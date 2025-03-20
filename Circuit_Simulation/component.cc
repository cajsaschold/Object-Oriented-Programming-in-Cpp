#include "component.h"

using namespace std;

Component :: Component(string name, Terminal* left_terminal, Terminal* right_terminal) : 
name{name}, left_terminal{left_terminal}, right_terminal{right_terminal}  {

}

double Component::get_voltage() const {
    double voltage{abs(*left_terminal - *right_terminal)};
    return voltage;
}

double Component::get_left_terminal() const {
    return *left_terminal;
}

double Component::get_right_terminal() const {
    return *right_terminal;
}

std::string Component::get_name() const {
    return name;
}
