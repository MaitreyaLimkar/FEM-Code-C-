#ifndef ELEMENT_H
#define ELEMENT_H
#include<vector>
#include<cmath>
#include "../eigen-3.4.0/Eigen/Dense"




class Element {
public:
    // Public properties (equivalent to public member variables)
    double Nr;                          // float
    std::vector<std::vector<double>> NdL; // matrix
    int NPE;                            // number of nodes per element
    int deg;                            // element degree
    std::vector<double> X;              // coordinates
    std::vector<double> x;              // deformed coordinates
    double lambda;                      // material property
    double mu;                          // material property
    int NGP;                            // number of Gauss points
    std::vector<std::vector<double>> GP; // Gauss points
    int PD;                             // problem dimension (float/int)

private:
    // Private properties (equivalent to private member variables)
    std::vector<std::vector<double>> N;        // shape functions for the cell
    std::vector<std::vector<double>> GradN;    // derivatives of shape functions
    std::vector<std::vector<double>> JJ;       // Jacobian

public:
    // Constructor
    Element(double Nr, int PD, const std::vector<std::vector<double>>& NdL,
            const std::vector<double>& X, const std::vector<double>& x, int NGP,
            const std::vector<int>& element_order, double lambda, double mu)
        : Nr(Nr), PD(PD), NdL(NdL), X(X), x(X), lambda(lambda), mu(mu), NGP(NGP)
    {
        NPE = NdL[0].size();
        deg = element_order[0];
        GP = compute_GP(NGP, PD);
        std::vector<std::vector<double>> GradN_xi;
        std::tie(N, GradN_xi) = compute_N(deg, GP, PD);
        JJ = compute_J(X, NGP, PD, GradN_xi);
        GradN = compute_GradN(JJ, NGP, PD, GradN_xi);
    }

    // Method to compute residual
    std::vector<double> Residual(double dt) {
        return compute_R(x, NPE, N, GradN, JJ, GP, PD, lambda, mu);
    }

    // Method to compute residual and stiffness matrix
    std::pair<std::vector<double>, std::vector<std::vector<double>>> RK(double dt) {
        return compute_RK(x, NPE, N, GradN, JJ, GP, PD, lambda, mu);
    }

    // Method to compute residual and stiffness matrix for a given Gauss point value
    std::pair<std::vector<double>, std::vector<std::vector<double>>> RK_GP(int NGP_val) {
        return compute_RK_GP(x, NPE, N, GradN, JJ, GP, PD, lambda, mu, NGP_val);
    }

    static std::vector<std::vector<double>> compute_gp(int NGP, int PD);

private:
    // These are placeholder function signatures. You need to implement these functions.
    static std::vector<std::vector<double>> compute_GP(int NGP, int PD) {
        // Compute Gauss points (this would need actual logic)
        return std::vector<std::vector<double>>();
    }

    std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> compute_N(int deg, const std::vector<std::vector<double>>& GP, int PD) {
        // Compute shape functions and their derivatives
        return { std::vector<std::vector<double>>(), std::vector<std::vector<double>>() };
    }

    std::vector<std::vector<double>> compute_J(const std::vector<double>& X, int NGP, int PD, const std::vector<std::vector<double>>& GradN_xi) {
        // Compute Jacobian
        return std::vector<std::vector<double>>();
    }

    std::vector<std::vector<double>> compute_GradN(const std::vector<std::vector<double>>& JJ, int NGP, int PD, const std::vector<std::vector<double>>& GradN_xi) {
        // Compute gradients of shape functions
        return std::vector<std::vector<double>>();
    }

    std::vector<double> compute_R(const std::vector<double>& x, int NPE, const std::vector<std::vector<double>>& N, const std::vector<std::vector<double>>& GradN, const std::vector<std::vector<double>>& JJ, const std::vector<std::vector<double>>& GP, int PD, double lambda, double mu) {
        // Compute residual
        return std::vector<double>();
    }

    std::pair<std::vector<double>, std::vector<std::vector<double>>> compute_RK(const std::vector<double>& x, int NPE, const std::vector<std::vector<double>>& N, const std::vector<std::vector<double>>& GradN, const std::vector<std::vector<double>>& JJ, const std::vector<std::vector<double>>& GP, int PD, double lambda, double mu) {
        // Compute residual and stiffness matrix
        return { std::vector<double>(), std::vector<std::vector<double>>() };
    }

    std::pair<std::vector<double>, std::vector<std::vector<double>>> compute_RK_GP(const std::vector<double>& x, int NPE, const std::vector<std::vector<double>>& N, const std::vector<std::vector<double>>& GradN, const std::vector<std::vector<double>>& JJ, const std::vector<std::vector<double>>& GP, int PD, double lambda, double mu, int NGP_val) {
        // Compute residual and stiffness matrix for a specific Gauss point value
        return { std::vector<double>(), std::vector<std::vector<double>>() };
    }
};

#endif //ELEMENT_H