#include <iostream>
#include "Preprocess/Mesh_1D.hpp"
//#include "eigen-3.4.0/Eigen/Dense"

int main() {
    // Problem input parameters (using const)
    constexpr int PD = 1;               // 1D problem
    constexpr double domain_size = 10.0; // size of the domain
    constexpr int partition = 10;       // number of partitions
    constexpr int element_order = 1;    // Linear elements

    // Create 1D mesh
    Mesh_1D mesh(PD, domain_size, partition, element_order);
    mesh.generate_mesh();

    // Retrieve nodes and elements
    //const Eigen::VectorXd nodes = mesh.getNodes();
    //const Eigen::MatrixXd elements = mesh.getElements();
    std::vector<double> nodes = mesh.getNodes();
    std::vector<std::vector<double>> elements = mesh.getElements();

    // Print Nodes and Elements (for testing purposes)
    //std::cout << "Nodes:\n" << nodes << std::endl;
    //std::cout << "Elements:\n" << elements << std::endl;
    std::cout << "Nodes:\n";
    for (const auto& node : nodes) {
        std::cout << node << " ";
    }
    std::cout << "\nElements:\n";
    for (const auto& element : elements) {
        for (const auto& el : element) {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }
}