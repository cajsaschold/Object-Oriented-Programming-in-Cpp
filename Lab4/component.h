#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

// All terminals are doubles
using Terminal = double;


// Main class for component
class Component
{
public:
    Component(std::string name, Terminal* left_terminal, Terminal* right_terminal);
    double get_voltage() const;
    virtual double get_current() const = 0;
    virtual void step(double const time_step) = 0;
    std::string get_name() const;
    double get_left_terminal() const;
    double get_right_terminal() const;

    virtual ~Component() = default;

protected:
    std::string name{};
    Terminal* left_terminal{};
    Terminal* right_terminal{};
    
};


// Class for battery
class Battery : public Component
{
public:
    Battery(std::string name, Terminal* left_terminal, Terminal* right_terminal, 
    double const battery_voltage);

    double get_current() const override;
    void step(double const time_step) override;

private: 
    double const battery_voltage{};

};


// Class for capacitor
class Capacitor : public Component
{
public:
    Capacitor(std::string name, Terminal* left_terminal, Terminal* right_terminal, double capacitance);
    double get_current() const override;
    double get_charge() const;
    void step(double const time_step) override;

private:
    double capacitance{};
    double charge{};
};


// Class for resistor
class Resistor : public Component
{
public:
    Resistor(std::string name, Terminal* left_terminal, Terminal* right_terminal, double resistance);
    double get_current() const override;
    void step(double const time_step) override;


private:
    double resistance{};

};
#endif
