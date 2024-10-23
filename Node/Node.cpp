#include "Node.hpp"

#include <algorithm>  // for std::fill

Node::Node(int Nr, int PD, const std::vector<double>& X, const std::vector<double>& x, const std::vector<int>& ElL)
        : PD(PD), Nr(Nr), X(X), x(x), ElL(ElL) {
    initializeVectors(PD);
}

void Node::initializeVectors(int PD) {
    // Initialize BC with ones
    BC.resize(PD, 1);

    // Initialize BCval and DOF with zeros
    BCval.resize(PD, 0.0);
    DOF.resize(PD, 0);

    // Initialize GP_BC, GP_DOF, GP_vals with respective sizes and values
    // This assumes a size of PD * PD + PD * PD as specified in the MATLAB code
    size_t size = PD * PD + PD * PD;
    GP_BC.resize(size, 1);
    GP_DOF.resize(size, 0);
    GP_vals.resize(size, 0.0);
}