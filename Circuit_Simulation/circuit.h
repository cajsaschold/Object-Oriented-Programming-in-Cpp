#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include "component.h"


class Circuit {
    public:
        Circuit();
        void simulate(int const iterations, 
            int const lines_to_print, double const time_step) const;
        void print_circuit(int iteration) const;
        void add_component(Component* comp);
        ~Circuit();
    protected:
        std::vector<Component*> net{};
};
#endif
