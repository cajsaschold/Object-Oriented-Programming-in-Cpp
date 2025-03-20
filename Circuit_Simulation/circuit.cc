#include "circuit.h"
#include <iomanip>
#include <iostream>

using namespace std;


Circuit :: Circuit()  {
    vector<Component*> net{};
}

void Circuit::add_component(Component* comp) { 
    net.push_back(comp);
}

void Circuit::simulate(int const iterations, int const lines_to_print, 
double const time_step) const {
    
    for(int i{0}; i <= iterations; ++i) {

        for(Component* component : net) {
            component->step(time_step);
        }

        if(i % (iterations / lines_to_print) == 0) {
            print_circuit(i);
        }
        
    }
}

void Circuit::print_circuit(int iteration) const{

    // We only want to print the component names and "Volt" and "Curr" on the first iteration
    if(iteration==0) {

        // Print component names
        cout << endl;
        for (const Component* component : net) {
            cout << setw(15) << component->get_name() << "   ";
        }
        cout << endl;

        // Print "Volt" and "Curr"
        for (int i = 0; (unsigned)i < net.size(); i++) {
            cout << "  Volt     Curr   ";
        }
        cout << endl;
        return;

    } else {
        for (Component* component : net) {
        cout << fixed << setw(6) << setprecision(2) << component->get_voltage() << "   ";
        cout << fixed << setw(6) << setprecision(2) << component->get_current() << "   ";
    }
    }
    
    cout << endl;
}

Circuit::~Circuit() {
    for(Component* component : net) {
        delete component;
    };
}
