//
// Created by srini on 22/10/2024.
//

#include "Element.h"


using vectors = std::vector<std::vector<double> >;

vectors Element::compute_gp(int NGP, int PD) {
    vectors GP;

    switch (PD) {
            case 1:
              if (NGP == 1.0) {
                std::vector<double> xi = {0.0};
                std::vector<double> w = {2.0};
                GP.push_back(xi);
                GP.push_back(w);
              }
              else if (NGP == 2) {
                std::vector<double> xi = {-sqrt(1.0 / 3.0), sqrt(1.0 / 3.0)};
                std::vector<double> w = {1.0,1.0};
                GP.push_back(xi);
                GP.push_back(w);
              }
              else if (NGP == 3) {
                std::vector<double> xi = {-sqrt(0.6), sqrt(0.6)};
                std::vector<double> w = { 5.0/9.0 , 8.0/9.0 , 5.0/9.0};
                GP.push_back(xi);
                GP.push_back(w);
              }
              else if (NGP == 4) {
                std::vector<double> xi = {-0.861136311594953 , -0.339981043584856 , 0.339981043584856 , 0.861136311594953};
                std::vector<double> w = { 0.347854845137454 , 0.652145154862546 , 0.652145154862546 , 0.347854845137454 };
                GP.push_back(xi);
                GP.push_back(w);
              }
              else if (NGP == 5) {
                std::vector<double> xi ={ -0.9061798459386640 , -0.5384693101056831 , 0 , 0.5384693101056831 , 0.9061798459386640 };
                std::vector<double> w = { 0.2369268850561891 , 0.4786286704993665 , 0.5688888888888889 , 0.4786286704993665 , 0.2369268850561891 };
                GP.push_back(xi);
                GP.push_back(w);
              }
              break;

            case 2:
              if (NGP == 4) {
                double a = sqrt(1.0/3.0);
                double w1 = 1.0;
                std::vector<double> xi  = { -a, a, a, -a};
                std::vector<double> eta = { -a, -a, a, a};
                std::vector<double> w   = { w1 * w1, w1 * w1, w1 * w1, w1 * w1 };
                GP.push_back(xi);
                GP.push_back(eta);
                GP.push_back(w);
              }
              else if (NGP == 9) {
                double a = sqrt(0.6);
                double  w1 = 5.0/9.0;
                double  w2 = 8.0/9.0;
                std::vector<double> xi  = { a, 0, a, -a, 0, a, -a, 0, a};
                std::vector<double> eta = { -a, -a, -a, 0, 0, 0, a, a, a};
                std::vector<double> w   = { w1 * w1, w2 * w1, w1 * w1, w2 * w1, w2 * w2, w2 * w1, w1 * w1, w2 * w1, w1 * w1 };
                GP.push_back(xi);
                GP.push_back(eta);
                GP.push_back(w);
              }
              else if (NGP == 16) {
                double a  = 0.861136311594953;
                double b  = 0.339981043584856;
                double w1 = 0.347854845137454;
                double w2 = 0.652145154862546;
                std::vector<double> xi  = { -a ,-b , b , a , -a ,-b , b , a , -a ,-b , b , a , -a ,-b , b , a};
                std::vector<double> eta = { -a ,-a ,-a ,-a, -b ,-b ,-b ,-b ,b , b , b , b ,a , a , a , a};
                std::vector<double> w   = { w1 * w1 , w2 * w1 , w2 * w1 , w1 * w1 ,w1 * w2 , w2 * w2 , w2 * w2 , w1 * w2 ,w1 * w2 , w2 * w2 , w2 * w2 , w1 * w2 ,w1 * w1 , w2 * w1 , w2 * w1 , w1 * w1};
                GP.push_back(xi);
                GP.push_back(eta);
                GP.push_back(w);
              }
              else if (NGP == 25) {
                double a  = 0.9061798459;
                double b  = 0.538469310105683;
                double w1 = 0.236926885056189;
                double w2 = 0.478628670499366;
                double w3 = 0.568888888888889;
                std::vector<double> xi  = {-a , -b , 0 , b , a ,-a , -b , 0 , b , a ,-a , -b , 0 , b , a ,-a , -b , 0 , b , a ,-a , -b , 0 , b , a};
                std::vector<double> eta = {-a ,-a ,-a ,-a ,-a ,-b ,-b ,-b ,-b ,-b ,0 , 0 , 0 , 0 , 0 ,b , b , b , b , b ,a , a , a , a , a };
                std::vector<double> w   = {w1 * w1 , w2 * w1 , w3 * w1 , w2 * w1 , w1 * w1 ,w1 * w2 , w2 * w2 , w3 * w2 , w2 * w2 , w1 * w2 ,w1 * w3 , w2 * w3 , w3 * w3 , w2 * w3 , w1 * w3 ,w1 * w2 , w2 * w2 , w3 * w2 , w2 * w2 , w1 * w2 ,w1 * w1 , w2 * w1 , w3 * w1 , w2 * w1 , w1 * w1};
                GP.push_back(xi);
                GP.push_back(eta);
                GP.push_back(w);
              }
              break;

            case 3:
              if (NGP == 8) {
                double a = sqrt(1.0/3.0);
                double w1 = 1.0;
                std::vector<double> xi   = { -a , a , a ,-a ,-a , a , a ,-a};
                std::vector<double> eta  = { -a ,-a , a , a ,-a ,-a , a , a };
                std::vector<double> zeta = { -a ,-a ,-a ,-a ,a , a , a , a };
                std::vector<double> w    = {w1 * w1 * w1 , w1 * w1 * w1 ,w1 * w1 * w1 , w1 * w1 * w1 ,w1 * w1 * w1 , w1 * w1 * w1 ,w1 * w1 * w1 , w1 * w1 * w1};
                GP.push_back(xi);
                GP.push_back(eta);
                GP.push_back(zeta);
                GP.push_back(w);
              }
              else if (NGP == 27) {
                double a = sqrt(0.6);
                double w1 = 5.0/9.0;
                double w2 = 8.0/9.0;
                std::vector<double> xi  = { -a , 0 , a ,-a , 0 , a ,-a , 0 , a , -a , 0 , a ,-a , 0 , a ,-a , 0 , a , -a , 0 , a ,-a , 0 , a ,-a , 0 , a };
                std::vector<double> eta = {-a ,-a ,-a , 0 , 0 , 0 , a , a , a ,-a ,-a ,-a , 0 , 0 , 0 , a , a , a ,-a ,-a ,-a , 0 , 0 , 0 , a , a , a};
                std::vector<double>zeta = {-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,a , a , a , a , a , a , a , a , a};
                std::vector<double> w   = { w1 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 ,w1 * w2 * w1 , w2 * w2 * w1 , w1 * w2 * w1 ,w1 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 ,w1 * w1 * w2 , w2 * w1 * w2 , w1 * w1 * w2 ,w1 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,w1 * w1 * w2 , w2 * w1 * w2 , w1 * w1 * w2 ,w1 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 ,w1 * w2 * w1 , w2 * w2 * w1 , w1 * w2 * w1 ,w1 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 };
                GP.push_back(xi);
                GP.push_back(eta);
                GP.push_back(zeta);
                GP.push_back(w);
              }
              else if (NGP == 64) {
                double a = 0.861136311594953;
                double b = 0.339981043584856;
                double w1= 0.347854845137454;
                double w2= 0.6521451875456;
                std::vector<double> xi = {-a ,-b , b , a ,-a ,-b , b , a ,-a ,-b , b , a ,-a ,-b , b , a ,
                     -a ,-b , b , a ,-a ,-b , b , a ,-a ,-b , b , a ,-a ,-b , b , a ,
                     -a ,-b , b , a ,-a ,-b , b , a ,-a ,-b , b , a ,-a ,-b , b , a ,
                     -a ,-b , b , a ,-a ,-b , b , a ,-a ,-b , b , a ,-a ,-b , b , a ,
                     -a ,-b , b , a ,-a ,-b , b , a ,-a ,-b , b , a ,-a ,-b , b , a};
                std::vector<double> eta = {-a ,-a ,-a ,-a ,-b ,-b ,-b ,-b , b , b , b , b , a , a , a , a ,
                     -a ,-a ,-a ,-a ,-b ,-b ,-b ,-b , b , b , b , b , a , a , a , a ,
                     -a ,-a ,-a ,-a ,-b ,-b ,-b ,-b , b , b , b , b , a , a , a , a ,
                     -a ,-a ,-a ,-a ,-b ,-b ,-b ,-b , b , b , b , b , a , a , a , a ,
                     -a ,-a ,-a ,-a ,-b ,-b ,-b ,-b , b , b , b , b , a , a , a , a };
                std::vector<double> zeta {-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,
                     -b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                      b , b , b , b , b , b , b , b , b , b , b , b , b , b , b , b ,
                      a , a , a , a , a , a , a , a , a , a , a , a , a , a , a , a};
                std::vector<double> w = {w1 * w1 * w1 , w2 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 ,
                   w1 * w2 * w1 , w2 * w2 * w1 , w2 * w2 * w1 , w1 * w2 * w1 ,
                   w1 * w2 * w1 , w2 * w2 * w1 , w2 * w2 * w1 , w1 * w2 * w1 ,
                   w1 * w1 * w1 , w2 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 ,
                   w1 * w1 * w2 , w2 * w1 * w2 , w2 * w1 * w2 , w1 * w1 * w2 ,
                   w1 * w2 * w2 , w2 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                   w1 * w2 * w2 , w2 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                   w1 * w1 * w2 , w2 * w1 * w2 , w2 * w1 * w2 , w1 * w1 * w2 ,
                   w1 * w1 * w2 , w2 * w1 * w2 , w2 * w1 * w2 , w1 * w1 * w2 ,
                   w1 * w2 * w2 , w2 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                   w1 * w2 * w2 , w2 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                   w1 * w1 * w2 , w2 * w1 * w2 , w2 * w1 * w2 , w1 * w1 * w2 ,
                   w1 * w1 * w1 , w2 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 ,
                   w1 * w2 * w1 , w2 * w2 * w1 , w2 * w2 * w1 , w1 * w2 * w1 ,
                   w1 * w2 * w1 , w2 * w2 * w1 , w2 * w2 * w1 , w1 * w2 * w1 ,
                   w1 * w1 * w1 , w2 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 };
                GP.push_back(xi);
                GP.push_back(eta);
                GP.push_back(zeta);
                GP.push_back(w);
              }
              else if (NGP==125) {
                double a  = 0.9061798459;
                double b  = 0.538469310105683;
                double w1 = 0.236926885056189;
                double w2 = 0.478628670499366;
                double w3 = 0.568888888888889;

                std::vector<double> xi   = {-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,
                                        -a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,
                                        -a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,
                                        -a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,
                                            -a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a ,-a ,-b , 0 , b , a };

                std::vector<double> eta  = {-a ,-a ,-a ,-a ,-a ,-b ,-b ,-b ,-b ,-b , 0 , 0 , 0 , 0 , 0 , b , b , b , b , b , a , a , a , a , a ,
                                        -a ,-a ,-a ,-a ,-a ,-b ,-b ,-b ,-b ,-b , 0 , 0 , 0 , 0 , 0 , b , b , b , b , b , a , a , a , a , a ,
                                        -a ,-a ,-a ,-a ,-a ,-b ,-b ,-b ,-b ,-b , 0 , 0 , 0 , 0 , 0 , b , b , b , b , b , a , a , a , a , a ,
                                        -a ,-a ,-a ,-a ,-a ,-b ,-b ,-b ,-b ,-b , 0 , 0 , 0 , 0 , 0 , b , b , b , b , b , a , a , a , a , a ,
                                        -a ,-a ,-a ,-a ,-a ,-b ,-b ,-b ,-b ,-b , 0 , 0 , 0 , 0 , 0 , b , b , b , b , b , a , a , a , a , a };

                std::vector<double> zeta = {-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,-a ,
                                        -b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,-b ,
                                        0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
                                        a , a , a , a , a , a , a , a , a , a , a , a , a , a , a , a , a , a , a , a , a , a , a , a , a ,
                                        b , b , b , b , b , b , b , b , b , b , b , b , b , b , b , b , b , b , b , b , b , b , b , b , b };

                std::vector<double> w   = { w1 * w1 * w1 , w2 * w1 * w1 , w3 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 ,
                                     w1 * w2 * w1 , w2 * w2 * w1 , w3 * w2 * w1 , w2 * w2 * w1 , w1 * w2 * w1 ,
                                     w1 * w3 * w1 , w2 * w3 * w1 , w3 * w3 * w1 , w2 * w3 * w1 , w1 * w3 * w1 ,
                                     w1 * w2 * w1 , w2 * w2 * w1 , w3 * w2 * w1 , w2 * w2 * w1 , w1 * w2 * w1 ,
                                     w1 * w1 * w1 , w2 * w1 * w1 , w3 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 ,
                                     w1 * w1 * w2 , w2 * w1 * w2 , w3 * w1 * w2 , w2 * w1 * w2 , w1 * w1 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w3 * w2 , w2 * w3 * w2 , w3 * w3 * w2 , w2 * w3 * w2 , w1 * w3 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w1 * w2 , w2 * w1 * w2 , w3 * w1 * w2 , w2 * w1 * w2 , w1 * w1 * w2 ,
                                     w1 * w1 * w3 , w2 * w1 * w3 , w3 * w1 * w3 , w2 * w1 * w3 , w1 * w1 * w3 ,
                                     w1 * w2 * w3 , w2 * w2 * w3 , w3 * w2 * w3 , w2 * w2 * w3 , w1 * w2 * w3 ,
                                     w1 * w3 * w3 , w2 * w3 * w3 , w3 * w3 * w3 , w2 * w3 * w3 , w1 * w3 * w3 ,
                                     w1 * w2 * w3 , w2 * w2 * w3 , w3 * w2 * w3 , w2 * w2 * w3 , w1 * w2 * w3 ,
                                     w1 * w1 * w3 , w2 * w1 * w3 , w3 * w1 * w3 , w2 * w1 * w3 , w1 * w1 * w3 ,
                                     w1 * w1 * w2 , w2 * w1 * w2 , w3 * w1 * w2 , w2 * w1 * w2 , w1 * w1 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w3 * w2 , w2 * w3 * w2 , w3 * w3 * w2 , w2 * w3 * w2 , w1 * w3 * w2 ,
                                     w1 * w2 * w2 , w2 * w2 * w2 , w3 * w2 * w2 , w2 * w2 * w2 , w1 * w2 * w2 ,
                                     w1 * w1 * w2 , w2 * w1 * w2 , w3 * w1 * w2 , w2 * w1 * w2 , w1 * w1 * w2 ,
                                     w1 * w1 * w1 , w2 * w1 * w1 , w3 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 ,
                                     w1 * w2 * w1 , w2 * w2 * w1 , w3 * w2 * w1 , w2 * w2 * w1 , w1 * w2 * w1 ,
                                     w1 * w3 * w1 , w2 * w3 * w1 , w3 * w3 * w1 , w2 * w3 * w1 , w1 * w3 * w1 ,
                                     w1 * w2 * w1 , w2 * w2 * w1 , w3 * w2 * w1 , w2 * w2 * w1 , w1 * w2 * w1 ,
                                     w1 * w1 * w1 , w2 * w1 * w1 , w3 * w1 * w1 , w2 * w1 * w1 , w1 * w1 * w1 };
                GP.push_back(xi);
                GP.push_back(eta);
                GP.push_back(zeta);
                GP.push_back(w);
              }
              break;
          default: ;
    }
    return GP;
}

std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> compute_N(int deg, const vectors & GP, int PD) {
    // Compute shape functions and their derivatives
    int NGP;
    NGP = GP[0].size();
    std::vector<double> xi, w, eta, zeta;
    vectors N_xi_gp;
    vectors GradN_xi_gp;

    switch (PD) {
        case 1:
            xi = GP[0];
            w = GP[1];
        break;
        case 2:
            xi = GP[0];
            eta = GP[1];
            w = GP[2];
            break;
        case 3:
            xi = GP[0];
            eta = GP[1];
            zeta = GP[2];
            w = GP[3];
            break;
        default:
            break;
    }

    std::vector<std::vector<double>> N, dN_dxi, dN_deta, dN_dzeta;

    switch (PD) {
        case 1:
            switch (deg) {
                case 1:
                    N.resize(2, std::vector<double>(NGP));
                dN_dxi.resize(2, std::vector<double>(NGP));

                for (int i = 0; i < NGP; ++i) {
                    N[0][i] = -0.5  *  (xi[i] - 1.0);
                    N[1][i] = 0.5  *  (xi[i] + 1.0);

                    dN_dxi[0][i] = -0.5;
                    dN_dxi[1][i] = 0.5;
                }
                break;

                case 2:
                    N.resize(3, std::vector<double>(NGP));
                dN_dxi.resize(3, std::vector<double>(NGP));

                for (int i = 0; i < NGP; ++i) {
                    N[0][i] = 0.5  *  xi[i]  *  (xi[i] - 1.0);
                    N[1][i] = -1.0  *  (xi[i] - 1.0)  *  (xi[i] + 1.0);
                    N[2][i] = 0.5  *  xi[i]  *  (xi[i] + 1.0);

                    dN_dxi[0][i] = 0.5  *  (2  *  xi[i] - 1.0);
                    dN_dxi[1][i] = -2.0  *  xi[i];
                    dN_dxi[2][i] = 0.5  *  (2  *  xi[i] + 1.0);
                }
                break;

                case 3:
                    N.resize(4, std::vector<double>(NGP));
                dN_dxi.resize(4, std::vector<double>(NGP));

                for (int i = 0; i < NGP; ++i) {
                    N[0][i] = -9.0/16.0 *  (xi[i] + 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] - 1.0);
                    N[1][i] = 27.0/16.0 *  (xi[i] + 1.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] - 1.0);
                    N[2][i] = -27.0/16.0 *  (xi[i] + 1.0)  *  (xi[i] + 1.0/3.0)  *  (xi[i] - 1.0);
                    N[3][i] = 9.0/16.0 *  (xi[i] + 1.0)  *  (xi[i] + 1.0/3.0)  *  (xi[i] - 1.0/3.0);

                    dN_dxi[0][i] = -9.0/16.0 *  ((xi[i] - 1.0)  *  (xi[i] - 1.0/3.0) + (xi[i] + 1.0/3.0)  *  (xi[i] - 1.0) + (xi[i] + 1.0/3.0)  *  (xi[i] - 1.0/3.0));
                    dN_dxi[1][i] = 27.0/16.0 *  ((xi[i] - 1.0)  *  (xi[i] - 1.0/3.0) + (xi[i] + 1.0)  *  (xi[i] - 1.0) + (xi[i] + 1.0)  *  (xi[i] - 1.0/3.0));
                    dN_dxi[2][i] = -27.0/16.0 *  ((xi[i] - 1.0)  *  (xi[i] + 1.0/3.0) + (xi[i] + 1.0)  *  (xi[i] - 1.0) + (xi[i] + 1.0)  *  (xi[i] + 1.0/3.0));
                    dN_dxi[3][i] = 9.0/16.0 *  ((xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0) + (xi[i] + 1.0)  *  (xi[i] - 1.0/3.0) + (xi[i] + 1.0)  *  (xi[i] + 1.0/3.0));
                }
                break;

                case 4:
                    N.resize(5, std::vector<double>(NGP));
                dN_dxi.resize(5, std::vector<double>(NGP));

                for (int i = 0; i < NGP; ++i) {
                    N[0][i] = (2.0/3.0)  *  (xi[i] + 0.5)  *  xi[i]  *  (xi[i] - 0.5)  *  (xi[i] - 1.0);
                    N[1][i] = -(8.0/3.0)  *  (xi[i] + 1.0)  *  xi[i]  *  (xi[i] - 0.5)  *  (xi[i] - 1.0);
                    N[2][i] = 4.0  *  (xi[i] + 1.0)  *  (xi[i] + 0.5)  *  (xi[i] - 0.5)  *  (xi[i] - 1.0);
                    N[3][i] = -(8.0/3.0)  *  (xi[i] + 1.0)  *  (xi[i] + 0.5)  *  xi[i]  *  (xi[i] - 1.0);
                    N[4][i] = (2.0/3.0)  *  (xi[i] + 1.0)  *  (xi[i] + 0.5)  *  xi[i]  *  (xi[i] - 0.5);

                    dN_dxi[0][i] = (8  *  std::pow(xi[i], 3)) / 3.0 - 2  *  std::pow(xi[i], 2) - xi[i] / 3.0 + 1.0/6.0;
                    dN_dxi[1][i] = -(32  *  std::pow(xi[i], 3)) / 3.0 + 4  *  std::pow(xi[i], 2) + (16  *  xi[i]) / 3.0 - 4.0/3.0;
                    dN_dxi[2][i] = 16  *  std::pow(xi[i], 3) - 10  *  xi[i];
                    dN_dxi[3][i] = -(32  *  std::pow(xi[i], 3)) / 3.0 - 4  *  std::pow(xi[i], 2) + (16  *  xi[i]) / 3.0 + 4.0/3.0;
                    dN_dxi[4][i] = (8  *  std::pow(xi[i], 3)) / 3.0 + 2  *  std::pow(xi[i], 2) - xi[i] / 3.0 - 1.0/6.0;
                }
                break;
            }

        break;
        N_xi_gp = N;
        GradN_xi_gp = dN_dxi;

        case 2:
            switch (deg) {
                case 1:
                    N.resize(4, std::vector<double>(NGP));
                dN_dxi.resize(4, std::vector<double>(NGP));
                dN_deta.resize(4, std::vector<double>(NGP));

                for (int i = 0; i < NGP; ++i) {
                    N[0][i] = 0.25  *  (1.0 -  xi[i])  *  (1.0 -  eta[i]);
                    N[1][i] = 0.25  *  (1.0 +  xi[i])  *  (1.0 -  eta[i]);
                    N[2][i] = 0.25  *  (1.0 +  xi[i])  *  (1.0 +  eta[i]);
                    N[3][i] = 0.25  *  (1.0 -  xi[i])  *  (1.0 +  eta[i]);

                    dN_dxi[0][i] = -0.25  *  (1.0 -  eta[i]);
                    dN_dxi[1][i] = 0.25  *  (1.0 -  eta[i]);
                    dN_dxi[2][i] = 0.25  *  (1.0 +  eta[i]);
                    dN_dxi[3][i] = -0.25  *  (1.0 +  eta[i]);

                    dN_deta[0][i] = -0.25  *  (1.0 -  xi[i]);
                    dN_deta[1][i] = -0.25  *  (1.0 +  xi[i]);
                    dN_deta[2][i] = 0.25  *  (1.0 +  xi[i]);
                    dN_deta[3][i] = 0.25  *  (1.0 -  xi[i]);
                }
                break;

                case 2 :
                    N.resize(9, std::vector<double>(NGP));
                dN_dxi.resize(9, std::vector<double>(NGP));
                dN_deta.resize(9, std::vector<double>(NGP));

                for (int i = 0; i < NGP; ++i) {

                    N[0][i] = 0.25  *  (1.0 -  xi[i])  *  xi[i]  *  (1.0 -  eta[i])  *  eta[i];
                    N[1][i] = -0.25  *  (1.0 +  xi[i])  *  xi[i]  *  (1.0 -  eta[i])  *  eta[i];
                    N[2][i] = 0.25  *  (1.0 +  xi[i])  *  xi[i]  *  (1.0 +  eta[i])  *  eta[i];
                    N[3][i] = -0.25  *  (1.0 -  xi[i])  *  xi[i]  *  (1.0 +  eta[i])  *  eta[i];
                    N[4][i] = -0.5  *  (1.0 -  xi[i])  *  (1.0 +  xi[i])  *  (1.0 -  eta[i])  *  eta[i];
                    N[5][i] = 0.5  *  (1.0 +  xi[i])  *  xi[i]  *  (1.0 +  eta[i])  *  (1.0 -  eta[i]);
                    N[6][i] = 0.5  *  (1.0 -  xi[i])  *  (1.0 +  xi[i])  *  (1.0 +  eta[i])  *  eta[i];
                    N[7][i] = -0.5  *  (1.0 -  xi[i])  *  xi[i]  *  (1.0 +  eta[i])  *  (1.0 -  eta[i]);
                    N[8][i] = (1.0 -  xi[i])  *  (1.0 +  xi[i])  *  (1.0 +  eta[i])  *  (1.0 -  eta[i]);

                    dN_dxi[0][i] =  0.25  *  (1.0 -  2  *  xi[i])  *  (1.0 -  eta[i])  *  eta[i];
                    dN_dxi[1][i] = -0.25  *  (1.0 +  2  *  xi[i])  *  (1.0 -  eta[i])  *  eta[i];
                    dN_dxi[2][i] =  0.25  *  (1.0 +  2  *  xi[i])  *  (1.0 +  eta[i])  *  eta[i];
                    dN_dxi[3][i] = -0.25  *  (1.0 -  2  *  xi[i])  *  (1.0 +  eta[i])  *  eta[i];
                    dN_dxi[4][i] =  xi[i]  *  eta[i]  *  (1.0 -  eta[i]);
                    dN_dxi[5][i] =  0.50  *  (1.0 +  2  *  xi[i])  *  (1.0 -  eta[i])  *  (1.0 +  eta[i]);
                    dN_dxi[6][i] = -xi[i]  *  eta[i]  *  (1.0 +  eta[i]);
                    dN_dxi[7][i] = -0.50  *  (1.0 -  2  *  xi[i])  *  (1.0 -  eta[i])  *  (1.0 +  eta[i]);
                    dN_dxi[8][i] = -2.00  *  xi[i]  *  (1.0 -  eta[i])  *  (1.0 +  eta[i]);

                    dN_deta[0][i] =  0.25  *  (1.0 -  xi[i])  *  xi[i]  *  (1.0 -  2  *  eta[i]);
                    dN_deta[1][i] = -0.25  *  (1.0 +  xi[i])  *  xi[i]  *  (1.0 -  2  *  eta[i]);
                    dN_deta[2][i] =  0.25  *  (1.0 +  xi[i])  *  xi[i]  *  (1.0 +  2  *  eta[i]);
                    dN_deta[3][i] = -0.25  *  (1.0 -  xi[i])  *  xi[i]  *  (1.0 +  2  *  eta[i]);
                    dN_deta[4][i] =  0.50  *  (1.0 -  xi[i])  *  (1.0 +  xi[i])  *  (2  *  eta[i] - 1.0);
                    dN_deta[5][i] = -(1.0 +  xi[i])  *  xi[i]  *  eta[i];
                    dN_deta[6][i] =  0.50  *  (1.0 -  xi[i])  *  (1.0 +  xi[i])  *  (1.0 +  2  *  eta[i]);
                    dN_deta[7][i] =  (1.0 -  xi[i])  *  xi[i]  *  (eta[i]);
                    dN_deta[8][i] = -2.00  *  (1.0 -  xi[i])  *  (1.0 +  xi[i])  *  (eta[i]);
                }
                break;

                case 3:
                    N.resize(16, std::vector<double>(NGP));
                dN_dxi.resize(16, std::vector<double>(NGP));
                dN_deta.resize(16, std::vector<double>(NGP));

                for (int i = 0; i < NGP; ++i) {

                    N[0][i]  =  (((9.0  *  eta[i]) / 16.0) + (3.0 / 16.0))   *  ((9  *  xi[i]) / 16.0 + 3.0 / 16.0)   *  (eta[i] - 1.0)   *  (eta[i] - 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] - 1.0 / 3.0);
                    N[1][i]  = -((9.0  *  eta[i]) / 16.0 + 3.0 / 16.0)   *  ((9  *  xi[i]) / 16.0 + 9.0 / 16.0)   *  (eta[i] - 1.0)   *  (eta[i] - 1.0 / 3.0)  *  (xi[i] - 1.0 / 3.0)  *  (xi[i] + 1.0 / 3.0);
                    N[2][i]  =  ((9.0  *  eta[i]) / 16.0 + 9.0 / 16.0)   *  ((9  *  xi[i]) / 16.0 + 9.0 / 16.0)   *  (eta[i] - 1.0 / 3.0)  *  (eta[i] + 1.0 / 3.0)  *  (xi[i] - 1.0 / 3.0)  *  (xi[i] + 1.0 / 3.0);
                    N[3][i]  = -((9.0  *  eta[i]) / 16.0 + 9.0 / 16.0)   *  ((9  *  xi[i]) / 16.0 + 3.0 / 16.0)   *  (eta[i] - 1.0 / 3.0)  *  (eta[i] + 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] - 1.0 / 3.0);
                    N[4][i]  = -((9  *  eta[i]) / 16.0 + 3.0 / 16.0)   *  ((27  *  xi[i]) / 16.0 + 27.0 / 16.0)  *  (eta[i] - 1.0)   *  (eta[i] - 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] - 1.0 / 3.0);
                    N[5][i]  =  ((9  *  eta[i]) / 16.0 + 3.0 / 16.0)   *  ((27  *  xi[i]) / 16.0 + 27.0 / 16.0)  *  (eta[i] - 1.0)   *  (eta[i] - 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] + 1.0 / 3.0);
                    N[6][i]  =  ((27  *  eta[i]) / 16.0 + 27.0 / 16.0)  *  ((9  *  xi[i]) / 16.0 + 9.0 / 16.0)   *  (eta[i] - 1.0)   *  (eta[i] - 1.0 / 3.0)  *  (xi[i] - 1.0 / 3.0)  *  (xi[i] + 1.0 / 3.0);
                    N[7][i]  = -((27  *  eta[i]) / 16.0 + 27.0 / 16.0)  *  ((9  *  xi[i]) / 16.0 + 9.0 / 16.0)   *  (eta[i] - 1.0)   *  (eta[i] + 1.0 / 3.0)  *  (xi[i] - 1.0 / 3.0)  *  (xi[i] + 1.0 / 3.0);
                    N[8][i]  = -((9  *  eta[i]) / 16.0 + 9.0 / 16.0)   *  ((27  *  xi[i]) / 16.0 + 27.0 / 16.0)  *  (eta[i] - 1.0 / 3.0)  *  (eta[i] + 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] + 1.0 / 3.0);
                    N[9][i]  =  ((9  *  eta[i]) / 16.0 + 9.0 / 16.0)   *  ((27  *  xi[i]) / 16.0 + 27.0 / 16.0)  *  (eta[i] - 1.0 / 3.0)  *  (eta[i] + 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] - 1.0 / 3.0);
                    N[10][i] =  ((27  *  eta[i]) / 16.0 + 27.0 / 16.0)  *  ((9  *  xi[i]) / 16.0 + 3.0 / 16.0)   *  (eta[i] - 1.0)   *  (eta[i] + 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] - 1.0 / 3.0);
                    N[11][i] = -((27  *  eta[i]) / 16.0 + 27.0 / 16.0)  *  ((9  *  xi[i]) / 16.0 + 3.0 / 16.0)   *  (eta[i] - 1.0)   *  (eta[i] - 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] - 1.0 / 3.0);
                    N[12][i] =  ((27  *  eta[i]) / 16.0 + 27.0 / 16.0)  *  ((27  *  xi[i]) / 16.0 + 27.0 / 16.0)  *  (eta[i] - 1.0)   *  (eta[i] - 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] - 1.0 / 3.0);
                    N[13][i] = -((27  *  eta[i]) / 16.0 + 27.0 / 16.0)  *  ((27  *  xi[i]) / 16.0 + 27.0 / 16.0)  *  (eta[i] - 1.0)   *  (eta[i] - 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] + 1.0 / 3.0);
                    N[14][i] =  ((27  *  eta[i]) / 16.0 + 27.0 / 16.0)  *  ((27  *  xi[i]) / 16.0 + 27.0 / 16.0)  *  (eta[i] - 1.0)   *  (eta[i] + 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] + 1.0 / 3.0);
                    N[15][i] = -((27  *  eta[i]) / 16.0 + 27.0 / 16.0)  *  ((27  *  xi[i]) / 16.0 + 27.0 / 16.0)  *  (eta[i] - 1.0)   *  (eta[i] + 1.0 / 3.0)  *  (xi[i] - 1.0)   *  (xi[i] - 1.0 / 3.0);

                    dN_dxi[0][i]  =  ((-27  *  std::pow(xi[i],2) + 18 * xi[i] + 1.0)  *  (- 9 * std::pow(eta[i],3) + 9 * std::pow(eta[i],2) + eta[i] - 1.0))/256.0;
                    dN_dxi[1][i]  =  ((27  *  std::pow(xi[i],2) + 18 * xi[i] - 1.0)   *  (- 9 * std::pow(eta[i],3) + 9 * std::pow(eta[i],2) + eta[i] - 1.0))/256.0;
                    dN_dxi[2][i]  = -((27 * std::pow(xi[i],2) + 18 * xi[i] - 1.0)     *  (- 9 * std::pow(eta[i],3) - 9 * std::pow(eta[i],2) + eta[i] + 1.0))/256.0;
                    dN_dxi[3][i]  = -((- 27 * std::pow(xi[i],2) + 18 * xi[i] + 1.0)   *  (- 9 * std::pow(eta[i],3) - 9 * std::pow(eta[i],2) + eta[i] + 1.0))/256.0;
                    dN_dxi[4][i]  = -(9 * (- 9 * std::pow(xi[i],2) + 2 * xi[i] + 3.0)   *  (- 9 * std::pow(eta[i],3) + 9 * std::pow(eta[i],2) + eta[i] - 1.0))/256.0;
                    dN_dxi[5][i]  = -(9 * (9 * std::pow(xi[i],2) + 2 * xi[i] - 3.0)     *  (- 9 * std::pow(eta[i],3) + 9 * std::pow(eta[i],2) + eta[i] - 1.0))/256.0;
                    dN_dxi[6][i]  = -(9 * (27 * std::pow(xi[i],2) + 18 * xi[i] - 1.0)   *  (- 3 * std::pow(eta[i],3) + std::pow(eta[i],2) + 3 * eta[i] - 1.0))/256.0;
                    dN_dxi[7][i]  =  (9 * (27 * std::pow(xi[i],2) + 18 * xi[i] - 1.0)   *  (- 3 * std::pow(eta[i],3) - std::pow(eta[i],2) + 3 * eta[i] + 1.0))/256.0;
                    dN_dxi[8][i]  =  (9 * (9 * std::pow(xi[i],2) + 2 * xi[i] - 3.0)     *  (- 9 * std::pow(eta[i],3) - 9 * std::pow(eta[i],2) + eta[i] + 1.0))/256.0;
                    dN_dxi[9][i]  =  (9 * (- 9 * std::pow(xi[i],2) + 2 * xi[i] + 3.0)   *  (- 9 * std::pow(eta[i],3) - 9 * std::pow(eta[i],2) + eta[i] + 1.0))/256.0;
                    dN_dxi[10][i] =  (9 * (- 27 * std::pow(xi[i],2) + 18 * xi[i] + 1.0) *  (- 3 * std::pow(eta[i],3) - std::pow(eta[i],2) + 3 * eta[i] + 1.0))/256.0;
                    dN_dxi[11][i] = -(9 * (- 27 * std::pow(xi[i],2) + 18 * xi[i] + 1.0) *  (- 3 * std::pow(eta[i],3) + std::pow(eta[i],2) + 3 * eta[i] - 1.0))/256.0;
                    dN_dxi[12][i] =  (81 * (- 9 * std::pow(xi[i],2) + 2 * xi[i] + 3.0)  *  (- 3 * std::pow(eta[i],3) + std::pow(eta[i],2) + 3 * eta[i] - 1.0))/256.0;
                    dN_dxi[13][i] =  (81 * (9 * std::pow(xi[i],2) + 2 * xi[i] - 3.0)    *  (- 3 * std::pow(eta[i],3) + std::pow(eta[i],2) + 3 * eta[i] - 1.0))/256.0;
                    dN_dxi[14][i] = -(81 * (9 * std::pow(xi[i],2) + 2 * xi[i] - 3.0)    *  (- 3 * std::pow(eta[i],3) - std::pow(eta[i],2) + 3 * eta[i] + 1.0))/256.0;
                    dN_dxi[15][i] = -(81 * (- 9 * std::pow(xi[i],2) + 2 * xi[i] + 3.0)  *  (- 3 * std::pow(eta[i],3) - std::pow(eta[i],2) + 3 * eta[i] + 1.0))/256.0;

                    dN_deta[0][i]  =  ((- 27 * std::pow(eta[i],2) + 18 * eta[i] + 1.0)   *  (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i],2) + xi[i] - 1.0))/256.0;
                    dN_deta[1][i]  = -((- 27 * std::pow(eta[i],2) + 18 * eta[i] + 1.0)   *  (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i],2) + xi[i] + 1.0))/256.0;
                    dN_deta[2][i]  = -((27 * std::pow(eta[i],2) + 18 * eta[i] - 1.0)     *  (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i],2) + xi[i] + 1.0))/256.0;
                    dN_deta[3][i]  =  ((27 * std::pow(eta[i],2) + 18 * eta[i] - 1.0)     *  (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i],2) + xi[i] - 1.0))/256.0;
                    dN_deta[4][i]  = -(9 * (- 27 * std::pow(eta[i],2) + 18 * eta[i] + 1.0) *  (- 3 * std::pow(xi[i],3) + std::pow(xi[i],2) + 3 * xi[i] - 1.0))/256.0;
                    dN_deta[5][i]  =  (9 * (- 27 * std::pow(eta[i],2) + 18 * eta[i] + 1.0) *  (- 3 * std::pow(xi[i],3) - std::pow(xi[i],2) + 3 * xi[i] + 1.0))/256.0;
                    dN_deta[6][i]  =  (9 * (- 9 * std::pow(eta[i],2) + 2 * eta[i] + 3.0)   *  (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i],2) + xi[i] + 1.0))/256.0;
                    dN_deta[7][i]  =  (9 * (9 * std::pow(eta[i],2) + 2 * eta[i] - 3.0)     *  (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i],2) + xi[i] + 1.0))/256.0;
                    dN_deta[8][i]  =  (9 * (27 * std::pow(eta[i],2) + 18 * eta[i] - 1.0)   *  (- 3 * std::pow(xi[i],3) - std::pow(xi[i],2) + 3 * xi[i] + 1.0))/256.0;
                    dN_deta[9][i]  = -(9 * (27 * std::pow(eta[i],2) + 18 * eta[i] - 1.0)   *  (- 3 * std::pow(xi[i],3) + std::pow(xi[i],2) + 3 * xi[i] - 1.0))/256.0;
                    dN_deta[10][i] = -(9 * (9 * std::pow(eta[i],2) + 2 * eta[i] - 3.0)     *  (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i],2) + xi[i] - 1.0))/256.0;
                    dN_deta[11][i] = -(9 * (- 9 * std::pow(eta[i],2) + 2 * eta[i] + 3.0)   *  (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i],2) + xi[i] - 1.0))/256.0;
                    dN_deta[12][i] =  (81 * (- 9 * std::pow(eta[i],2) + 2 * eta[i] + 3.0)  *  (- 3 * std::pow(xi[i],3) + std::pow(xi[i],2) + 3 * xi[i] - 1.0))/256.0;
                    dN_deta[13][i] = -(81 * (- 9 * std::pow(eta[i],2) + 2 * eta[i] + 3.0)  *  (- 3 * std::pow(xi[i],3) - std::pow(xi[i],2) + 3 * xi[i] + 1.0))/256.0;
                    dN_deta[14][i] = -(81 * (9 * std::pow(eta[i],2) + 2 * eta[i] - 3.0)    *  (- 3 * std::pow(xi[i],3) - std::pow(xi[i],2) + 3 * xi[i] + 1.0))/256.0;
                    dN_deta[15][i] =  (81 * (9 * std::pow(eta[i],2) + 2 * eta[i] - 3.0)    *  (- 3 * std::pow(xi[i],3) + std::pow(xi[i],2) + 3 * xi[i] - 1.0))/256.0;
                }
                break;

                case 4:
                    N.resize(25, std::vector<double>(NGP)); // Assuming N has 16 rows, adjust as necessary
                dN_dxi.resize(25, std::vector<double>(NGP));
                dN_deta.resize(25, std::vector<double>(NGP));

                for (int i = 0; i < NGP; ++i) {

                    N[0][i]  =  (4.0/9.0)   *  (0.5 + xi[i])  *  (xi[i])        *  (0.5 - xi[i])  *  (1.0 -  xi[i])    *  (0.5 + eta[i])  *  (eta[i])      *  (0.5 - eta[i])  *  (1.0 -  eta[i]);
                    N[1][i]  = -(4.0/9.0)   *  (1.0 +  xi[i])    *  (0.5 + xi[i])  *  (xi[i])        *  (0.5 - xi[i])  *  (0.5 + eta[i])  *  (eta[i])      *  (0.5 - eta[i])  *  (1.0 -  eta[i]);
                    N[2][i]  =  (4.0/9.0)    *   (1.0 +  xi[i])     *   (0.5 + xi[i])  *  (xi[i])        *  (0.5 - xi[i])  *  (1.0 +  eta[i])    *  (0.5 + eta[i])  *  (eta[i])      *  (0.5 - eta[i]);
                    N[3][i]  = -(4.0/9.0)   *  (0.5 + xi[i])  *  (xi[i])        *  (0.5 - xi[i])  *  (1.0 -  xi[i])    *  (1.0 +  eta[i])    *  (0.5 + eta[i])  *  (eta[i])      *  (0.5 - eta[i]);
                    N[4][i]  = -(16.0/9.0)  *  (1.0 + xi[i])    *  (xi[i])      *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (0.5+eta[i])  *  (eta[i])      *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[5][i]  =  (8.0/3.0)   *  (1.0 + xi[i])    *  (0.5+xi[i])  *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (0.5+eta[i])  *  (eta[i])      *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[6][i]  =  (16.0/9.0)  *  (1.0 + xi[i])    *  (0.5+xi[i])  *  (xi[i])      *  (1.0 - xi[i])    *  (0.5+eta[i])  *  (eta[i])      *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[7][i]  =  (16.0/9.0)  *  (1.0 + xi[i])    *  (0.5+xi[i])  *  (xi[i])      *  (0.5-xi[i])  *  (1.0 + eta[i])    *  (eta[i])      *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[8][i]  = -(8.0/3.0)   *  (1.0 + xi[i])    *  (0.5+xi[i])  *  (xi[i])      *  (0.5-xi[i])  *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[9][i]  = -(16.0/9.0)  *  (1.0 + xi[i])     *  (0.5+xi[i])  *  (xi[i])      *  (0.5-xi[i])  *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (eta[i])       *   (1.0 - eta[i]);
                    N[10][i] = -(16.0/9.0)  *  (1.0 + xi[i])    *  (0.5+xi[i])  *  (xi[i])      *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (eta[i])       *   (0.5-eta[i]);
                    N[11][i] = -(8.0/3.0)   *  (1.0 + xi[i])    *  (0.5+xi[i])  *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (eta[i])       *   (0.5-eta[i]);
                    N[12][i] =  (16.0/9.0)  *  (1.0 + xi[i])    *  (xi[i])      *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (eta[i])       *   (0.5-eta[i]);
                    N[13][i] =  (16.0/9.0)  *  (0.5+xi[i])  *  (xi[i])      *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (eta[i])       *   (1.0 - eta[i]);
                    N[14][i] =  (8.0/3.0)   *  (0.5+xi[i])  *  (xi[i])      *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[15][i] = -(16.0/9.0)  *  (0.5+xi[i])  *  (xi[i])      *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (eta[i])      *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[16][i] =  (64.0/9.0)  *  (1.0 + xi[i])    *  (xi[i])      *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (eta[i])      *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[17][i] = -(32.0/3.0)  *  (1.0 + xi[i])    *  (0.5+xi[i])  *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (eta[i])      *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[18][i] = -(64.0/9.0)  *  (1.0 + xi[i])    *  (0.5+xi[i])  *  (xi[i])      *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (eta[i])      *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[19][i] =  (32.0/3.0)  *  (1.0 + xi[i])    *  (0.5+xi[i])  *  (xi[i])      *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[20][i] =  (64.0/9.0)  *  (1.0 + xi[i])     *  (0.5+xi[i])  *  (xi[i])      *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (eta[i])       *   (1.0 - eta[i]);
                    N[21][i] =  (32.0/3.0)  *  (1.0 + xi[i])    *  (0.5+xi[i])  *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (eta[i])       *   (1.0 - eta[i]);
                    N[22][i] = -(64.0/9.0)  *  (1.0 + xi[i])    *  (xi[i])      *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (eta[i])       *   (1.0 - eta[i]);
                    N[23][i] = -(32.0/3.0)  *  (1.0 + xi[i])    *  (xi[i])      *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (0.5-eta[i])   *   (1.0 - eta[i]);
                    N[24][i] =  (16.0)    *  (1.0 + xi[i])    *  (0.5+xi[i])  *  (0.5-xi[i])  *  (1.0 - xi[i])    *  (1.0 + eta[i])    *  (0.5+eta[i])  *  (0.5-eta[i])   *   (1.0 - eta[i]);

                    dN_dxi[0][i]  =  (eta[i]  *  (- 4 * std::pow(eta[i],3) + 4 * std::pow(eta[i],2) + eta[i] - 1.0)  *  (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i],2) + 2 * xi[i] - 1.0))/36.0;
                    dN_dxi[1][i]  =  (eta[i]  *  (- 4 * std::pow(eta[i],3) + 4 * std::pow(eta[i],2) + eta[i] - 1.0)  *  (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i],2) + 2 * xi[i] + 1.0))/36.0;
                    dN_dxi[2][i]  =  (eta[i]  *  (- 4 * std::pow(eta[i],3) - 4 * std::pow(eta[i],2) + eta[i] + 1.0)  *  (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i],2) + 2 * xi[i] + 1.0))/36.0;
                    dN_dxi[3][i]  =  (eta[i]  *  (- 4 * std::pow(eta[i],3) - 4 * std::pow(eta[i],2) + eta[i] + 1.0)  *  (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i],2) + 2 * xi[i] - 1.0))/36.0;
                    dN_dxi[4][i]  = -(2 * eta[i]  *  (- 4 * std::pow(eta[i],3) + 4 * std::pow(eta[i],2) + eta[i] - 1.0)  *  (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i],2) + 4 * xi[i] - 1.0))/9;
                    dN_dxi[5][i]  = -(eta[i]  *  xi[i]  *  (8 * std::pow(xi[i],2) - 5)  *  (- 4 * std::pow(eta[i],3) + 4 * std::pow(eta[i],2) + eta[i] - 1.0))/3;
                    dN_dxi[6][i]  = -(2 * eta[i]  *  (- 4 * std::pow(eta[i],3) + 4 * std::pow(eta[i],2) + eta[i] - 1.0)  *  (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i],2) + 4 * xi[i] + 1.0))/9;
                    dN_dxi[7][i]  = -(2 * eta[i]  *  (- 2 * std::pow(eta[i],3) + std::pow(eta[i],2) + 2 * eta[i] - 1.0)  *  (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i],2) + 2 * xi[i] + 1.0))/9;
                    dN_dxi[8][i]  = -((4 *std::pow(eta[i],4) - 5 * std::pow(eta[i],2) + 1.0)  *  (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i],2) + 2 * xi[i] + 1.0))/6;
                    dN_dxi[9][i]  = -(2 * eta[i]  *  (- 2 * std::pow(eta[i],3) - std::pow(eta[i],2) + 2 * eta[i] + 1.0)  *  (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i],2) + 2 * xi[i] + 1.0))/9;
                    dN_dxi[10][i] = -(2 * eta[i]  *  (- 4 * std::pow(eta[i],3) - 4 * std::pow(eta[i],2) + eta[i] + 1.0)  *  (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i],2) + 4 * xi[i] + 1.0))/9;
                    dN_dxi[11][i] = -(eta[i]  *  xi[i]  *  (8 * std::pow(xi[i],2) - 5)  *  (- 4 * std::pow(eta[i],3) - 4 * std::pow(eta[i],2) + eta[i] + 1.0))/3;
                    dN_dxi[12][i] = -(2 * eta[i]  *  (- 4 * std::pow(eta[i],3) - 4 * std::pow(eta[i],2) + eta[i] + 1.0)  *  (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i],2) + 4 * xi[i] - 1.0))/9;
                    dN_dxi[13][i] = -(2 * eta[i]  *  (- 2 * std::pow(eta[i],3) - std::pow(eta[i],2) + 2 * eta[i] + 1.0)  *  (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i],2) + 2 * xi[i] - 1.0))/9;
                    dN_dxi[14][i] = -((4 *std::pow(eta[i],4) - 5 * std::pow(eta[i],2) + 1.0)  *  (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i],2) + 2 * xi[i] - 1.0))/6;
                    dN_dxi[15][i] = -(2 * eta[i]  *  (- 2 * std::pow(eta[i],3) + std::pow(eta[i],2) + 2 * eta[i] - 1.0)  *  (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i],2) + 2 * xi[i] - 1.0))/9;
                    dN_dxi[16][i] =  (16 * eta[i]  *  (- 2 * std::pow(eta[i],3) + std::pow(eta[i],2) + 2 * eta[i] - 1.0)  *  (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i],2) + 4 * xi[i] - 1.0))/9;
                    dN_dxi[17][i] =  (8 * eta[i]  *  xi[i]  *  (8 * std::pow(xi[i],2) - 5)  *  (- 2 * std::pow(eta[i],3) + std::pow(eta[i],2) + 2 * eta[i] - 1.0))/3;
                    dN_dxi[18][i] =  (16 * eta[i]  *  (- 2 * std::pow(eta[i],3) + std::pow(eta[i],2) + 2 * eta[i] - 1.0)  *  (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i],2) + 4 * xi[i] + 1.0))/9;
                    dN_dxi[19][i] =  (4 * (4 *std::pow(eta[i],4) - 5 * std::pow(eta[i],2) + 1.0)  *  (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i],2) + 4 * xi[i] + 1.0))/3;
                    dN_dxi[20][i] =  (16 * eta[i]  *  (- 2 * std::pow(eta[i],3) - std::pow(eta[i],2) + 2 * eta[i] + 1.0)  *  (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i],2) + 4 * xi[i] + 1.0))/9;
                    dN_dxi[21][i] =  (8 * eta[i]  *  xi[i]  *  (8 * std::pow(xi[i],2) - 5)  *  (- 2 * std::pow(eta[i],3) - std::pow(eta[i],2) + 2 * eta[i] + 1.0))/3;
                    dN_dxi[22][i] =  (16 * eta[i]  *  (- 2 * std::pow(eta[i],3) - std::pow(eta[i],2) + 2 * eta[i] + 1.0)  *  (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i],2) + 4 * xi[i] - 1.0))/9;
                    dN_dxi[23][i] =  (4 * (4 *std::pow(eta[i],4) - 5 * std::pow(eta[i],2) + 1.0)  *  (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i],2) + 4 * xi[i] - 1.0))/3;
                    dN_dxi[24][i] =  2 * xi[i]  *  (8 * std::pow(xi[i],2) - 5)  *  (4 *std::pow(eta[i],4) - 5 * std::pow(eta[i],2) + 1.0);

                    dN_deta[0][i]  = (xi[i]  *  (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i],2) + xi[i] - 1.0)  *  (- 16 * std::pow(eta[i],3) + 12 * std::pow(eta[i],2) + 2 * eta[i] - 1.0))/36.0;
                    dN_deta[1][i]  = (xi[i]  *  (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i],2) + xi[i] + 1.0)  *  (- 16 * std::pow(eta[i],3) + 12 * std::pow(eta[i],2) + 2 * eta[i] - 1.0))/36.0;
                    dN_deta[2][i]  = (xi[i]  *  (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i],2) + xi[i] + 1.0)  *  (- 16 * std::pow(eta[i],3) - 12 * std::pow(eta[i],2) + 2 * eta[i] + 1.0))/36.0;
                    dN_deta[3][i]  = (xi[i]  *  (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i],2) + xi[i] - 1.0)  *  (- 16 * std::pow(eta[i],3) - 12 * std::pow(eta[i],2) + 2 * eta[i] + 1.0))/36.0;
                    dN_deta[4][i]  = -(2 * xi[i]  *  (- 2 * std::pow(xi[i],3) + std::pow(xi[i],2) + 2 * xi[i] - 1.0)  *  (- 16 * std::pow(eta[i],3) + 12 * std::pow(eta[i],2) + 2 * eta[i] - 1.0))/9;
                    dN_deta[5][i]  = -((4 *  std::pow(xi[i],4) - 5 * std::pow(xi[i],2) + 1.0)  *  (- 16 * std::pow(eta[i],3) + 12 * std::pow(eta[i],2) + 2 * eta[i] - 1.0))/6;
                    dN_deta[6][i]  = -(2 * xi[i]  *  (- 16 * std::pow(eta[i],3) + 12 * std::pow(eta[i],2) + 2 * eta[i] - 1.0)  *  (- 2 * std::pow(xi[i],3) - std::pow(xi[i],2) + 2 * xi[i] + 1.0))/9;
                    dN_deta[7][i]  = -(2 * xi[i]  *  (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i],2) + xi[i] + 1.0)  *  (- 8 * std::pow(eta[i],3) + 3 * std::pow(eta[i],2) + 4 * eta[i] - 1.0))/9;
                    dN_deta[8][i]  = -(eta[i]  *  xi[i]  *  (8 * std::pow(eta[i],2) - 5)  *  (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i],2) + xi[i] + 1.0))/3;
                    dN_deta[9][i]  = -(2 * xi[i]  *  (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i],2) + xi[i] + 1.0)  *  (- 8 * std::pow(eta[i],3) - 3 * std::pow(eta[i],2) + 4 * eta[i] + 1.0))/9;
                    dN_deta[10][i] = -(2 * xi[i]  *  (- 16 * std::pow(eta[i],3) - 12 * std::pow(eta[i],2) + 2 * eta[i] + 1.0)  *  (- 2 * std::pow(xi[i],3) - std::pow(xi[i],2) + 2 * xi[i] + 1.0))/9;
                    dN_deta[11][i] = -((4 *  std::pow(xi[i],4) - 5 * std::pow(xi[i],2) + 1.0)  *  (- 16 * std::pow(eta[i],3) - 12 * std::pow(eta[i],2) + 2 * eta[i] + 1.0))/6;
                    dN_deta[12][i] = -(2 * xi[i]  *  (- 2 * std::pow(xi[i],3) + std::pow(xi[i],2) + 2 * xi[i] - 1.0)  *  (- 16 * std::pow(eta[i],3) - 12 * std::pow(eta[i],2) + 2 * eta[i] + 1.0))/9;
                    dN_deta[13][i] = -(2 * xi[i]  *  (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i],2) + xi[i] - 1.0)  *  (- 8 * std::pow(eta[i],3) - 3 * std::pow(eta[i],2) + 4 * eta[i] + 1.0))/9;
                    dN_deta[14][i] = -(eta[i]  *  xi[i]  *  (8 * std::pow(eta[i],2) - 5)  *  (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i],2) + xi[i] - 1.0))/3;
                    dN_deta[15][i] = -(2 * xi[i]  *  (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i],2) + xi[i] - 1.0)  *  (- 8 * std::pow(eta[i],3) + 3 * std::pow(eta[i],2) + 4 * eta[i] - 1.0))/9;
                    dN_deta[16][i] = (16 * xi[i]  *  (- 2 * std::pow(xi[i],3) + std::pow(xi[i],2) + 2 * xi[i] - 1.0)  *  (- 8 * std::pow(eta[i],3) + 3 * std::pow(eta[i],2) + 4 * eta[i] - 1.0))/9;
                    dN_deta[17][i] = (4 * (4 *  std::pow(xi[i],4) - 5 * std::pow(xi[i],2) + 1.0)  *  (- 8 * std::pow(eta[i],3) + 3 * std::pow(eta[i],2) + 4 * eta[i] - 1.0))/3;
                    dN_deta[18][i] = (16 * xi[i]  *  (- 8 * std::pow(eta[i],3) + 3 * std::pow(eta[i],2) + 4 * eta[i] - 1.0)  *  (- 2 * std::pow(xi[i],3) - std::pow(xi[i],2) + 2 * xi[i] + 1.0))/9;
                    dN_deta[19][i] = (8 * eta[i]  *  xi[i]  *  (8 * std::pow(eta[i],2) - 5)  *  (- 2 * std::pow(xi[i],3) - std::pow(xi[i],2) + 2 * xi[i] + 1.0))/3;
                    dN_deta[20][i] = (16 * xi[i]  *  (- 8 * std::pow(eta[i],3) - 3 * std::pow(eta[i],2) + 4 * eta[i] + 1.0)  *  (- 2 * std::pow(xi[i],3) - std::pow(xi[i],2) + 2 * xi[i] + 1.0))/9;
                    dN_deta[21][i] = (4 * (4 *  std::pow(xi[i],4) - 5 * std::pow(xi[i],2) + 1.0)  *  (- 8 * std::pow(eta[i],3) - 3 * std::pow(eta[i],2) + 4 * eta[i] + 1.0))/3;
                    dN_deta[22][i] = (16 * xi[i]  *  (- 2 * std::pow(xi[i],3) + std::pow(xi[i],2) + 2 * xi[i] - 1.0)  *  (- 8 * std::pow(eta[i],3) - 3 * std::pow(eta[i],2) + 4 * eta[i] + 1.0))/9;
                    dN_deta[23][i] = (8 * eta[i]  *  xi[i]  *  (8 * std::pow(eta[i],2) - 5)  *  (- 2 * std::pow(xi[i],3) + std::pow(xi[i],2) + 2 * xi[i] - 1.0))/3;
                    dN_deta[24][i] = 2 * eta[i]  *  (8 * std::pow(eta[i],2) - 5)  *  (4 *  std::pow(xi[i],4) - 5 * std::pow(xi[i],2) + 1.0);
                }
                break;
            }
        {
        N_xi_gp = N;
        vectors GradN_xi_gp(dN_dxi.size(), std::vector<double>(dN_dxi[0].size() + dN_deta[0].size()));

        for (size_t i = 0; i < dN_dxi.size(); ++i) {
            for (size_t j = 0; j < dN_dxi[i].size(); ++j) {
                GradN_xi_gp[i][j] = dN_dxi[i][j];
            }

            for (size_t j = 0; j < dN_deta[i].size(); ++j) {
                GradN_xi_gp[i][dN_dxi[i].size() + j] = dN_deta[i][j];
            }
        }
        }
        case 3 :
            switch (deg){
                case 1 :
                    N.resize(8, std::vector<double>(NGP));
                    dN_dxi.resize(8, std::vector<double>(NGP));
                    dN_deta.resize(8, std::vector<double>(NGP));
                    dN_dzeta.resize(8, std::vector<double>(NGP));

                    for (int i = 0; i < NGP; i++)
                    {
                        N[0][i] = 1.0/8.0  *  (1.0 - xi[i])  *  (1.0 - eta[i])  *  (1.0 - zeta[i]);
                        N[1][i] = 1.0/8.0  *  (1.0 + xi[i])  *  (1.0 - eta[i])  *  (1.0 - zeta[i]);
                        N[2][i] = 1.0/8.0  *  (1.0 + xi[i])  *  (1.0 + eta[i])  *  (1.0 - zeta[i]);
                        N[3][i] = 1.0/8.0  *  (1.0 - xi[i])  *  (1.0 + eta[i])  *  (1.0 - zeta[i]);
                        N[4][i] = 1.0/8.0  *  (1.0 - xi[i])  *  (1.0 - eta[i])  *  (1.0 + zeta[i]);
                        N[5][i] = 1.0/8.0  *  (1.0 + xi[i])  *  (1.0 - eta[i])  *  (1.0 + zeta[i]);
                        N[6][i] = 1.0/8.0  *  (1.0 + xi[i])  *  (1.0 + eta[i])  *  (1.0 + zeta[i]);
                        N[7][i] = 1.0/8.0  *  (1.0 - xi[i])  *  (1.0 + eta[i])  *  (1.0 + zeta[i]);

                        dN_dxi[0][i] = -1.0/8.0  *  (1.0 - eta[i])  *  (1.0 - zeta[i]);
                        dN_dxi[1][i] =  1.0/8.0  *  (1.0 - eta[i])  *  (1.0 - zeta[i]);
                        dN_dxi[2][i] =  1.0/8.0  *  (1.0 + eta[i])  *  (1.0 - zeta[i]);
                        dN_dxi[3][i] = -1.0/8.0  *  (1.0 + eta[i])  *  (1.0 - zeta[i]);
                        dN_dxi[4][i] = -1.0/8.0  *  (1.0 - eta[i])  *  (1.0 + zeta[i]);
                        dN_dxi[5][i] =  1.0/8.0  *  (1.0 - eta[i])  *  (1.0 + zeta[i]);
                        dN_dxi[6][i] =  1.0/8.0  *  (1.0 + eta[i])  *  (1.0 + zeta[i]);
                        dN_dxi[7][i] = -1.0/8.0  *  (1.0 + eta[i])  *  (1.0 + zeta[i]);

                        dN_deta[0][i] = -1.0/8.0  *  (1.0 - xi[i])  *  (1.0 - zeta[i]);
                        dN_deta[1][i] = -1.0/8.0  *  (1.0 + xi[i])  *  (1.0 - zeta[i]);
                        dN_deta[2][i] =  1.0/8.0  *  (1.0 + xi[i])  *  (1.0 - zeta[i]);
                        dN_deta[3][i] =  1.0/8.0  *  (1.0 - xi[i])  *  (1.0 - zeta[i]);
                        dN_deta[4][i] = -1.0/8.0  *  (1.0 - xi[i])  *  (1.0 + zeta[i]);
                        dN_deta[5][i] = -1.0/8.0  *  (1.0 + xi[i])  *  (1.0 + zeta[i]);
                        dN_deta[6][i] =  1.0/8.0  *  (1.0 + xi[i])  *  (1.0 + zeta[i]);
                        dN_deta[7][i] =  1.0/8.0  *  (1.0 - xi[i])  *  (1.0 + zeta[i]);

                        dN_dzeta[0][i] = -1.0/8.0  *  (1.0 - xi[i])  *  (1.0 - eta[i]);
                        dN_dzeta[1][i] = -1.0/8.0  *  (1.0 + xi[i])  *  (1.0 - eta[i]);
                        dN_dzeta[2][i] = -1.0/8.0  *  (1.0 + xi[i])  *  (1.0 + eta[i]);
                        dN_dzeta[3][i] = -1.0/8.0  *  (1.0 - xi[i])  *  (1.0 + eta[i]);
                        dN_dzeta[4][i] =  1.0/8.0  *  (1.0 - xi[i])  *  (1.0 - eta[i]);
                        dN_dzeta[5][i] =  1.0/8.0  *  (1.0 + xi[i])  *  (1.0 - eta[i]);
                        dN_dzeta[6][i] =  1.0/8.0  *  (1.0 + xi[i])  *  (1.0 + eta[i]);
                        dN_dzeta[7][i] =  1.0/8.0  *  (1.0 - xi[i])  *  (1.0 + eta[i]);
                    }
                    break;
                case 2 :
                    N.resize(27, std::vector<double>(NGP));
                    dN_dxi.resize(27, std::vector<double>(NGP));
                    dN_deta.resize(27, std::vector<double>(NGP));
                    dN_dzeta.resize(27, std::vector<double>(NGP));

                    for (int i = 0; i < (NGP); i++)
                    {
                        N[0][i]  =  (1.0/8.0) * (xi[i])    *  (xi[i]-1.0)  *  eta[i]    *  (eta[i] - 1.0)  *  (zeta[i])    *  (zeta[i]-1.0);
                        N[1][i]  =  (1.0/8.0) * (xi[i])    *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] - 1.0)  *  (zeta[i])    *  (zeta[i]-1.0);
                        N[2][i]  =  (1.0/8.0) * (xi[i])    *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]-1.0);
                        N[3][i]  =  (1.0/8.0) * (xi[i])    *  (xi[i]-1.0)  *  eta[i]    *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]-1.0);
                        N[4][i]  =  (1.0/8.0) * (xi[i])    *  (xi[i]-1.0)  *  eta[i]    *  (eta[i] - 1.0)  *  (zeta[i])    *  (zeta[i]+1.0);
                        N[5][i]  =  (1.0/8.0) * (xi[i])    *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] - 1.0)  *  (zeta[i])    *  (zeta[i]+1.0);
                        N[6][i]  =  (1.0/8.0) * (xi[i])    *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]+1.0);
                        N[7][i]  =  (1.0/8.0) * (xi[i])    *  (xi[i]-1.0)  *  eta[i]    *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]+1.0);
                        N[8][i]  = -(1.0/4.0) * (xi[i]-1.0)  *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] - 1.0)  *  (zeta[i])    *  (zeta[i]-1.0);
                        N[9][i] = -(1.0/4.0) * (xi[i])    *  (xi[i]+1.0)  *  (eta[i] - 1.0)  *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]-1.0);
                        N[10][i] = -(1.0/4.0) * (xi[i]-1.0)  *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]-1.0);
                        N[11][i] = -(1.0/4.0) * (xi[i])    *  (xi[i]-1.0)  *  (eta[i] - 1.0)  *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]-1.0);
                        N[12][i] = -(1.0/4.0) * (xi[i])    *  (xi[i]-1.0)  *  eta[i]    *  (eta[i] - 1.0)  *  (zeta[i]-1.0)  *  (zeta[i]+1.0);
                        N[13][i] = -(1.0/4.0) * (xi[i])    *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] - 1.0)  *  (zeta[i]-1.0)  *  (zeta[i]+1.0);
                        N[14][i] = -(1.0/4.0) * (xi[i])    *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] + 1.0)  *  (zeta[i]-1.0)  *  (zeta[i]+1.0);
                        N[15][i] = -(1.0/4.0) * (xi[i])    *  (xi[i]-1.0)  *  eta[i]    *  (eta[i] + 1.0)  *  (zeta[i]-1.0)  *  (zeta[i]+1.0);
                        N[16][i] = -(1.0/4.0) * (xi[i]-1.0)  *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] - 1.0)  *  (zeta[i])    *  (zeta[i]+1.0);
                        N[17][i] = -(1.0/4.0) * (xi[i])    *  (xi[i]+1.0)  *  (eta[i] - 1.0)  *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]+1.0);
                        N[18][i] = -(1.0/4.0) * (xi[i]-1.0)  *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]+1.0);
                        N[19][i] = -(1.0/4.0) * (xi[i])    *  (xi[i]-1.0)  *  (eta[i] - 1.0)  *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]+1.0);
                        N[20][i] =  (1.0/2.0) * (xi[i]-1.0)  *  (xi[i]+1.0)  *  (eta[i] - 1.0)  *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]-1.0);
                        N[21][i] =  (1.0/2.0) * (xi[i]-1.0)  *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] - 1.0)  *  (zeta[i]-1.0)  *  (zeta[i]+1.0);
                        N[22][i] =  (1.0/2.0) * (xi[i])    *  (xi[i]+1.0)  *  (eta[i] - 1.0)  *  (eta[i] + 1.0)  *  (zeta[i]-1.0)  *  (zeta[i]+1.0);
                        N[23][i] =  (1.0/2.0) * (xi[i]-1.0)  *  (xi[i]+1.0)  *  eta[i]    *  (eta[i] + 1.0)  *  (zeta[i]-1.0)  *  (zeta[i]+1.0);
                        N[24][i] =  (1.0/2.0) * (xi[i])    *  (xi[i]-1.0)  *  (eta[i] - 1.0)  *  (eta[i] + 1.0)  *  (zeta[i]-1.0)  *  (zeta[i]+1.0);
                        N[25][i] =  (1.0/2.0) * (xi[i]-1.0)  *  (xi[i]+1.0)  *  (eta[i] - 1.0)  *  (eta[i] + 1.0)  *  (zeta[i])    *  (zeta[i]+1.0);
                        N[26][i] = - (1.0)  * (xi[i]-1.0)  *  (xi[i]+1.0)  *  (eta[i] - 1.0)  *  (eta[i] + 1.0)  *  (zeta[i]-1.0)  *  (zeta[i]+1.0);

                        dN_dxi[0][i]  =  (eta[i]* zeta[i] * (2 * xi[i] - 1.0) * (eta[i]- 1.0) * (zeta[i] - 1.0))/8.0;
                        dN_dxi[1][i]  =  (eta[i]* zeta[i] * (2 * xi[i] + 1.0) * (eta[i]- 1.0) * (zeta[i] - 1.0))/8.0;
                        dN_dxi[2][i]  =  (eta[i]* zeta[i] * (2 * xi[i] + 1.0) * (eta[i]+ 1.0) * (zeta[i] - 1.0))/8.0;
                        dN_dxi[3][i]  =  (eta[i]* zeta[i] * (2 * xi[i] - 1.0) * (eta[i]+ 1.0) * (zeta[i] - 1.0))/8.0;
                        dN_dxi[4][i]  =  (eta[i]* zeta[i] * (2 * xi[i] - 1.0) * (eta[i]- 1.0) * (zeta[i] + 1.0))/8.0;
                        dN_dxi[5][i]  =  (eta[i]* zeta[i] * (2 * xi[i] + 1.0) * (eta[i]- 1.0) * (zeta[i] + 1.0))/8.0;
                        dN_dxi[6][i]  =  (eta[i]* zeta[i] * (2 * xi[i] + 1.0) * (eta[i]+ 1.0) * (zeta[i] + 1.0))/8.0;
                        dN_dxi[7][i]  =  (eta[i]* zeta[i] * (2 * xi[i] - 1.0) * (eta[i]+ 1.0) * (zeta[i] + 1.0))/8.0;
                        dN_dxi[8][i]  = -(eta[i]* xi[i] * zeta[i] * (eta[i]- 1.0) * (zeta[i] - 1.0))/2.0;
                        dN_dxi[9][i] = -(zeta[i] * (std::pow(eta[i], 2) - 1.0) * (2 * xi[i] + 1.0) * (zeta[i] - 1.0))/4.0;
                        dN_dxi[10][i] = -(eta[i]* xi[i] * zeta[i] * (eta[i]+ 1.0) * (zeta[i] - 1.0))/2.0;
                        dN_dxi[11][i] = -(zeta[i] * (std::pow(eta[i], 2) - 1.0) * (2 * xi[i] - 1.0) * (zeta[i] - 1.0))/4.0;
                        dN_dxi[12][i] = -(eta[i]* (2 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 1.0) * (eta[i]- 1.0))/4.0;
                        dN_dxi[13][i] = -(eta[i]* (2 * xi[i] + 1.0) * (std::pow(zeta[i], 2) - 1.0) * (eta[i]- 1.0))/4.0;
                        dN_dxi[14][i] = -(eta[i]* (2 * xi[i] + 1.0) * (std::pow(zeta[i], 2) - 1.0) * (eta[i]+ 1.0))/4.0;
                        dN_dxi[15][i] = -(eta[i]* (2 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 1.0) * (eta[i]+ 1.0))/4.0;
                        dN_dxi[16][i] = -(eta[i]* xi[i] * zeta[i] * (eta[i]- 1.0) * (zeta[i] + 1.0))/2.0;
                        dN_dxi[17][i] = -(zeta[i] * (std::pow(eta[i], 2) - 1.0) * (2 * xi[i] + 1.0) * (zeta[i] + 1.0))/4.0;
                        dN_dxi[18][i] = -(eta[i]* xi[i] * zeta[i] * (eta[i]+ 1.0) * (zeta[i] + 1.0))/2.0;
                        dN_dxi[19][i] = -(zeta[i] * (std::pow(eta[i], 2) - 1.0) * (2 * xi[i] - 1.0) * (zeta[i] + 1.0))/4.0;
                        dN_dxi[20][i] = xi[i] * zeta[i] * (std::pow(eta[i], 2) - 1.0) * (zeta[i] - 1.0);
                        dN_dxi[21][i] = eta[i]* xi[i] * (std::pow(zeta[i], 2) - 1.0) * (eta[i]- 1.0);
                        dN_dxi[22][i] = ((std::pow(eta[i], 2) - 1.0) * (2 * xi[i] + 1.0) * (std::pow(zeta[i], 2) - 1.0))/2.0;
                        dN_dxi[23][i] = eta[i]* xi[i] * (std::pow(zeta[i], 2) - 1.0) * (eta[i]+ 1.0);
                        dN_dxi[24][i] = ((std::pow(eta[i], 2) - 1.0) * (2 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 1.0))/2.0;
                        dN_dxi[25][i] = xi[i] * zeta[i] * (std::pow(eta[i], 2) - 1.0) * (zeta[i] + 1.0);
                        dN_dxi[26][i] = -2 * xi[i] * (std::pow(eta[i], 2) - 1.0) * (std::pow(zeta[i], 2) - 1.0);

                        dN_deta[0][i]  =  (xi[i] * zeta[i] * (2 * eta[i]- 1.0) * (xi[i] - 1.0) * (zeta[i] - 1.0))/8.0;
                        dN_deta[1][i]  =  (xi[i] * zeta[i] * (2 * eta[i]- 1.0) * (xi[i] + 1.0) * (zeta[i] - 1.0))/8.0;
                        dN_deta[2][i]  =  (xi[i] * zeta[i] * (2 * eta[i]+ 1.0) * (xi[i] + 1.0) * (zeta[i] - 1.0))/8.0;
                        dN_deta[3][i]  =  (xi[i] * zeta[i] * (2 * eta[i]+ 1.0) * (xi[i] - 1.0) * (zeta[i] - 1.0))/8.0;
                        dN_deta[4][i]  =  (xi[i] * zeta[i] * (2 * eta[i]- 1.0) * (xi[i] - 1.0) * (zeta[i] + 1.0))/8.0;
                        dN_deta[5][i]  =  (xi[i] * zeta[i] * (2 * eta[i]- 1.0) * (xi[i] + 1.0) * (zeta[i] + 1.0))/8.0;
                        dN_deta[6][i]  =  (xi[i] * zeta[i] * (2 * eta[i]+ 1.0) * (xi[i] + 1.0) * (zeta[i] + 1.0))/8.0;
                        dN_deta[7][i]  =  (xi[i] * zeta[i] * (2 * eta[i]+ 1.0) * (xi[i] - 1.0) * (zeta[i] + 1.0))/8.0;
                        dN_deta[8][i]  = -(zeta[i] * (2 * eta[i]- 1.0) * (std::pow(xi[i], 2) - 1.0) * (zeta[i] - 1.0))/4.0;
                        dN_deta[9][i] = -(eta[i]* xi[i] * zeta[i] * (xi[i] + 1.0) * (zeta[i] - 1.0))/2.0;
                        dN_deta[10][i] = -(zeta[i] * (2 * eta[i]+ 1.0) * (std::pow(xi[i], 2) - 1.0) * (zeta[i] - 1.0))/4.0;
                        dN_deta[11][i] = -(eta[i]* xi[i] * zeta[i] * (xi[i] - 1.0) * (zeta[i] - 1.0))/2.0;
                        dN_deta[12][i] = -(xi[i] * (2 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 1.0) * (xi[i] - 1.0))/4.0;
                        dN_deta[13][i] = -(xi[i] * (2 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 1.0) * (xi[i] + 1.0))/4.0;
                        dN_deta[14][i] = -(xi[i] * (2 * eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 1.0) * (xi[i] + 1.0))/4.0;
                        dN_deta[15][i] = -(xi[i] * (2 * eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 1.0) * (xi[i] - 1.0))/4.0;
                        dN_deta[16][i] = -(zeta[i] * (2 * eta[i]- 1.0) * (std::pow(xi[i], 2) - 1.0) * (zeta[i] + 1.0))/4.0;
                        dN_deta[17][i] = -(eta[i]* xi[i] * zeta[i] * (xi[i] + 1.0) * (zeta[i] + 1.0))/2.0;
                        dN_deta[18][i] = -(zeta[i] * (2 * eta[i]+ 1.0) * (std::pow(xi[i], 2) - 1.0) * (zeta[i] + 1.0))/4.0;
                        dN_deta[19][i] = -(eta[i]* xi[i] * zeta[i] * (xi[i] - 1.0) * (zeta[i] + 1.0))/2.0;
                        dN_deta[20][i] = eta[i]* zeta[i] * (std::pow(xi[i], 2) - 1.0) * (zeta[i] - 1.0);
                        dN_deta[21][i] = ((2 * eta[i]- 1.0) * (std::pow(xi[i], 2) - 1.0) * (std::pow(zeta[i], 2) - 1.0))/2.0;
                        dN_deta[22][i] = eta[i]* xi[i] * (std::pow(zeta[i], 2) - 1.0) * (xi[i] + 1.0);
                        dN_deta[23][i] = ((2 * eta[i]+ 1.0) * (std::pow(xi[i], 2) - 1.0) * (std::pow(zeta[i], 2) - 1.0))/2.0;
                        dN_deta[24][i] = eta[i]* xi[i] * (std::pow(zeta[i], 2) - 1.0) * (xi[i] - 1.0);
                        dN_deta[25][i] = eta[i]* zeta[i] * (std::pow(xi[i], 2) - 1.0) * (zeta[i] + 1.0);
                        dN_deta[26][i] = -2 * eta[i]* (std::pow(xi[i], 2) - 1.0) * (std::pow(zeta[i], 2) - 1.0);

                        dN_dzeta[0][i]  =  (eta[i]* xi[i] * (2 * zeta[i] - 1.0) * (eta[i]- 1.0) * (xi[i] - 1.0))/8.0;
                        dN_dzeta[1][i]  =  (eta[i]* xi[i] * (2 * zeta[i] - 1.0) * (eta[i]- 1.0) * (xi[i] + 1.0))/8.0;
                        dN_dzeta[2][i]  =  (eta[i]* xi[i] * (2 * zeta[i] - 1.0) * (eta[i]+ 1.0) * (xi[i] + 1.0))/8.0;
                        dN_dzeta[3][i]  =  (eta[i]* xi[i] * (2 * zeta[i] - 1.0) * (eta[i]+ 1.0) * (xi[i] - 1.0))/8.0;
                        dN_dzeta[4][i]  =  (eta[i]* xi[i] * (2 * zeta[i] + 1.0) * (eta[i]- 1.0) * (xi[i] - 1.0))/8.0;
                        dN_dzeta[5][i]  =  (eta[i]* xi[i] * (2 * zeta[i] + 1.0) * (eta[i]- 1.0) * (xi[i] + 1.0))/8.0;
                        dN_dzeta[6][i]  =  (eta[i]* xi[i] * (2 * zeta[i] + 1.0) * (eta[i]+ 1.0) * (xi[i] + 1.0))/8.0;
                        dN_dzeta[7][i]  =  (eta[i]* xi[i] * (2 * zeta[i] + 1.0) * (eta[i]+ 1.0) * (xi[i] - 1.0))/8.0;
                        dN_dzeta[8][i]  = -(eta[i]* (std::pow(xi[i], 2) - 1.0) * (2 * zeta[i] - 1.0) * (eta[i]- 1.0))/4.0;
                        dN_dzeta[9][i] = -(xi[i] * (std::pow(eta[i], 2) - 1.0) * (2 * zeta[i] - 1.0) * (xi[i] + 1.0))/4.0;
                        dN_dzeta[10][i] = -(eta[i]* (std::pow(xi[i], 2) - 1.0) * (2 * zeta[i] - 1.0) * (eta[i]+ 1.0))/4.0;
                        dN_dzeta[11][i] = -(xi[i] * (std::pow(eta[i], 2) - 1.0) * (2 * zeta[i] - 1.0) * (xi[i] - 1.0))/4.0;
                        dN_dzeta[12][i] = -(eta[i]* xi[i] * zeta[i] * (eta[i]- 1.0) * (xi[i] - 1.0))/2.0;
                        dN_dzeta[13][i] = -(eta[i]* xi[i] * zeta[i] * (eta[i]- 1.0) * (xi[i] + 1.0))/2.0;
                        dN_dzeta[14][i] = -(eta[i]* xi[i] * zeta[i] * (eta[i]+ 1.0) * (xi[i] + 1.0))/2.0;
                        dN_dzeta[15][i] = -(eta[i]* xi[i] * zeta[i] * (eta[i]+ 1.0) * (xi[i] - 1.0))/2.0;
                        dN_dzeta[16][i] = -(eta[i]* (std::pow(xi[i], 2) - 1.0) * (2 * zeta[i] + 1.0) * (eta[i]- 1.0))/4.0;
                        dN_dzeta[17][i] = -(xi[i] * (std::pow(eta[i], 2) - 1.0) * (2 * zeta[i] + 1.0) * (xi[i] + 1.0))/4.0;
                        dN_dzeta[18][i] = -(eta[i]* (std::pow(xi[i], 2) - 1.0) * (2 * zeta[i] + 1.0) * (eta[i]+ 1.0))/4.0;
                        dN_dzeta[19][i] = -(xi[i] * (std::pow(eta[i], 2) - 1.0) * (2 * zeta[i] + 1.0) * (xi[i] - 1.0))/4.0;
                        dN_dzeta[20][i] = ((std::pow(eta[i], 2) - 1.0) * (std::pow(xi[i], 2) - 1.0) * (2 * zeta[i] - 1.0))/2.0;
                        dN_dzeta[21][i] = eta[i]* zeta[i] * (std::pow(xi[i], 2) - 1.0) * (eta[i]- 1.0);
                        dN_dzeta[22][i] = xi[i] * zeta[i] * (std::pow(eta[i], 2) - 1.0) * (xi[i] + 1.0);
                        dN_dzeta[23][i] = eta[i]* zeta[i] * (std::pow(xi[i], 2) - 1.0) * (eta[i]+ 1.0);
                        dN_dzeta[24][i] = xi[i] * zeta[i] * (std::pow(eta[i], 2) - 1.0) * (xi[i] - 1.0);
                        dN_dzeta[25][i] = ((std::pow(eta[i], 2) - 1.0) * (std::pow(xi[i], 2) - 1.0) * (2 * zeta[i] + 1.0))/2.0;
                        dN_dzeta[26][i] = -2 * zeta[i] * (std::pow(eta[i], 2) - 1.0) * (std::pow(xi[i], 2) - 1.0);
                    }
                    break;
                case 3:
                    N.resize(64, std::vector<double>(NGP)); // Assuming N has 16 rows, adjust as necessary
                    dN_dxi.resize(64, std::vector<double>(NGP));
                    dN_deta.resize(64, std::vector<double>(NGP));
                    dN_dzeta.resize(64, std::vector<double>(NGP));

                    for (int i =0; i<64; i++)
                    {
                        N[0][i]  = -((9* eta[i])/16.0 + 3.0/16.0)   *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[1][i]  =  ((9* eta[i])/16.0 + 3.0/16.0)   *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[2][i]  = -((9* eta[i])/16.0 + 9.0/16.0)   *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[3][i]  =  ((9* eta[i])/16.0 + 9.0/16.0)   *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[4][i]  =  ((9* eta[i])/16.0 + 3.0/16.0)   *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[5][i]  = -((9* eta[i])/16.0 + 3.0/16.0)   *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[6][i]  =  ((9* eta[i])/16.0 + 9.0/16.0)   *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[7][i]  = -((9* eta[i])/16.0 + 9.0/16.0)   *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[8][i]  =  ((9* eta[i])/16.0 + 3.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[9][i] = -((9* eta[i])/16.0 + 3.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[10][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[11][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[12][i] =  ((9* eta[i])/16.0 + 9.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[13][i] = -((9* eta[i])/16.0 + 9.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[14][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[15][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[16][i] =  ((9* eta[i])/16.0 + 3.0/16.0)   *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[17][i] = -((9* eta[i])/16.0 + 3.0/16.0)   *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[18][i] = -((9* eta[i])/16.0 + 3.0/16.0)   *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[19][i] =  ((9* eta[i])/16.0 + 3.0/16.0)   *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[20][i] =  ((9* eta[i])/16.0 + 9.0/16.0)   *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[21][i] = -((9* eta[i])/16.0 + 9.0/16.0)   *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[22][i] = -((9* eta[i])/16.0 + 9.0/16.0)   *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[23][i] =  ((9* eta[i])/16.0 + 9.0/16.0)   *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[24][i] = -((9* eta[i])/16.0 + 3.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[25][i] =  ((9* eta[i])/16.0 + 3.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[26][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[27][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[28][i] = -((9* eta[i])/16.0 + 9.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[29][i] =  ((9* eta[i])/16.0 + 9.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[30][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[31][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[32][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[33][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[34][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[35][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 3.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[36][i] = -((9* eta[i])/16.0 + 3.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[37][i] =  ((9* eta[i])/16.0 + 3.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[38][i] = -((9* eta[i])/16.0 + 3.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[39][i] =  ((9* eta[i])/16.0 + 3.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[40][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[41][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[42][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[43][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 9.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0/3.0)  *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[44][i] = -((9* eta[i])/16.0 + 9.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[45][i] =  ((9* eta[i])/16.0 + 9.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[46][i] = -((9* eta[i])/16.0 + 9.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[47][i] =  ((9* eta[i])/16.0 + 9.0/16.0)   *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0/3.0)  *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[48][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[49][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[50][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[51][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((9*xi[i])/16.0 + 3.0/16.0)   *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[52][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[53][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[54][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[55][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((9*zeta[i])/16.0 + 9.0/16.0)   *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0/3.0)  *  (zeta[i] + 1.0/3.0);
                        N[56][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[57][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[58][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[59][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] - 1.0/3.0);
                        N[60][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[61][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]- 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[62][i] = -((27* eta[i])/16.0+ 27.0/16.0)  *  ((27*xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] + 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);
                        N[63][i] =  ((27* eta[i])/16.0+ 27.0/16.0)  *  ((27 *xi[i])/16.0+ 27.0/16.0)  *  ((27*zeta[i])/16.0+ 27.0/16.0)  *  (eta[i]- 1.0)    *  (eta[i]+ 1.0/3.0)  *  (xi[i] - 1.0)    *  (xi[i] - 1.0/3.0)  *  (zeta[i] - 1.0)    *  (zeta[i] + 1.0/3.0);

                        dN_dxi[0][i]  =  ((- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[1][i]  =  ((27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[2][i]  = -((27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[3][i]  = -((- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[4][i]  = -((- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[5][i]  = -((27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[6][i]  =  ((27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[7][i]  =  ((- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[8][i]  = -(9 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[9][i] = -(9 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[10][i] = -(9 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[11][i] =  (9 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[12][i] =  (9 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[13][i] =  (9 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[14][i] =  (9 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[15][i] = -(9 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[16][i] = -(9 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[17][i] =  (9 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[18][i] = -(9 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[19][i] =  (9 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[20][i] =  (9 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[21][i] = -(9 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[22][i] =  (9 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[23][i] = -(9 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[24][i] =  (9 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[25][i] =  (9 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[26][i] =  (9 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[27][i] = -(9 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[28][i] = -(9 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[29][i] = -(9 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[30][i] = -(9 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[31][i] =  (9 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[32][i] =  (81 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[33][i] =  (81 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[34][i] = -(81 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[35][i] = -(81 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[36][i] =  (81 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[37][i] =  (81 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[38][i] = -(81 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[39][i] = -(81 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[40][i] =  (81 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[41][i] = -(81 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[42][i] =  (81 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[43][i] = -(81 * (27 * std::pow(xi[i], 2) + 18 * xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[44][i] = -(81 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[45][i] = -(81 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[46][i] =  (81 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[47][i] =  (81 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[48][i] = -(81 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[49][i] =  (81 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[50][i] = -(81 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[51][i] =  (81 * (- 27 * std::pow(xi[i], 2) + 18 * xi[i] + 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[52][i] = -(81 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[53][i] = -(81 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[54][i] =  (81 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[55][i] =  (81 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[56][i] = -(729 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[57][i] = -(729 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0 ;
                        dN_dxi[58][i] =  (729 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[59][i] =  (729 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0 ;
                        dN_dxi[60][i] =  (729 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[61][i] =  (729 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[62][i] = -(729 * (9 * std::pow(xi[i], 2) + 2 * xi[i] - 3.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;
                        dN_dxi[63][i] = -(729 * (- 9 * std::pow(xi[i], 2) + 2 * xi[i] + 3.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0 ;

                        dN_deta[0][i]  =  ((- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[1][i]  = -((- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[2][i]  = -((27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[3][i]  =  ((27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[4][i]  = -((- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[5][i]  =  ((- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[6][i]  =  ((27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[7][i]  = -((27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[8][i]  = -(9 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[9][i] =  (9 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[10][i] =  (9 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[11][i] =  (9 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[12][i] =  (9 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[13][i] = -(9 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[14][i] = -(9 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[15][i] = -(9 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[16][i] = -(9 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[17][i] =  (9 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[18][i] =  (9 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[19][i] = -(9 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[20][i] =  (9 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[21][i] = -(9 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[22][i] = -(9 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[23][i] =  (9 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[24][i] =  (9 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[25][i] = -(9 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[26][i] = -(9 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[27][i] = -(9 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[28][i] = -(9 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[29][i] =  (9 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[30][i] =  (9 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[31][i] =  (9 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[32][i] =  (81 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[33][i] = -(81 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[34][i] = -(81 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[35][i] =  (81 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/4096.0;
                        dN_deta[36][i] =  (81 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[37][i] = -(81 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[38][i] =  (81 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[39][i] = -(81 * (- 27 * std::pow(eta[i], 2) + 18 * eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[40][i] = -(81 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[41][i] = -(81 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[42][i] =  (81 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[43][i] =  (81 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[44][i] = -(81 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[45][i] =  (81 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[46][i] = -(81 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[47][i] =  (81 * (27 * std::pow(eta[i], 2) + 18 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[48][i] =  (81 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[49][i] =  (81 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[50][i] = -(81 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[51][i] = -(81 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[52][i] = -(81 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[53][i] =  (81 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[54][i] =  (81 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[55][i] = -(81 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (zeta[i] - 9 * std::pow(zeta[i], 2) - 9 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[56][i] = -(729 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[57][i] =  (729 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[58][i] =  (729 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_deta[59][i] = -(729 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 3 * zeta[i] - 1.0))/4096.0;
                        dN_deta[60][i] =  (729 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[61][i] = -(729 * (- 9 * std::pow(eta[i], 2) + 2 * eta[i]+ 3.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[62][i] = -(729 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;
                        dN_deta[63][i] =  (729 * (9 * std::pow(eta[i], 2) + 2 * eta[i]- 3.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (3 * zeta[i] - std::pow(zeta[i], 2) - 3 * std::pow(zeta[i], 3) + 1.0))/4096.0;

                        dN_dzeta[0][i]  =  ((18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[1][i]  = -((18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[2][i]  =  ((18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[3][i]  = -((18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[4][i]  =  ((27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[5][i]  = -((27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[6][i]  =  ((27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[7][i]  = -((27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[8][i]  = -(9 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[9][i] =  (9 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[10][i] =  (9 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[11][i] = -(9 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;
                        dN_dzeta[12][i] = -(9 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[13][i] =  (9 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[14][i] =  (9 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;
                        dN_dzeta[15][i] = -(9 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[16][i] = -(9 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[17][i] = -(9 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[18][i] =  (9 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[19][i] =  (9 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[20][i] = -(9 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[21][i] = -(9 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[22][i] =  (9 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[23][i] =  (9 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[24][i] = -(9 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[25][i] =  (9 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[26][i] =  (9 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[27][i] = -(9 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;
                        dN_dzeta[28][i] = -(9 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[29][i] =  (9 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[30][i] =  (9 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;
                        dN_dzeta[31][i] = -(9 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[32][i] =  (81 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[33][i] = -(81 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[34][i] =  (81 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[35][i] = -(81 * (18 * zeta[i] - 27 * std::pow(zeta[i], 2) + 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;
                        dN_dzeta[36][i] =  (81 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[37][i] = -(81 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[38][i] = -(81 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[39][i] =  (81 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 9 * std::pow(eta[i], 3) + 9 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[40][i] = -(81 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[41][i] =  (81 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;
                        dN_dzeta[42][i] =  (81 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;
                        dN_dzeta[43][i] = -(81 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) - 9 * std::pow(xi[i], 2) + xi[i] + 1.0))/4096.0;
                        dN_dzeta[44][i] =  (81 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[45][i] = -(81 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[46][i] = -(81 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[47][i] =  (81 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 9 * std::pow(eta[i], 3) - 9 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[48][i] = -(81 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;
                        dN_dzeta[49][i] =  (81 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[50][i] =  (81 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0))/4096.0;
                        dN_dzeta[51][i] = -(81 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 9 * std::pow(xi[i],3) + 9 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;
                        dN_dzeta[52][i] =  (81 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[53][i] = -(81 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[54][i] =  (81 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[55][i] = -(81 * (27 * std::pow(zeta[i], 2) + 18 * zeta[i] - 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;
                        dN_dzeta[56][i] = -(729 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[57][i] =  (729 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[58][i] = -(729 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[59][i] =  (729 * (2 * zeta[i] - 9 * std::pow(zeta[i], 2) + 3.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;
                        dN_dzeta[60][i] = -(729 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0))/4096.0;
                        dN_dzeta[61][i] =  (729 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 3 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 3 * eta[i]- 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[62][i] = -(729 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0) * (- 3 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 3 * xi[i] + 1.0))/4096.0;
                        dN_dzeta[63][i] =  (729 * (9 * std::pow(zeta[i], 2) + 2 * zeta[i] - 3.0) * (- 3 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 3 * xi[i] - 1.0) * (- 3 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 3 * eta[i]+ 1.0))/4096.0;

                    }
                    break;

                    case 4:
                        N.resize(125, std::vector<double>(NGP));
                    dN_dxi.resize(125, std::vector<double>(NGP));
                    dN_deta.resize(125, std::vector<double>(NGP));
                    dN_dzeta.resize(125, std::vector<double>(NGP));

                    for (int i = 0; i < NGP; i++)
                    {
                        N[0][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[1][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[2][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[3][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[4][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[5][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[6][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[7][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[8][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[9][i] = eta[i]* zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * (4 * xi[i] + 4.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[10][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[11][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[12][i] = xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[13][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[14][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[15][i] = eta[i]* zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * (4 * xi[i] + 4.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[16][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[17][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[18][i] = xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[19][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[20][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[21][i] = eta[i]* xi[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[22][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[23][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[24][i] = eta[i]* xi[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[25][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[26][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[27][i] = eta[i]* xi[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[28][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[29][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[30][i] = eta[i]* xi[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((2 * xi[i])/3.0 + 1.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[31][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[32][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[33][i] = eta[i]* zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * (4 * xi[i] + 4.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[34][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[35][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[36][i] = xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[37][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[38][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[39][i] = eta[i]* zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * (4 * xi[i] + 4.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[40][i] = -eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[41][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[42][i] = xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[43][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[44][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[45][i] = -eta[i]* zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * (4 * xi[i] + 4.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[46][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[47][i] = -xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[48][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[49][i] = -eta[i]* zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * (4 * xi[i] + 4.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[50][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[51][i] = -xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[52][i] = zeta[i] * (4 * eta[i]+ 4.0) * (4 * xi[i] + 4.0) * ((2 * zeta[i])/3.0 + 1.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[53][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[54][i] = -eta[i]* zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * (4 * xi[i] + 4.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[55][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[56][i] = -eta[i]* xi[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[57][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[58][i] = -eta[i]* zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * (4 * xi[i] + 4.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[59][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[60][i] = -eta[i]* xi[i] * ((2 * eta[i])/3.0 + 1.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[61][i] = eta[i]* ((2 * eta[i])/3.0 + 1.0/3.0) * (4 * xi[i] + 4.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[62][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[63][i] = -xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[64][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[65][i] = -eta[i]* xi[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[66][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[67][i] = -xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[68][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[69][i] = -eta[i]* xi[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[70][i] = xi[i] * (4 * eta[i]+ 4.0) * ((2 * xi[i])/3.0 + 2.0/3.0 ) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[71][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[72][i] = -eta[i]* zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * (4 * xi[i] + 4.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[73][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[74][i] = -eta[i]* xi[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((8 * xi[i])/3.0 + 8.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[75][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[76][i] = -eta[i]* zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * (4 * xi[i] + 4.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[77][i] = eta[i]* xi[i] * zeta[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[78][i] = -eta[i]* xi[i] * ((2 * eta[i])/3.0 + 2.0/3.0 ) * ((8 * xi[i])/3.0 + 8.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[79][i] = eta[i]* ((2 * eta[i])/3.0 + 2.0/3.0 ) * (4 * xi[i] + 4.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[80][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[81][i] = -xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[82][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[83][i] = -eta[i]* xi[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[84][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[85][i] = -xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[86][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[87][i] = -eta[i]* xi[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[88][i] = xi[i] * (4 * eta[i]+ 4.0) * ((2 * xi[i])/3.0 + 1.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[89][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[90][i] = -eta[i]* zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * (4 * xi[i] + 4.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[91][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[92][i] = -xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[93][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[94][i] = -eta[i]* zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * (4 * xi[i] + 4.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[95][i] = eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[96][i] = -xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[97][i] = zeta[i] * (4 * eta[i]+ 4.0) * (4 * xi[i] + 4.0) * ((2 * zeta[i])/3.0 + 2.0/3.0 ) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[98][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[99][i] = eta[i]* zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * (4 * xi[i] + 4.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[100][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[101][i] = xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[102][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[103][i] = eta[i]* zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * (4 * xi[i] + 4.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[104][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[105][i] = xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[106][i] = eta[i]* xi[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[107][i] = -eta[i]* ((8 * eta[i])/3.0 + 8.0/3.0) * (4 * xi[i] + 4.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[108][i] = eta[i]* xi[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[109][i] = -xi[i] * (4 * eta[i]+ 4.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[110][i] = eta[i]* xi[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[111][i] = -eta[i]* ((8 * eta[i])/3.0 + 8.0/3.0) * (4 * xi[i] + 4.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[112][i] = eta[i]* xi[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[113][i] = -xi[i] * (4 * eta[i]+ 4.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);
                        N[114][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[115][i] = eta[i]* zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * (4 * xi[i] + 4.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[116][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[117][i] = xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[118][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[119][i] = eta[i]* zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * (4 * xi[i] + 4.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[120][i] = -eta[i]* xi[i] * zeta[i] * ((8 * eta[i])/3.0 + 8.0/3.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[121][i] = xi[i] * zeta[i] * (4 * eta[i]+ 4.0) * ((8 * xi[i])/3.0 + 8.0/3.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[122][i] = -zeta[i] * (4 * eta[i]+ 4.0) * (4 * xi[i] + 4.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0);
                        N[123][i] = -zeta[i] * (4 * eta[i]+ 4.0) * (4 * xi[i] + 4.0) * ((8 * zeta[i])/3.0 + 8.0/3.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] + 1.0/2.0);
                        N[124][i] = (4 * eta[i]+ 4.0) * (4 * xi[i] + 4.0) * (4 * zeta[i] + 4.0) * (eta[i]- 1.0) * (eta[i]- 1.0/2.0) * (eta[i]+ 1.0/2.0) * (xi[i] - 1.0) * (xi[i] - 1.0/2.0) * (xi[i] + 1.0/2.0) * (zeta[i] - 1.0) * (zeta[i] - 1.0/2.0) * (zeta[i] + 1.0/2.0);



                        dN_dxi[0][i] = -(eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/216 ;
                        dN_dxi[1][i] = -(eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/216 ;
                        dN_dxi[2][i] = -(eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/216 ;
                        dN_dxi[3][i] = -(eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/216 ;
                        dN_dxi[4][i] = -(eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/216 ;
                        dN_dxi[5][i] = -(eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/216 ;
                        dN_dxi[6][i] = -(eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/216 ;
                        dN_dxi[7][i] = -(eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/216 ;
                        dN_dxi[8][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[9][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/18 ;
                        dN_dxi[10][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[11][i] = (eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27 ;
                        dN_dxi[12][i] = (zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/36.0 ;
                        dN_dxi[13][i] = (eta[i]* zeta[i] * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27 ;
                        dN_dxi[14][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[15][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/18 ;
                        dN_dxi[16][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[17][i] = (eta[i]* zeta[i] * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/27 ;
                        dN_dxi[18][i] = (zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/36.0 ;
                        dN_dxi[19][i] = (eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/27 ;
                        dN_dxi[20][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/27 ;
                        dN_dxi[21][i] = (eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/36.0 ;
                        dN_dxi[22][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[23][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27 ;
                        dN_dxi[24][i] = (eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/36.0 ;
                        dN_dxi[25][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[26][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27 ;
                        dN_dxi[27][i] = (eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/36.0 ;
                        dN_dxi[28][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[29][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/27 ;
                        dN_dxi[30][i] = (eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/36.0 ;
                        dN_dxi[31][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[32][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[33][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0))/18 ;
                        dN_dxi[34][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[35][i] = (eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27 ;
                        dN_dxi[36][i] = (zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/36.0 ;
                        dN_dxi[37][i] = (eta[i]* zeta[i] * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27 ;
                        dN_dxi[38][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[39][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0))/18 ;
                        dN_dxi[40][i] = (eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[41][i] = (eta[i]* zeta[i] * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/27 ;
                        dN_dxi[42][i] = (zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/36.0 ;
                        dN_dxi[43][i] = (eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/27 ;
                        dN_dxi[44][i] = -(8 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[45][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/9 ;
                        dN_dxi[46][i] = -(8 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[47][i] = -(2 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/9 ;
                        dN_dxi[48][i] = -(8 * eta[i]* zeta[i] * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[49][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/9 ;
                        dN_dxi[50][i] = -(8 * eta[i]* zeta[i] * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[51][i] = -(2 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/9 ;
                        dN_dxi[52][i] = -(xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/3.0 ;
                        dN_dxi[53][i] = -(8 * eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[54][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/9 ;
                        dN_dxi[55][i] = -(8 * eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[56][i] = -(2 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/9 ;
                        dN_dxi[57][i] = -(8 * eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[58][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9 ;
                        dN_dxi[59][i] = -(8 * eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[60][i] = -(2 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/9 ;
                        dN_dxi[61][i] = -(eta[i]* xi[i] * (8 * std::pow(xi[i], 2) - 5) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0))/3.0 ;
                        dN_dxi[62][i] = -(8 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27 ;
                        dN_dxi[63][i] = -(2 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9 ;
                        dN_dxi[64][i] = -(8 * eta[i]* zeta[i] * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27 ;
                        dN_dxi[65][i] = -(2 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9 ;
                        dN_dxi[66][i] = -(8 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[67][i] = -(2 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9 ;
                        dN_dxi[68][i] = -(8 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[69][i] = -(2 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9 ;
                        dN_dxi[70][i] = -((4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 16 * std::pow(xi[i],3) - 12 * std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/6 ;
                        dN_dxi[71][i] = -(8 * eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[72][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/9 ;
                        dN_dxi[73][i] = -(8 * eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[74][i] = -(2 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/9 ;
                        dN_dxi[75][i] = -(8 * eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[76][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9 ;
                        dN_dxi[77][i] = -(8 * eta[i]* zeta[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[78][i] = -(2 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/9 ;
                        dN_dxi[79][i] = -(eta[i]* xi[i] * (8 * std::pow(xi[i], 2) - 5) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0))/3.0 ;
                        dN_dxi[80][i] = -(8 * eta[i]* zeta[i] * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/27 ;
                        dN_dxi[81][i] = -(2 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/9 ;
                        dN_dxi[82][i] = -(8 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/27 ;
                        dN_dxi[83][i] = -(2 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/9 ;
                        dN_dxi[84][i] = -(8 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[85][i] = -(2 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9 ;
                        dN_dxi[86][i] = -(8 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[87][i] = -(2 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/9 ;
                        dN_dxi[88][i] = -((4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 16 * std::pow(xi[i],3) + 12 * std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/6 ;
                        dN_dxi[89][i] = -(8 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[90][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0))/9 ;
                        dN_dxi[91][i] = -(8 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[92][i] = -(2 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/9 ;
                        dN_dxi[93][i] = -(8 * eta[i]* zeta[i] * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[94][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/9 ;
                        dN_dxi[95][i] = -(8 * eta[i]* zeta[i] * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[96][i] = -(2 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/9 ;
                        dN_dxi[97][i] = -(xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0))/3.0 ;
                        dN_dxi[98][i] = (64 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[99][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/9 ;
                        dN_dxi[100][i] = (64 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[101][i] = (16 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/9 ;
                        dN_dxi[102][i] = (64 * eta[i]* zeta[i] * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/27 ;
                        dN_dxi[103][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/9 ;
                        dN_dxi[104][i] = (64 * eta[i]* zeta[i] * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/27 ;
                        dN_dxi[105][i] = (16 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/9 ;
                        dN_dxi[106][i] = (16 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/9 ;
                        dN_dxi[107][i] = (8 * eta[i]* xi[i] * (8 * std::pow(xi[i], 2) - 5) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/3.0 ;
                        dN_dxi[108][i] = (16 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/9 ;
                        dN_dxi[109][i] = (4 * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/3.0 ;
                        dN_dxi[110][i] = (16 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0))/9 ;
                        dN_dxi[111][i] = (8 * eta[i]* xi[i] * (8 * std::pow(xi[i], 2) - 5) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/3.0 ;
                        dN_dxi[112][i] = (16 * eta[i]* (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/9 ;
                        dN_dxi[113][i] = (4 * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0))/3.0 ;
                        dN_dxi[114][i] = (64 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[115][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9 ;
                        dN_dxi[116][i] = (64 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[117][i] = (16 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9 ;
                        dN_dxi[118][i] = (64 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) - 3 * std::pow(xi[i], 2) + 4 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[119][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9 ;
                        dN_dxi[120][i] = (64 * eta[i]* zeta[i] * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27 ;
                        dN_dxi[121][i] = (16 * zeta[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 8 * std::pow(xi[i],3) + 3 * std::pow(xi[i], 2) + 4 * xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9 ;
                        dN_dxi[122][i] = (8 * xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/3.0 ;
                        dN_dxi[123][i] = (8 * xi[i] * zeta[i] * (8 * std::pow(xi[i], 2) - 5) * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/3.0 ;
                        dN_dxi[124][i] = 2 * xi[i] * (8 * std::pow(xi[i], 2) - 5) * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0);



                        dN_deta[0][i] = -(xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/216;
                        dN_deta[1][i] = -(xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/216;
                        dN_deta[2][i] = -(xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/216;
                        dN_deta[3][i] = -(xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/216;
                        dN_deta[4][i] = -(xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/216;
                        dN_deta[5][i] = -(xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/216;
                        dN_deta[6][i] = -(xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/216;
                        dN_deta[7][i] = -(xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/216;
                        dN_deta[8][i] = (xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/27;
                        dN_deta[9][i] = (zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/36.0;
                        dN_deta[10][i] = (xi[i] * zeta[i] * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[11][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/27;
                        dN_deta[12][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/18;
                        dN_deta[13][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/27;
                        dN_deta[14][i] = (xi[i] * zeta[i] * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[15][i] = (zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/36.0;
                        dN_deta[16][i] = (xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/27;
                        dN_deta[17][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/27;
                        dN_deta[18][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/18;
                        dN_deta[19][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/27;
                        dN_deta[20][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/27;
                        dN_deta[21][i] = (xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/36.0;
                        dN_deta[22][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[23][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/27;
                        dN_deta[24][i] = (xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/36.0;
                        dN_deta[25][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[26][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/27;
                        dN_deta[27][i] = (xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/36.0;
                        dN_deta[28][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[29][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/27;
                        dN_deta[30][i] = (xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/36.0;
                        dN_deta[31][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[32][i] = (xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/27;
                        dN_deta[33][i] = (zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/36.0;
                        dN_deta[34][i] = (xi[i] * zeta[i] * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[35][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/27;
                        dN_deta[36][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0))/18;
                        dN_deta[37][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/27;
                        dN_deta[38][i] = (xi[i] * zeta[i] * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[39][i] = (zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/36.0;
                        dN_deta[40][i] = (xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/27;
                        dN_deta[41][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/27;
                        dN_deta[42][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0))/18;
                        dN_deta[43][i] = (xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/27;
                        dN_deta[44][i] = -(8 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/27;
                        dN_deta[45][i] = -(2 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/9;
                        dN_deta[46][i] = -(8 * xi[i] * zeta[i] * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[47][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9;
                        dN_deta[48][i] = -(8 * xi[i] * zeta[i] * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[49][i] = -(2 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/9;
                        dN_deta[50][i] = -(8 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/27;
                        dN_deta[51][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/9;
                        dN_deta[52][i] = -(eta[i]* zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + zeta[i] - 1.0))/3;
                        dN_deta[53][i] = -(8 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/27;
                        dN_deta[54][i] = -(2 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/9;
                        dN_deta[55][i] = -(8 * xi[i] * zeta[i] * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[56][i] = -(2 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9;
                        dN_deta[57][i] = -(8 * xi[i] * zeta[i] * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[58][i] = -(2 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_deta[59][i] = -(8 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[60][i] = -(2 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/9;
                        dN_deta[61][i] = -((4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 16 * std::pow(eta[i], 3) + 12 * std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/6;
                        dN_deta[62][i] = -(8 * xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/27;
                        dN_deta[63][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/9;
                        dN_deta[64][i] = -(8 * xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/27;
                        dN_deta[65][i] = -(2 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/9;
                        dN_deta[66][i] = -(8 * xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[67][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_deta[68][i] = -(8 * xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[69][i] = -(2 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/9;
                        dN_deta[70][i] = -(eta[i]* xi[i] * (8 * std::pow(eta[i], 2) - 5) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0))/3;
                        dN_deta[71][i] = -(8 * xi[i] * zeta[i] * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[72][i] = -(2 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/9;
                        dN_deta[73][i] = -(8 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/27;
                        dN_deta[74][i] = -(2 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/9;
                        dN_deta[75][i] = -(8 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[76][i] = -(2 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_deta[77][i] = -(8 * xi[i] * zeta[i] * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[78][i] = -(2 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9;
                        dN_deta[79][i] = -((4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 16 * std::pow(eta[i], 3) - 12 * std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/6;
                        dN_deta[80][i] = -(8 * xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/27;
                        dN_deta[81][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/9;
                        dN_deta[82][i] = -(8 * xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/27;
                        dN_deta[83][i] = -(2 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/9;
                        dN_deta[84][i] = -(8 * xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[85][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_deta[86][i] = -(8 * xi[i] * zeta[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[87][i] = -(2 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/9;
                        dN_deta[88][i] = -(eta[i]* xi[i] * (8 * std::pow(eta[i], 2) - 5) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0))/3;
                        dN_deta[89][i] = -(8 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/27;
                        dN_deta[90][i] = -(2 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/9;
                        dN_deta[91][i] = -(8 * xi[i] * zeta[i] * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[92][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9;
                        dN_deta[93][i] = -(8 * xi[i] * zeta[i] * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[94][i] = -(2 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/9;
                        dN_deta[95][i] = -(8 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/27;
                        dN_deta[96][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_deta[97][i] = -(eta[i]* zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (zeta[i] - 4 * std::pow(zeta[i], 2) - 4 * std::pow(zeta[i], 3) + 1.0))/3;
                        dN_deta[98][i] = (64 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/27;
                        dN_deta[99][i] = (16 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/9;
                        dN_deta[100][i] = (64 * xi[i] * zeta[i] * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[101][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9;
                        dN_deta[102][i] = (64 * xi[i] * zeta[i] * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/27;
                        dN_deta[103][i] = (16 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/9;
                        dN_deta[104][i] = (64 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/27;
                        dN_deta[105][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/9;
                        dN_deta[106][i] = (16 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/9;
                        dN_deta[107][i] = (4 * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0))/3;
                        dN_deta[108][i] = (16 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9;
                        dN_deta[109][i] = (8 * eta[i]* xi[i] * (8 * std::pow(eta[i], 2) - 5) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/3;
                        dN_deta[110][i] = (16 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9;
                        dN_deta[111][i] = (4 * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/3;
                        dN_deta[112][i] = (16 * xi[i] * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0))/9;
                        dN_deta[113][i] = (8 * eta[i]* xi[i] * (8 * std::pow(eta[i], 2) - 5) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/3;
                        dN_deta[114][i] = (64 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[115][i] = (16 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_deta[116][i] = (64 * xi[i] * zeta[i] * (- 8 * std::pow(eta[i], 3) + 3 * std::pow(eta[i], 2) + 4 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[117][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_deta[118][i] = (64 * xi[i] * zeta[i] * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[119][i] = (16 * zeta[i] * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_deta[120][i] = (64 * xi[i] * zeta[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 8 * std::pow(eta[i], 3) - 3 * std::pow(eta[i], 2) + 4 * eta[i]+ 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_deta[121][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_deta[122][i] = (8 * eta[i]* zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/3;
                        dN_deta[123][i] = (8 * eta[i]* zeta[i] * (8 * std::pow(eta[i], 2) - 5) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (2 * zeta[i] - std::pow(zeta[i], 2) - 2 * std::pow(zeta[i], 3) + 1.0))/3;
                        dN_deta[124][i] = 2 * eta[i]* (8 * std::pow(eta[i], 2) - 5) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (4 * std::pow(zeta[i], 4) - 5 * std::pow(zeta[i], 2) + 1.0);



                        dN_dzeta[0][i] = -(eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/216;
                        dN_dzeta[1][i] = -(eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/216;
                        dN_dzeta[2][i] = -(eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/216;
                        dN_dzeta[3][i] = -(eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/216;
                        dN_dzeta[4][i] = -(eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/216;
                        dN_dzeta[5][i] = -(eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/216;
                        dN_dzeta[6][i] = -(eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/216;
                        dN_dzeta[7][i] = -(eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/216;
                        dN_dzeta[8][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[9][i] = (eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/36.0;
                        dN_dzeta[10][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[11][i] = (eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[12][i] = (xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/36.0;
                        dN_dzeta[13][i] = (eta[i]* xi[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[14][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[15][i] = (eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/36.0;
                        dN_dzeta[16][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[17][i] = (eta[i]* xi[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[18][i] = (xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/36.0;
                        dN_dzeta[19][i] = (eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[20][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[21][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0))/18;
                        dN_dzeta[22][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[23][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[24][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0))/18;
                        dN_dzeta[25][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[26][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[27][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0))/18;
                        dN_dzeta[28][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[29][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[30][i] = (eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0))/18;
                        dN_dzeta[31][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[32][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[33][i] = (eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/36.0;
                        dN_dzeta[34][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[35][i] = (eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[36][i] = (xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/36.0;
                        dN_dzeta[37][i] = (eta[i]* xi[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[38][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[39][i] = (eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/36.0;
                        dN_dzeta[40][i] = (eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[41][i] = (eta[i]* xi[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[42][i] = (xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/36.0;
                        dN_dzeta[43][i] = (eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[44][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[45][i] = -(2 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/9;
                        dN_dzeta[46][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[47][i] = -(2 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/9;
                        dN_dzeta[48][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[49][i] = -(2 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/9;
                        dN_dzeta[50][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/27;
                        dN_dzeta[51][i] = -(2 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/9;
                        dN_dzeta[52][i] = -((4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 2 * zeta[i] - 1.0))/6;
                        dN_dzeta[53][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[54][i] = -(2 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/9;
                        dN_dzeta[55][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[56][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9;
                        dN_dzeta[57][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[58][i] = -(2 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[59][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[60][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/9;
                        dN_dzeta[61][i] = -(eta[i]* zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) + 4 * std::pow(eta[i], 2) + eta[i]- 1.0))/3;
                        dN_dzeta[62][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i]- 1.0))/27;
                        dN_dzeta[63][i] = -(2 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/9;
                        dN_dzeta[64][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[65][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/9;
                        dN_dzeta[66][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[67][i] = -(2 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[68][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[69][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0))/9;
                        dN_dzeta[70][i] = -(xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) - 4 * std::pow(xi[i], 2) + xi[i] + 1.0))/3;
                        dN_dzeta[71][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[72][i] = -(2 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/9;
                        dN_dzeta[73][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[74][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/9;
                        dN_dzeta[75][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[76][i] = -(2 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[77][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[78][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9;
                        dN_dzeta[79][i] = -(eta[i]* zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 4 * std::pow(eta[i], 3) - 4 * std::pow(eta[i], 2) + eta[i]+ 1.0))/3;
                        dN_dzeta[80][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[81][i] = -(2 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/9;
                        dN_dzeta[82][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[83][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0))/9;
                        dN_dzeta[84][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[85][i] = -(2 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[86][i] = -(8 * eta[i]* xi[i] * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[87][i] = -(4 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/9;
                        dN_dzeta[88][i] = -(xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 4 * std::pow(xi[i],3) + 4 * std::pow(xi[i], 2) + xi[i] - 1.0))/3;
                        dN_dzeta[89][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[90][i] = -(2 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[91][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[92][i] = -(2 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[93][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[94][i] = -(2 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[95][i] = -(8 * eta[i]* xi[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[96][i] = -(2 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[97][i] = -((4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (2 * zeta[i] - 12 * std::pow(zeta[i], 2) - 16 * std::pow(zeta[i], 3) + 1.0))/6;
                        dN_dzeta[98][i] = (64 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[99][i] = (16 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/9;
                        dN_dzeta[100][i] = (64 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[101][i] = (16 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/9;
                        dN_dzeta[102][i] = (64 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[103][i] = (16 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/9;
                        dN_dzeta[104][i] = (64 * eta[i]* xi[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/27;
                        dN_dzeta[105][i] = (16 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/9;
                        dN_dzeta[106][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/9;
                        dN_dzeta[107][i] = (8 * eta[i]* zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0))/3;
                        dN_dzeta[108][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9;
                        dN_dzeta[109][i] = (8 * xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/3;
                        dN_dzeta[110][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0))/9;
                        dN_dzeta[111][i] = (8 * eta[i]* zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/3;
                        dN_dzeta[112][i] = (32 * eta[i]* xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0))/9;
                        dN_dzeta[113][i] = (8 * xi[i] * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0))/3;
                        dN_dzeta[114][i] = (64 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[115][i] = (16 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[116][i] = (64 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) + std::pow(eta[i], 2) + 2 * eta[i]- 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[117][i] = (16 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[118][i] = (64 * eta[i]* xi[i] * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (- 2 * std::pow(xi[i],3) - std::pow(xi[i], 2) + 2 * xi[i] + 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[119][i] = (16 * eta[i]* (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[120][i] = (64 * eta[i]* xi[i] * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (- 2 * std::pow(eta[i], 3) - std::pow(eta[i], 2) + 2 * eta[i]+ 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/27;
                        dN_dzeta[121][i] = (16 * xi[i] * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (- 2 * std::pow(xi[i],3) + std::pow(xi[i], 2) + 2 * xi[i] - 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/9;
                        dN_dzeta[122][i] = (4 * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 4 * zeta[i] - 1.0))/3;
                        dN_dzeta[123][i] = (4 * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0) * (4 * zeta[i] - 3 * std::pow(zeta[i], 2) - 8 * std::pow(zeta[i], 3) + 1.0))/3;
                        dN_dzeta[124][i] = 2 * zeta[i] * (8 * std::pow(zeta[i], 2) - 5) * (4 * std::pow(eta[i], 4) - 5 * std::pow(eta[i], 2) + 1.0) * (4 * std::pow(xi[i],4) - 5 * std::pow(xi[i], 2) + 1.0);

                }
                break;
            }
        {
            N_xi_gp = N;
            int numRows = dN_dxi.size();
            int numCols = dN_dxi[0].size() * 3;
            vectors gradN_xi_gp(numRows, std::vector<double>(numCols));

            for (size_t i = 0; i < numRows; ++i) {
                for (size_t j = 0; j < dN_dxi[i].size(); ++j) {
                    gradN_xi_gp[i][3 * j + 0] = dN_dxi[i][j];     // Column for dN_dxi
                    gradN_xi_gp[i][3 * j + 1] = dN_deta[i][j];    // Column for dN_deta
                    gradN_xi_gp[i][3 * j + 2] = dN_dzeta[i][j];    // Column for dN_dzeta
                }
            }
            GradN_xi_gp = gradN_xi_gp;
        }
        default:

            break;
    }
    return std::make_pair(N_xi_gp, GradN_xi_gp);
}
std::vector<std::vector<double> > compute_J(const std::vector<double> &X, int NGP, int PD,
                                                     const std::vector<std::vector<double> > &GradN_xi_gp) {
    // Initialize J_gp to have PD rows and NGP * PD columns
    std::vector<std::vector<double>> J_gp(PD, std::vector<double>(PD * NGP, 0.0));

    for (int gp = 0; gp < NGP; ++gp) {
        // Extract the appropriate gradient for the current Gauss point
        std::vector<std::vector<double>> GradN_xi; // To hold gradients for the current Gauss point

        // Extract columns for the current Gauss point
        for (size_t row = 0; row < GradN_xi_gp.size(); ++row) {
            std::vector<double> gradient_row;
            int start_col = gp * PD; // Starting column index for the current Gauss point
            for (int col = start_col; col < start_col + PD; ++col) {
                gradient_row.push_back(GradN_xi_gp[row][col]); // Copy the specific columns for the current row
            }
            GradN_xi.push_back(gradient_row); // Add the row to the extracted gradients
        }

        // Compute J as the product of X and GradN_xi
        std::vector<double> J(PD, 0.0); // Initialize J with PD size
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < GradN_xi.size(); ++j) {
                J[i] += X[j] * GradN_xi[j][i]; // Multiply and accumulate
            }
        }

        // Store J in the correct position in J_gp
        for (int j = 0; j < PD; ++j) {
            J_gp[j][(gp * PD) + j] = J[j]; // Store the computed J
        }
    }

    return J_gp; // Return the computed Jacobian matrix
}
std::vector<std::vector<double>> compute_GradN(const std::vector<std::vector<double>>& J_gp, int NGP, int PD, const std::vector<std::vector<double>>& GradN_xi_gp) {
    std::vector<std::vector<double>> GradN_X_gp(J_gp.size(), std::vector<double>(NGP * PD)); // Initialize output
    for (int gp = 0; gp < NGP; ++gp) {
        // Extract GradN_xi and J for the current Gauss point
        auto GradN_xi = std::vector<double>(GradN_xi_gp.begin() + gp * PD, GradN_xi_gp.begin() + (gp + 1) * PD);
        auto J = std::vector<double>(J_gp.begin() + gp * PD, J_gp.begin() + (gp + 1) * PD);

        // Compute JinvT = inv(J)' (for simplicity, assume J is square)
        std::vector<std::vector<double>> JinvT(PD, std::vector<double>(PD)); // Placeholder for the inverse transpose
        // Inversion logic should be implemented here (omitted for brevity)

        // GradN_X_gp = (JinvT * GradN_xi')'
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                GradN_X_gp[gp][(gp * PD) + j] += JinvT[i][j] * GradN_xi[j]; // Matrix multiplication
            }
        }
    }

    return GradN_X_gp; // Return computed gradient
}
void compute_at_gp(const std::vector<double>& x_e, int N_gp, std::vector<std::vector<double>>& x_gp, std::vector<std::vector<double>>& Gradx_gp) {
    x_gp = std::vector<std::vector<double>>(x_e.size(), std::vector<double>(N_gp, 0));
    Gradx_gp = std::vector<std::vector<double>>(x_e.size(), std::vector<double>(N_gp, 0));
}

std::vector<std::vector<double>> compute_R(const std::vector<double>& x_e, int NPE, int N_gp, const std::vector<std::vector<double>>& GradN_gp, const std::vector<std::vector<double>>& JJ, const std::vector<std::vector<double>>& GP, int PD, double lambda, double mu) {
    std::vector<std::vector<double>> x_gp, Gradx_gp;
    compute_at_gp(x_e, N_gp, x_gp, Gradx_gp);

    std::vector<std::vector<double>> R(NPE * PD, std::vector<double>(1, 0));
    int NGP = GP[0].size();
    std::vector<double> wp = GP[GP.size() - 1];

    for (int gp = 0; gp < NGP; gp++) {
        std::vector<double> N = GradN_gp[gp];
        std::vector<std::vector<double>> GradN(PD, std::vector<double>(PD));
        for (int i = 0; i < PD; i++)
            for (int j = 0; j < PD; j++)
                GradN[i][j] = GradN_gp[i + gp * PD][j];

        double JxW = 1.0;
        for (int i = 0; i < PD; i++)
            JxW *= JJ[i + gp * PD][i];
        JxW *= wp[gp];

        std::vector<double> x = x_gp[gp];
        std::vector<std::vector<double>> Gradx(PD, std::vector<double>(PD));
        for (int i = 0; i < PD; i++)
            for (int j = 0; j < PD; j++)
                Gradx[i][j] = Gradx_gp[i + gp * PD][j];

        std::vector<std::vector<double>> F = Gradx;
        std::vector<std::vector<double>> Finv(PD, std::vector<double>(PD));
        double detF = 1.0;
        for (int i = 0; i < PD; i++)
            detF *= F[i][i];

        for (int i = 0; i < PD; i++)
            for (int j = 0; j < PD; j++)
                Finv[i][j] = (i == j) ? 1.0 / F[i][i] : 0;

        std::vector<std::vector<double>> FinvT(PD, std::vector<double>(PD));
        for (int i = 0; i < PD; i++)
            for (int j = 0; j < PD; j++)
                FinvT[i][j] = Finv[j][i];

        double J = detF;
        std::vector<std::vector<double>> P(PD, std::vector<double>(PD));
        for (int i = 0; i < PD; i++)
            for (int j = 0; j < PD; j++)
                P[i][j] = mu * (F[i][j] - FinvT[i][j]) + 0.5 * lambda * (J * J - 1) * FinvT[i][j];

        std::vector<double> R1(PD, 0);
        std::vector<std::vector<double>> R2 = P;
        for (int I = 0; I < NPE; I++) {
            std::vector<double> R_tmp(PD, 0);
            for (int k = 0; k < PD; k++)
                R_tmp[k] = (R1[k] * N[I] + R2[k][I] * GradN[k][I]) * JxW;
            for (int k = 0; k < PD; k++)
                R[I * PD + k][0] += R_tmp[k];
        }
    }

    return R;
}
#include <iostream>

template<typename T>
using Array3D = std::vector<std::vector<std::vector<T>>>;

template<typename T>
using Array4D = std::vector<std::vector<std::vector<std::vector<T>>>>;

std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> compute_at_gp(const std::vector<std::vector<double>>& x_e, const std::vector<std::vector<double>>& N_gp, const std::vector<std::vector<double>>& GradN_gp) {
    std::vector<std::vector<double>> x_gp = x_e; // Replace with actual computation
    std::vector<std::vector<double>> Gradx_gp = GradN_gp; // Replace with actual computation
    return {x_gp, Gradx_gp};
}

std::pair<std::vector<double>, std::vector<std::vector<double>>> compute_RK(const std::vector<std::vector<double>>& x_e, int NPE, const std::vector<std::vector<double>>& N_gp, const std::vector<std::vector<double>>& GradN_gp, const std::vector<std::vector<double>>& JJ, const std::vector<std::vector<double>>& GP, int PD, double lambda, double mu, const std::vector<std::vector<double>>& NGP_val) {
    auto [x_gp, Gradx_gp] = compute_at_gp(x_e, N_gp, GradN_gp);

    std::vector<std::vector<double>> II(PD, std::vector<double>(PD, 0));
    for (int i = 0; i < PD; ++i) {
        II[i][i] = 1.0;
    }

    std::vector<double> R(NPE * PD, 0);
    std::vector<std::vector<double>> K(NPE * PD, std::vector<double>(NPE * PD, 0));
    int NGP = GP[0].size();
    std::vector<double> wp = GP[GP.size() - 1];

    for (int gp = 0; gp < NGP; ++gp) {
        std::vector<double> N = N_gp[gp];
        std::vector<std::vector<double>> GradN(PD, std::vector<double>(PD, 0));
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                GradN[i][j] = GradN_gp[i + gp * PD][j];
            }
        }

        double JxW = 1.0;
        for (int i = 0; i < PD; ++i) {
            JxW *= JJ[i + gp * PD][i];
        }
        JxW *= wp[gp];

        std::vector<double> x = x_gp[gp];
        std::vector<std::vector<double>> Gradx(PD, std::vector<double>(PD, 0));
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                Gradx[i][j] = Gradx_gp[i + gp * PD][j];
            }
        }

        std::vector<std::vector<double>> F = Gradx;
        std::vector<std::vector<double>> Finv(PD, std::vector<double>(PD, 0));
        double detF = 1.0;
        for (int i = 0; i < PD; ++i) {
            detF *= F[i][i];
        }

        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                Finv[i][j] = (i == j) ? 1.0 / F[i][i] : 0;
            }
        }

        std::vector<std::vector<double>> FinvT(PD, std::vector<double>(PD, 0));
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                FinvT[i][j] = Finv[j][i];
            }
        }

        double J = detF;
        std::vector<std::vector<double>> P(PD, std::vector<double>(PD, 0));
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                P[i][j] = mu * (F[i][j] - FinvT[i][j]) + 0.5 * lambda * (J * J - 1) * FinvT[i][j];
            }
        }

        Array4D<double> dP_dF(PD, Array3D<double>(PD, std::vector<std::vector<double>>(PD, std::vector<double>(PD, 0))));
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                for (int k = 0; k < PD; ++k) {
                    for (int l = 0; l < PD; ++l) {
                        dP_dF[i][j][k][l] = lambda * J * J * FinvT[i][j] * FinvT[k][l] - 0.5 * lambda * (J * J - 1) * FinvT[i][l] * FinvT[k][j] + mu * (II[i][k] * II[j][l] + FinvT[i][l] * FinvT[k][j]);
                    }
                }
            }
        }

        std::vector<double> R1(PD, 0);
        std::vector<std::vector<double>> dR1_dx(PD, std::vector<double>(PD, 0));
        Array3D<double> dR1_dGradx(PD, std::vector<std::vector<double>>(PD, std::vector<double>(PD, 0)));
        std::vector<std::vector<double>> R2 = P;
        Array3D<double>dR2_dx(PD, std::vector<std::vector<double>>(PD, std::vector<double>(PD, 0)));
        Array4D<double> dR2_dGradx = dP_dF;

        for (int I = 0; I < NPE; ++I) {
            std::vector<double> R_tmp(PD, 0);
            for (int k = 0; k < PD; ++k) {
                R_tmp[k] = (R1[k] * N[I] + R2[k][I] * GradN[I][k]) * JxW;
            }
            for (int k = 0; k < PD; ++k) {
                R[I * PD + k] += R_tmp[k];
            }
        }

        for (int I = 0; I < NPE; ++I) {
            for (int J = 0; J < NPE; ++J) {
                std::vector<std::vector<double>> K1(PD, std::vector<double>(PD, 0));
                for (int i = 0; i < PD; ++i) {
                    for (int j = 0; j < PD; ++j) {
                        K1[i][j] = dR1_dx[i][j] * N[I] * N[J] * JxW;
                    }
                }

                std::vector<std::vector<double>> K2(PD, std::vector<double>(PD, 0));
                for (int i = 0; i < PD; ++i) {
                    for (int j = 0; j < PD; ++j) {
                        for (int l = 0; l < PD; ++l) {
                            K2[i][j] += dR1_dGradx[i][j][l] * N[I] * GradN[J][l] * JxW;
                        }
                    }
                }

                std::vector<std::vector<double>> K3(PD, std::vector<double>(PD, 0));
                for (int i = 0; i < PD; ++i) {
                    for (int k = 0; k < PD; ++k) {
                        for (int j = 0; j < PD; ++j) {
                            K3[i][k] += dR2_dx[i][j][k] * GradN[I][j] * N[J] * JxW;
                        }
                    }
                }

                std::vector<std::vector<double>> K4(PD, std::vector<double>(PD, 0));
                for (int i = 0; i < PD; ++i) {
                    for (int k = 0; k < PD; ++k) {
                        for (int j = 0; j < PD; ++j) {
                            for (int m = 0; m < PD; ++m) {
                                K4[i][k] += dR2_dGradx[i][j][k][m] * GradN[I][j] * GradN[J][m] * JxW;
                            }
                        }
                    }
                }

                for (int i = 0; i < PD; ++i) {
                    for (int j = 0; j < PD; ++j) {
                        for (int k = 0; k < PD; ++k)
                        K[I * PD + i][J * PD + j] += K1[i][j] + K2[i][j] + K3[i][k] + K4[i][k];
                    }
                }
            }
        }
    }

    return std::make_pair(R, K);
}

void compute_at_gp(const std::vector<std::vector<double>>& x_e, int N_gp, const std::vector<std::vector<double>>& GradN_gp,
                   std::vector<std::vector<double>>& x_gp, std::vector<std::vector<double>>& Gradx_gp) {
    int num_nodes = x_e.size();  // Number of nodes in the element
    int PD = x_e[0].size();      // Problem dimension (e.g., 2 for 2D)

    // Initialize x_gp and Gradx_gp with dimensions
    x_gp = std::vector<std::vector<double>>(N_gp, std::vector<double>(PD, 0.0));
    Gradx_gp = std::vector<std::vector<double>>(N_gp, std::vector<double>(PD, 0.0));

    // Loop over Gauss points
    for (int gp = 0; gp < N_gp; ++gp) {
        // For each spatial dimension, calculate the position and gradient at the Gauss point
        for (int dim = 0; dim < PD; ++dim) {
            for (int node = 0; node < num_nodes; ++node) {
                // x_gp[gp][dim]: Position of Gauss point in current dimension
                x_gp[gp][dim] += GradN_gp[gp][node] * x_e[node][dim];

                // Gradx_gp: Gradient contribution at Gauss point for this dimension
                Gradx_gp[gp][dim] += GradN_gp[gp][node] * x_e[node][dim];
            }
        }
    }
}


void compute_RK_GP(const std::vector<std::vector<double>>& x_e, int NPE, int N_gp, const std::vector<std::vector<double>>& GradN_gp,
                   const std::vector<std::vector<double>>& JJ, const std::vector<std::vector<double>>& GP, int PD, double lambda,
                   double mu, int NGP_val, std::vector<std::vector<double>>& R_GP, std::vector<std::vector<double>>& K_GP) {

    std::vector<std::vector<double>> x_gp, Gradx_gp;
    compute_at_gp(x_e, N_gp, GradN_gp, x_gp, Gradx_gp);

    R_GP = std::vector<std::vector<double>>(NPE, std::vector<double>(NGP_val, 0));
    K_GP = std::vector<std::vector<double>>(NPE, std::vector<double>(NPE, 0));

    std::vector<std::vector<double>> II(PD, std::vector<double>(PD, 0));
    for (int i = 0; i < PD; ++i) {
        II[i][i] = 1.0;
    }

    int NGP = GP[0].size();
    std::vector<double> wp = GP[GP.size() - 1];

    for (int gp = 0; gp < NGP; gp++) {
        std::vector<double> N = GradN_gp[gp];
        std::vector<std::vector<double>> GradN(PD, std::vector<double>(PD, 0));
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                GradN[i][j] = GradN_gp[i + gp * PD][j];
            }
        }

        double JxW = 1.0;
        for (int i = 0; i < PD; ++i) {
            JxW *= JJ[i + gp * PD][i];
        }
        JxW *= wp[gp];

        std::vector<double> x = x_gp[gp];
        std::vector<std::vector<double>> Gradx(PD, std::vector<double>(PD, 0));
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                Gradx[i][j] = Gradx_gp[i + gp * PD][j];
            }
        }

        std::vector<std::vector<double>> F = Gradx;
        std::vector<std::vector<double>> Finv(PD, std::vector<double>(PD, 0));
        double detF = 1.0;
        for (int i = 0; i < PD; ++i) {
            detF *= F[i][i];
        }

        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                Finv[i][j] = (i == j) ? 1.0 / F[i][i] : 0;
            }
        }

        std::vector<std::vector<double>> FinvT(PD, std::vector<double>(PD, 0));
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                FinvT[i][j] = Finv[j][i];
            }
        }

        double J = detF;
        std::vector<std::vector<double>> P(PD, std::vector<double>(PD, 0));
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                P[i][j] = mu * (F[i][j] - FinvT[i][j]) + 0.5 * lambda * (J * J - 1) * FinvT[i][j];
            }
        }

        std::vector<double> R1(PD, 0);
        std::vector<double> R2(P.size() * P.size(), 0);
        for (int i = 0; i < PD; ++i) {
            for (int j = 0; j < PD; ++j) {
                R2[i * PD + j] = P[i][j];
            }
        }

        std::vector<double> R(R1.size() + R2.size(), 0);
        R.insert(R.end(), R1.begin(), R1.end());
        R.insert(R.end(), R2.begin(), R2.end());

        for (int s = 0; s < R.size(); s++) {
            for (int I = 0; I < NPE; I++) {
                double R_tmp = R[s] * N[I] * JxW;
                R_GP[I][s] += R_tmp;
            }
        }

        for (int I = 0; I < NPE; I++) {
            for (int J = 0; J < NPE; J++) {
                double K_tmp = N[I] * N[J] * JxW;
                K_GP[I][J] += K_tmp;
            }
        }
    }
}

int delta(int a, int b) {
    return (a == b) ? 1 : 0;
}


int main() {

    return 0;
}

