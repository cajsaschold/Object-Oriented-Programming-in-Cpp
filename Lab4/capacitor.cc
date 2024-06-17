#include "component.h"

using namespace std;

Capacitor :: Capacitor(string name, Terminal* left_terminal, Terminal* right_terminal, 
double capacitance) : Component{name, left_terminal, right_terminal}, capacitance{capacitance} {
}


double Capacitor::get_current() const {
    double voltage{get_voltage()};
    double current{capacitance * (voltage - charge)};

    return current;
}

double Capacitor::get_charge() const {
    return charge;
}

void Capacitor::step(double const time_step) {
    double difference{get_voltage()};
    double store{capacitance * (difference - charge) * time_step};

    if(*left_terminal > *right_terminal) {
        *left_terminal -= store;
        *right_terminal += store;
    } else {
        *left_terminal += store;
        *right_terminal -= store;
    }
    charge += store;
}

