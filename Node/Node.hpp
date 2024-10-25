#ifndef NODE_H
#define NODE_H

#include <vector>  // for std::vector

class Node {
public:
    // Constructors
    Node(int Nr, int PD, const std::vector<double>& X, const std::vector<double>& x, const std::vector<int>& ElL);

    // Member variables
    int PD;                     // Problem Dimension
    int Nr;                     // Node number
    std::vector<double> X;      // Node position in material configuration
    std::vector<double> x;      // Node position in spatial configuration
    std::vector<int> ElL;       // Element list
    std::vector<int> BC;        // Boundary condition corresponding to node unknowns
    std::vector<double> BCval;  // Boundary condition value corresponding to node unknowns
    std::vector<int> DOF;       // Degrees of freedom corresponding to the unknwons
    std::vector<int> GP_BC;     // Boundary condition associated with the values computed on Gauss Points
    std::vector<int> GP_DOF;    // Degrees of freedom corresponding to the values computed on Gauss points
    std::vector<double> GP_vals;// Gauss point values written from the gauss points

private:
    void initializeVectors(int PD);
};

#endif // NODE_H