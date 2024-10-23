#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "../Node/Node.hpp"
#include "../Element/Element.cpp"
#include "../eigen-3.4.0/Eigen/Sparse"



// Function to assign boundary conditions (Placeholder)
std::pair<std::vector<Node>, std::vector<int>> Assign_BC(std::vector<Node>& NL, const std::vector<double>& domain_size,
                                                         const std::vector<std::vector<double>>& BC,
                                                         const std::vector<std::vector<double>>& F) {
    // Placeholder for the actual boundary condition assignment logic
    std::vector<int> DOFs; // This would be populated with DOF information
    // Modify nodes (NL) based on the boundary conditions (BC) and transformation F
    return {NL, DOFs};
}

// Function to compute the norm (Placeholder for vector norm)
double computeNorm(const std::vector<double>& vec) {
    double norm = 0.0;
    for (const auto& val : vec) {
        norm += val * val;
    }
    return std::sqrt(norm);
}

// Main Problem function
void Problem(int PD, std::vector<Node>& NL, std::vector<Element>& EL, const std::vector<double>& domain_size,
             const std::vector<std::vector<double>>& BC, const std::string& DEF, int element_order, double d,
             int steps, int max_iter, double tol, const std::vector<double>& GP_vals) {

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //                   output file name
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    std::string filename = std::to_string(PD) + "D_Normal_" + std::to_string(EL.size()) + "_EL=[" + std::to_string(element_order) + "].txt";

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //               assign boundary condition
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    std::vector<std::vector<double>> F(PD, std::vector<double>(PD, 0.0));
    for (int i = 0; i < PD; ++i) {
        F[i][i] = 1.0; // Identity matrix
    }

    if (DEF == "EXT") {
        F[0][0] = 1 + d;
    } else if (DEF == "EXP") {
        for (int i = 0; i < PD; ++i) {
            F[i][i] = 1 + d;
        }
    } else if (DEF == "SHR") {
        F[0][1] = d;
    }

    // Assign Boundary Conditions
    std::vector<int> DOFs;
    std::tie(NL, DOFs) = Assign_BC(NL, domain_size, BC, F);

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //               assign Gauss Point DOFs
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // Initialize Gauss point-related DOFs for each element

    // Time-stepping variables
    double dt = d / static_cast<double>(steps);

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //               begin time stepping
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    for (int step = 1; step <= steps; ++step) {
        std::cout << "Step: " << step << "/" << steps << std::endl;

        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        //                   begin iterations
        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        int iter = 0;
        double error = tol + 1.0;  // Initial error above tolerance

        std::vector<double> Residual(NL.size() * PD, 0.0);  // Placeholder for Residual vector
        std::vector<std::vector<double>> Stiffness(NL.size() * PD, std::vector<double>(NL.size() * PD, 0.0));  // Placeholder for Stiffness matrix

        while (error > tol && iter < max_iter) {
            ++iter;

            //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            //                   compute residual & stiffness
            //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            for (auto& element : EL) {
                // Element-wise residual and stiffness computation
                auto [R_e, K_e] = element.RK(dt);

                // Accumulate element contributions to global Residual and Stiffness
                // (This part needs to handle element-to-global mapping, not shown here)
            }

            //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            //                   solve system
            //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            // Placeholder: Solve linear system K * delta_x = R to get update delta_x
            std::vector<double> delta_x(NL.size() * PD, 0.0);  // Solution update placeholder

            // Update node positions using delta_x
            for (int i = 0; i < NL.size(); ++i) {
                for (int j = 0; j < PD; ++j) {
                    NL[i].x[j] += delta_x[i * PD + j];  // Update spatial configuration
                }
            }

            // Compute error as the norm of the residual
            error = computeNorm(Residual);

            std::cout << "Iteration " << iter << ", Error: " << error << std::endl;

            if (error <= tol) {
                std::cout << "Converged in " << iter << " iterations.\n";
                break;
            }
        }

        // Check if max iterations were reached without convergence
        if (iter == max_iter) {
            std::cout << "Max iterations reached without convergence.\n";
        }

        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        //                   end of time step
        //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    }

    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //                   write output
    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        outfile << "Simulation Results:\n";
        for (const auto& node : NL) {
            for (const auto& coord : node.x) {
                outfile << coord << " ";
            }
            outfile << "\n";
        }
        outfile.close();
    } else {
        std::cerr << "Unable to open output file.\n";
    }
}


std::pair<std::vector<Node>, std::vector<int>> Assign_DOF_DBC(std::vector<Node>& NL);

std::pair<std::vector<Node>, std::vector<int>> Assign_BC(std::vector<Node>& NL, const std::vector<double>& domain_size,
                                                         const std::vector<std::vector<double>>& F) {
    int NoNs = NL.size();
    int PD = NL[0].PD;  // Assuming all nodes have the same problem dimension
    double tol = 1e-6;

    double W = domain_size[0];  // X-direction ... width
    double H = (PD >= 2) ? domain_size[1] : 0;  // Y-direction ... height
    double D = (PD == 3) ? domain_size[2] : 0;  // Z-direction ... depth

    for (int i = 0; i < NoNs; ++i) {
        std::vector<double> X = NL[i].X;

        // Depending on the problem dimension, check the spatial coordinates
        if (PD == 1) {
            if (std::abs(X[0] - 0) < tol || std::abs(X[0] - W) < tol) {
                std::vector<int> BC(PD, 0);  // Zero boundary conditions (free)
                std::vector<double> BCval(PD);

                // Compute BCval as F * X - X
                for (int j = 0; j < PD; ++j) {
                    BCval[j] = 0.0;
                    for (int k = 0; k < PD; ++k) {
                        BCval[j] += F[j][k] * X[k];
                    }
                    BCval[j] -= X[j];
                }

                NL[i].BC = BC;
                NL[i].BCval = BCval;
            }
        } else if (PD == 2) {
            if (std::abs(X[0] - 0) < tol || std::abs(X[0] - W) < tol ||
                std::abs(X[1] - 0) < tol || std::abs(X[1] - H) < tol) {
                std::vector<int> BC(PD, 0);  // Zero boundary conditions (free)
                std::vector<double> BCval(PD);

                // Compute BCval as F * X - X
                for (int j = 0; j < PD; ++j) {
                    BCval[j] = 0.0;
                    for (int k = 0; k < PD; ++k) {
                        BCval[j] += F[j][k] * X[k];
                    }
                    BCval[j] -= X[j];
                }

                NL[i].BC = BC;
                NL[i].BCval = BCval;
            }
        } else if (PD == 3) {
            if (std::abs(X[0] - 0) < tol || std::abs(X[0] - W) < tol ||
                std::abs(X[1] - 0) < tol || std::abs(X[1] - H) < tol ||
                std::abs(X[2] - 0) < tol || std::abs(X[2] - D) < tol) {
                std::vector<int> BC(PD, 0);  // Zero boundary conditions (free)
                std::vector<double> BCval(PD);

                // Compute BCval as F * X - X
                for (int j = 0; j < PD; ++j) {
                    BCval[j] = 0.0;
                    for (int k = 0; k < PD; ++k) {
                        BCval[j] += F[j][k] * X[k];
                    }
                    BCval[j] -= X[j];
                }

                NL[i].BC = BC;
                NL[i].BCval = BCval;
            }
        }
    }

    // Now call the Assign_DOF_DBC function to assign DOFs and Dirichlet BCs
    return Assign_DOF_DBC(NL);
}

std::pair<std::vector<Node>, std::vector<int>> Assign_DOF_DBC(std::vector<Node>& NL) {
    int NoNs = NL.size();
    int DOFs = 0;  // Counter for degrees of freedom
    std::vector<int> globalDOFs;  // Store all DOFs

    for (int i = 0; i < NoNs; ++i) {
        std::vector<int>& BC = NL[i].BC;
        std::vector<int>& DOF = NL[i].DOF;

        for (size_t p = 0; p < BC.size(); ++p) {
            if (BC[p] == 1) {  // Active boundary condition
                DOFs++;
                DOF[p] = DOFs;
                globalDOFs.push_back(DOF[p]);
            }
        }

        // Assign the updated DOF list to the node
        NL[i].DOF = DOF;
    }

    // Return the updated node list and the global DOFs
    return {NL, globalDOFs};
}

// Function to compute the total residual
std::vector<double> Residual(int PD, const std::vector<Node>& NL, const std::vector<Element>& EL, int DOFs, double dt) {
    int NoEs = EL.size();  // Number of elements
    int NoNs = NL.size();  // Number of nodes
    int NPE = EL[0].NPE;   // Number of nodes per element

    // Initialize the total residual vector to zero
    std::vector<double> Rtot(DOFs, 0.0);
    int sprC = 0;  // Sparse counter (not used in this implementation)

    // Loop over elements
    for (int e = 0; e < NoEs; ++e) {
        // Get the residual vector for the current element
        std::vector<double> R = EL[e].Residual(dt);

        // Get the node list of the current element
        std::vector<std::vector<double>> NdL = EL[e].NdL;

        // Problem dimension, defining the range for each node's DOF
        int dim = PD;
        int first = 1;
        int last = dim;

        // Loop over nodes per element (NPE)
        for (int i = 0; i < NPE; ++i) {
            // Get the boundary conditions (BC) and degrees of freedom (DOF) of the node
            std::vector<int> BC = NL[NdL[i][0]].BC;  // Assumes NdL is 2D with node indices
            std::vector<int> DOF = NL[NdL[i][0]].DOF;

            // Loop over dimensions (from 'first' to 'last')
            for (int p = first; p <= last; ++p) {
                // If BC is active (BC[p-1] == 1), update the total residual
                if (BC[p - 1] == 1) {
                    // Update the total residual with the element's contribution
                    Rtot[DOF[p - 1]] += R[(i * dim) + (p - first)];
                }
            }
        }
    }

    return Rtot;
}


// Function to assemble the global residual and stiffness matrix
std::pair<std::vector<double>, Eigen::SparseMatrix<double>> Assemble(int PD, const std::vector<Node>& NL, const std::vector<Element>& EL, int DOFs) {
    int NoEs = EL.size();  // Number of elements
    int NoNs = NL.size();  // Number of nodes
    int NPE = EL[0].NPE;   // Number of nodes per element

    // Initialize the total residual vector to zero
    std::vector<double> Rtot(DOFs, 0.0);

    // Vectors to store the triplets for the sparse matrix assembly
    std::vector<Eigen::Triplet<double>> tripletList;

    // Sparse counter (for internal counting)
    int sprC = 0;

    // Loop over elements
    for (int e = 0; e < NoEs; ++e) {
        // Get the residual and stiffness matrix for the current element
        auto [R, K] = EL[e].RK(0.0); // Assuming dt = 0.0 for now, adjust as needed

        // Get the node list of the current element
        std::vector<std::vector<double>> NdL = EL[e].NdL;

        // Problem dimension, defining the range for each node's DOF
        int dim = PD;
        int first = 1;
        int last = dim;

        // Loop over nodes per element (NPE)
        for (int i = 0; i < NPE; ++i) {
            // Get the boundary conditions (BC) and degrees of freedom (DOF) of the node
            std::vector<int> BC = NL[NdL[i][0]].BC;
            std::vector<int> DOF = NL[NdL[i][0]].DOF;

            // Loop over dimensions (from 'first' to 'last')
            for (int p = first; p <= last; ++p) {
                if (BC[p - 1] == 1) {
                    // Update the total residual with the element's contribution
                    Rtot[DOF[p - 1]] += R[(i * dim) + (p - first)];
                }
            }
        }

        // Second part: assembling the stiffness matrix (Ktot)
        int dim_i = PD;
        int first_i = 1;
        int last_i = dim_i;

        // Loop over nodes per element (NPE) for matrix assembly
        for (int i = 0; i < NPE; ++i) {
            std::vector<int> BC_i = NL[NdL[i][0]].BC;
            std::vector<int> DOF_i = NL[NdL[i][0]].DOF;

            for (int p = first_i; p <= last_i; ++p) {
                if (BC_i[p - 1] == 1) {
                    // Assemble K11, K12, etc.
                    int dim_j = PD;
                    int first_j = 1;
                    int last_j = dim_j;

                    for (int j = 0; j < NPE; ++j) {
                        std::vector<int> BC_j = NL[NdL[j][0]].BC;
                        std::vector<int> DOF_j = NL[NdL[j][0]].DOF;

                        for (int q = first_j; q <= last_j; ++q) {
                            if (BC_j[q - 1] == 1) {
                                // Add the triplet to the triplet list (for sparse matrix)
                                tripletList.emplace_back(DOF_i[p - 1], DOF_j[q - 1],
                                                         K[(i * dim_i) + (p - first_i)][(j * dim_j) + (q - first_j)]);
                            }
                        }
                    }
                }
            }
        }
    }

    // Create the sparse matrix Ktot using the triplets
    Eigen::SparseMatrix<double> Ktot(DOFs, DOFs);
    Ktot.setFromTriplets(tripletList.begin(), tripletList.end());

    return {Rtot, Ktot};
}


typedef Eigen::SparseMatrix<double> SpMat;
typedef Eigen::Triplet<double> Triplet;

std::pair<Eigen::MatrixXd, SpMat> Assemble_GP(
        int PD,
        std::vector<Node>& NL,
        std::vector<Element>& EL,
        int GP_DOFs)
{
    int NoEs = EL.size();
    int NoNs = NL.size();
    int NPE = EL[0].NPE;
    int NGP_val = NL[0].GP_BC.size();  // number of gauss point values

    // Initialize Rtot_GP and prepare for sparse matrix
    Eigen::MatrixXd Rtot_GP = Eigen::MatrixXd::Zero(GP_DOFs, NGP_val);
    std::vector<Triplet<double>> tripletList;

    for (int e = 0; e < NoEs; ++e) {
        // Retrieve the residual and stiffness matrix at Gauss Points
        auto [R, K] = EL[e].RK_gp(NGP_val);

        // Get the node list for the element
        std::vector<int> NdL = EL[e].NdL;

        // Process for the Residual
        for (int s = 0; s < NGP_val; ++s) {
            for (int i = 0; i < NPE; ++i) {
                int dim = 1; // as in the original code
                int first = 0;
                int last = dim;

                std::vector<int> BC = NL[NdL[i]].GP_BC;
                std::vector<int> DOF = NL[NdL[i]].GP_DOF;

                for (int p = first; p < last; ++p) {
                    if (BC[p] == 1) {
                        Rtot_GP(DOF[p], s) += R((i * dim + p - first), s);
                    }
                }
            }
        }

        // Process for the Stiffness Matrix
        for (int i = 0; i < NPE; ++i) {
            int dim_i = 1;
            int first_i = 0;
            int last_i = dim_i;

            std::vector<int> BC_i = NL[NdL[i]].GP_BC;
            std::vector<int> DOF_i = NL[NdL[i]].GP_DOF;

            for (int p = first_i; p < last_i; ++p) {
                if (BC_i[p] == 1) {
                    for (int j = 0; j < NPE; ++j) {
                        int dim_j = 1;
                        int first_j = 0;
                        int last_j = dim_j;

                        std::vector<int> BC_j = NL[NdL[j]].GP_BC;
                        std::vector<int> DOF_j = NL[NdL[j]].GP_DOF;

                        for (int q = first_j; q < last_j; ++q) {
                            if (BC_j[q] == 1) {
                                // Store the triplet (row, col, value) for Ktot_GP
                                tripletList.emplace_back(DOF_i[p], DOF_j[q], K((i * dim_i + p - first_i), (j * dim_j + q - first_j)));
                            }
                        }
                    }
                }
            }
        }
    }

    // Convert the triplet list into a sparse matrix
    SpMat Ktot_GP(GP_DOFs, GP_DOFs);
    Ktot_GP.setFromTriplets(tripletList.begin(), tripletList.end());

    return std::make_pair(Rtot_GP, Ktot_GP);
}