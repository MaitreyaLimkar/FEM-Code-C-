//
// Created by trueno on 10/13/24.
//

#include "Mesh_1D.hpp"
#include <algorithm>
#include <iostream>
#include <Eigen/Dense>

// Constructor definition
Mesh_1D::Mesh_1D(const int PD, const double domain_size, const int partition, const int element_order)
    : PD(PD), partition(partition), element_order(element_order), domain_size(domain_size){}

void Mesh_1D::generate_mesh(int nargout) {
    // TODO
}

void Mesh_1D::individual(double domain_size, int partition, int degree, int PD,
    std::vector<double> &NL, std::vector<std::vector<double> > &EL)
{
    const int p = partition;

    const int number_of_nodes =(degree*p + 1); // NoN
    const int number_of_elements = p;          // NoE
    const int nodes_per_element = degree + 1;

    
}
