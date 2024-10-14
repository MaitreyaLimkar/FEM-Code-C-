//
// Created by trueno on 10/13/24.
//

#ifndef MESH_1D_HPP
#define MESH_1D_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Mesh_1D class declaration
class Mesh_1D {
private:
    // Initializing the variables
    int PD = 0, partition = 0, element_order = 0;
    double domain_size = 0.0;
    std::vector<double> NL, EL_1, EL_2, EL_3;

public:
    // Constructor for Mesh_1D
    Mesh_1D(int PD, double domain_size, int partition, int element_order);

    // Generation of mesh
    static void generate_mesh(int nargout);

    // Function declaration for helper function that generates node list and element list
    static void individual (double domain_size, int partition, int degree, int PD,
                            std::vector<double> &NL, std::vector<std::vector<double>> &EL);

    // Getter functions to retrieve mesh data
    [[nodiscard]] std::vector<double> getNodeList() const;
    [[nodiscard]] std::vector<double> getElementList1() const;
    [[nodiscard]] std::vector<double> getElementList2() const;
    [[nodiscard]] std::vector<double> getElementList3() const;
};

#endif //MESH_1D_HPP