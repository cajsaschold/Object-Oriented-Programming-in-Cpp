#include "component.h"

using namespace std;

Resistor :: Resistor(string name, Terminal* left_terminal, Terminal* right_terminal, 
double resistance) : Component{name, left_terminal, right_terminal}, resistance{resistance} {

}


double Resistor::get_current() const {
    double voltage{get_voltage()};
    double current{voltage/resistance};

    return current;
}

void Resistor::step(double const time_step) {
    double charge{(get_voltage()/resistance) * time_step};

    if(*left_terminal > *right_terminal) {
        *left_terminal -= charge;
        *right_terminal += charge;
    } else {
        *left_terminal += charge;
        *right_terminal -= charge;
    }
}
