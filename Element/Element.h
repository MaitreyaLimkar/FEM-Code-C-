//
// Created by srini on 22/10/2024.
//

#ifndef ELEMENT_H
#define ELEMENT_H
#include<vector>
#include<cmath>
#include "../eigen-3.4.0/Eigen/Dense"

class Element {
public:
    // Public member variables
    int Nr;                       // Element number
    std::vector<std::vector<double>> NdL;   // Node coordinates (2D std::vector of doubles)
    int NPE;                      // Number of nodes per element
    int deg;                      // Element degree
    std::vector<double> X;             // Coordinates of the element
    std::vector<double> x;             // Solution vector
    double lambda;                // Lame's first parameter
    double mu;                    // Lame's second parameter
    int NGP;                      // Number of Gauss points
    std::vector<std::vector<double>> GP;    // Gauss points (2D std::vector of doubles)
    int PD;                       // Problem dimension

private:
    // Private member variables
    std::vector<std::vector<double>> N;     // Shape functions (matrix)
    std::vector<std::vector<double>> GradN; // Derivatives of shape functions (matrix)
    std::vector<std::vector<double>> JJ;    // Jacobian (matrix)

public:
    // Constructor
    Element(int Nr, int PD, std::vector<std::vector<double>> NdL,
            std::vector<double> X, std::vector<double> x,
            int NGP, int element_order, double lambda, double mu)
        : Nr(Nr), NdL(NdL),NPE(NdL[0].size()),PD(PD), deg(element_order),
          X(X), x(x), lambda(lambda),
          mu(mu), NGP(NGP), GP(compute_gp(NGP, PD))
    {
    }

    // Methods
    std::vector<double> Residual(double dt) {
        return compute_R(x, NPE, N, GradN, JJ, GP, PD, lambda, mu);
    }

    std::pair<std::vector<double>, std::vector<std::vector<double>>> RK(double dt) {
        return compute_RK(x, NPE, N, GradN, JJ, GP, PD, lambda, mu);
    }

    std::pair<std::vector<double>, std::vector<std::vector<double>>> RK_gp(int NGP_val) {
        return compute_RK_gp(x, NPE, N, GradN, JJ, GP, PD, lambda, mu, NGP_val);
    }

private:
    // Function declarations (to be implemented)
    std::vector<std::vector<double>> compute_gp(int NGP, int PD);
    std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> compute_N_xi_gp(int deg, std::vector<std::vector<double>> GP, int PD);
    std::vector<std::vector<double>> compute_J(std::vector<double> X, int NGP, int PD, std::vector<std::vector<double>> GradN_xi);
    std::vector<std::vector<double>> compute_GradN_xi_gp(std::vector<std::vector<double>> JJ, int NGP, int PD, std::vector<std::vector<double>> GradN_xi);
    std::vector<double> compute_R(std::vector<double> x, int NPE, std::vector<std::vector<double>> N,
                                   std::vector<std::vector<double>> GradN, std::vector<std::vector<double>> JJ,
                                   std::vector<std::vector<double>> GP, int PD, double lambda, double mu);
    std::pair<std::vector<double>, std::vector<std::vector<double>>> compute_RK(std::vector<double> x, int NPE,
        std::vector<std::vector<double>> N, std::vector<std::vector<double>> GradN,
        std::vector<std::vector<double>> JJ, std::vector<std::vector<double>> GP, int PD, double lambda, double mu);
    std::pair<std::vector<double>, std::vector<std::vector<double>>> compute_RK_gp(std::vector<double> x, int NPE,
        std::vector<std::vector<double>> N, std::vector<std::vector<double>> GradN,
        std::vector<std::vector<double>> JJ, std::vector<std::vector<double>> GP, int PD, double lambda, double mu,
        int NGP_val);
};



#endif //ELEMENT_H
