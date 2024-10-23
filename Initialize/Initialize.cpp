#include "Initialize.hpp"
#include <algorithm>  // For std::max_element

constexpr double TOLERANCE = 1e-6;

void Initialize(int PD,
                const std::vector<std::vector<double>>& nl,
                const std::vector<std::vector<int>>& el,
                double domain_size,
                const std::vector<int>& element_order,
                double lambda,
                double mu,
                std::vector<Node>& NL,
                std::vector<Element>& EL) {

    int NoN = nl.size();              // Number of nodes
    int NoE = el.size();              // Number of elements

    int NGP = 0;
    int maxOrder = *std::max_element(element_order.begin(), element_order.end());

    switch (PD) {
        case 1:
            NGP = (maxOrder == 1) ? 2 : (maxOrder == 2) ? 3 : (maxOrder == 3) ? 4 : 5;
            break;
        case 2:
            NGP = (maxOrder == 1) ? 4 : (maxOrder == 2) ? 9 : (maxOrder == 3) ? 16 : 25;
            break;
        case 3:
            NGP = (maxOrder == 1) ? 8 : (maxOrder == 2) ? 27 : (maxOrder == 3) ? 64 : 125;
            break;
        default:
            throw std::invalid_argument("Invalid problem dimension PD.");
    }

    // Initialize Nodes
    for (int i = 0; i < NoN; ++i) {
        std::vector<int> ElL;

        for (int j = 0; j < NoE; ++j) {
            if (std::find(el[j].begin(), el[j].end(), i + 1) != el[j].end()) {
                ElL.push_back(j + 1);  // 1-based index as in MATLAB
            }
        }

        std::vector<double> X(nl[i].begin(), nl[i].end());
        std::vector<double> x = X;

        NL.emplace_back(Node(i + 1, PD, X, x, ElL));  // Adding nodes, converting MATLAB 1-based to C++ 0-based
    }

    // Initialize Elements
    int NPE = el[0].size();  // Nodes per element

    for (int i = 0; i < NoE; ++i) {
        std::vector<int> NdL = el[i];
        std::vector<std::vector<double>> X(PD, std::vector<double>(NPE));

        for (int j = 0; j < NPE; ++j) {
            for (int d = 0; d < PD; ++d) {
                X[d][j] = NL[NdL[j] - 1].X[d];  // 0-based index adjustment for nodes
            }
        }

        std::vector<std::vector<double>> x = X;

        EL.emplace_back(Element(i + 1, PD, NdL, X, x, NGP, element_order[i], lambda, mu));
    }
}
