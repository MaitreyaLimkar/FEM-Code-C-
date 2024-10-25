#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <vector>
#include "../Node/Node.hpp"
#include "../Element/Element.cpp"

// Function declaration
void Initialize(int PD,
                const std::vector<std::vector<double>>& nl,
                const std::vector<std::vector<int>>& el,
                double domain_size,
                const std::vector<int>& element_order,
                double lambda,
                double mu,
                std::vector<Node>& NL,
                std::vector<Element>& EL);

#endif // INITIALIZE_H
