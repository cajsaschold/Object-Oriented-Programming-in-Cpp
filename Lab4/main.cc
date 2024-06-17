//to run: 
//g++ component.cc battery.cc capacitor.cc resistor.cc main.cc circuit.cc -o Lab4
//./Lab4 200000 10 0.01 24
// almost... Use:
// g++ -Wall -Wextra -Wpedantic component.cc battery.cc capacitor.cc resistor.cc main.cc circuit.cc -o Lab4

// valgrind: valgrind --tool=memcheck --leak-check=yes ./Lab4 200000 10 0.01 24

#include "component.h"
#include "circuit.h"
#include <iostream>

using namespace std;


// Small note: The battery voltage for C1 is 23.96 in the simulation. After discussion with  
// three of the lab assistants, they concluded that the small difference was okay.
void C1(int const iterations, int const lines_to_print, double const time_step, 
double const battery_voltage) {

    Terminal p{}, n{}, R124{}, R23{};
    Circuit circuit_1{};

    circuit_1.add_component(new Battery("Bat", &p, &n, battery_voltage));
    circuit_1.add_component(new Resistor("R1", &p, &R124, 6));
    circuit_1.add_component(new Resistor("R2", &R124, &R23, 4));
    circuit_1.add_component(new Resistor("R3", &R23, &n, 8));
    circuit_1.add_component(new Resistor("R4", &R124, &n, 12));

    circuit_1.simulate(iterations, lines_to_print, time_step);
}

void C2(int const iterations, int const lines_to_print, double const time_step, 
double const battery_voltage) {

    Terminal p{}, n{}, L{}, R{};
    Circuit circuit_2{};

    circuit_2.add_component(new Battery("Bat", &p, &n, battery_voltage));
    circuit_2.add_component(new Resistor("R1", &p, &L, 150));
    circuit_2.add_component(new Resistor("R2", &p, &R, 50));
    circuit_2.add_component(new Resistor("R3", &L, &R, 100));
    circuit_2.add_component(new Resistor("R4", &L, &n, 300));
    circuit_2.add_component(new Resistor("R5", &R, &n, 250));

    circuit_2.simulate(iterations, lines_to_print, time_step);
}

void C3(int const iterations, int const lines_to_print, double const time_step, 
double const battery_voltage) {

    Terminal p{}, n{}, L{}, R{};
    Circuit circuit_3{};

    circuit_3.add_component(new Battery("Bat", &p, &n, battery_voltage));
    circuit_3.add_component(new Resistor("R1", &p, &L, 150));
    circuit_3.add_component(new Resistor("R2", &p, &R, 50));
    circuit_3.add_component(new Capacitor("C3", &L, &R, 1.0));
    circuit_3.add_component(new Resistor("R4", &L, &n, 300));
    circuit_3.add_component(new Capacitor("C5", &R, &n, 0.75));
    
    circuit_3.simulate(iterations, lines_to_print, time_step);
}

int main(int argc, char** argv) {

    int iterations{};
    int lines_to_print{};
    double time_step{};
    double battery_voltage{};

    if(argc == 5) {

        try {
            iterations = stoi(argv[1]);

            if(iterations < 0) {
                cerr << "Iterations (input 1) should not be negative" << endl;
                return -1;
            }
        }
        catch(invalid_argument& e) {
            cerr << "Iterations (input 1) should be an integer" << endl;
            return -1;
        }
        catch(out_of_range& e) {
            cerr << "The integer you have entered for iterations (input 1) is out of range" << endl;
            return -1;
        }

        try {
            lines_to_print = stoi(argv[2]); 

            if(lines_to_print < 0) {
                cerr << "Lines to print (input 2) should not be negative" << endl;
                return -1;
            }
        }
        catch(invalid_argument& e) {
            cerr << "The number of lines to print (input 2) should be an integer" << endl;
            return -1;
        }
        catch(out_of_range& e) {
            cerr << "The integer you have entered for lines to print (input 2) "
            << "is out of range" << endl;
            return -1;
        }

        try {
            time_step = stod(argv[3]);

            if(time_step < 0) {
                cerr << "Time step (input 3) should not be negative" << endl;
                return -1;
            }
        }
        catch(invalid_argument& e) {
            cerr << "Time step (input 3) should be a double" << endl;
            return -1;
        }
        catch(out_of_range& e) {
            cerr << "The double you have entered for time step (input 3) is out of range" << endl;
            return -1;
        }

        try {
            battery_voltage = stod(argv[4]);

            if(battery_voltage < 0) {
                cerr << "Battery voltage (input 4) should not be negative" << endl;
                return -1;
            }
        }
        catch(invalid_argument& e) {
            cerr << "Battery voltage (input 4) should be a double" << endl;
            return -1;
        }
        catch(out_of_range& e) {
            cerr << "The double you have entered for battery voltage (input 4) "
            << "is out of range" << endl;
            return -1;
        }

    } else {
        cerr << "You shuld have 4 inputs. Iterations (integer), lines to print (integer)" 
            << " time step (double) and battery voltage (double)" << endl;
        return -1;
    }

    C1(iterations, lines_to_print, time_step, battery_voltage);
    C2(iterations, lines_to_print, time_step, battery_voltage);
    C3(iterations, lines_to_print, time_step, battery_voltage);

    return 0;
}
