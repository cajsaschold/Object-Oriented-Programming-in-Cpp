#include "component.h"

using namespace std;

Battery :: Battery(string name, Terminal* left_terminal, Terminal* right_terminal, 
double battery_voltage) : Component{name, left_terminal, right_terminal}, 
battery_voltage{battery_voltage} {
}

double Battery::get_current() const {
    return 0;
}

void Battery::step(double const) {
    *left_terminal = battery_voltage;
    *right_terminal = 0.0;
}