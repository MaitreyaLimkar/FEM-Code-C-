//
// Created by David Valle on 18-Oct-24.
//
#include "Initialize.h"
#include <cmath>   // For std::pow and tolerance comparison
#include <algorithm> // For std::max
#include <iostream>  // For debugging purposes

void Initialize(int problemDimension,
                const std::vector<std::vector<double>>& nodeList,
                const std::vector<std::vector<int>>& elementList,
                const std::vector<double>& domainSize,
                const std::vector<int>& elementOrder,
                double lambda,
                double mu,
                std::vector<Node>& nodeArray,
                std::vector<Element>& elementArray) {

    // Number of nodes (NoN) and number of elements (NoE)
    int numOfNodes = nodeList.size();
    int numOfElements = elementList.size();

    // Tolerance (not currently used in C++, but you can implement tolerance checks if needed)
    double tol = 1e-6;

    // Determine the number of Gauss Points (NGP) based on problemDimension and elementOrder
    int maxElementOrder = *std::max_element(elementOrder.begin(), elementOrder.end());
    int NGP = 0;

    switch (problemDimension) {
        case 1:
            switch (maxElementOrder) {
                case 1: NGP = 2; break;
                case 2: NGP = 3; break;
                case 3: NGP = 4; break;
                case 4: NGP = 5; break;
            }
            break;
        case 2:
            switch (maxElementOrder) {
                case 1: NGP = 4; break;
                case 2: NGP = 9; break;
                case 3: NGP = 16; break;
                case 4: NGP = 25; break;
            }
            break;
        case 3:
            switch (maxElementOrder) {
                case 1: NGP = 8; break;
                case 2: NGP = 27; break;
                case 3: NGP = 64; break;
                case 4: NGP = 125; break;
            }
            break;
    }

    // Initialize Nodes
    nodeArray.resize(numOfNodes);  // Resize the nodeArray to store the nodes

    for (int i = 0; i < numOfNodes; ++i) {
        // Element list for the node (list of elements attached to the node)
        std::vector<int> elementListForNode;
        for (int j = 0; j < numOfElements; ++j) {
            if (std::find(elementList[j].begin(), elementList[j].end(), i + 1) != elementList[j].end()) {
                elementListForNode.push_back(j);
            }
        }

        // Get material position of node i
        std::vector<double> materialPosition = nodeList[i];
        std::vector<double> spatialPosition = materialPosition;  // Initialize spatial position with material position

        // Create a Node object and store it in nodeArray
        nodeArray[i] = Node(i + 1, problemDimension, materialPosition, elementListForNode);
    }

    // Initialize Elements
    elementArray.resize(numOfElements);  // Resize the elementArray to store the elements

    for (int i = 0; i < numOfElements; ++i) {
        // Node list for the element
        std::vector<int> nodeListForElement = elementList[i];

        // Material and spatial positions for the element
        std::vector<std::vector<double>> materialPosition(problemDimension, std::vector<double>(nodeListForElement.size()));
        std::vector<std::vector<double>> spatialPosition(problemDimension, std::vector<double>(nodeListForElement.size()));

        // Fill in material and spatial positions from node data
        for (int j = 0; j < nodeListForElement.size(); ++j) {
            const Node& node = nodeArray[nodeListForElement[j] - 1];  // -1 for zero-based index
            for (int k = 0; k < problemDimension; ++k) {
                materialPosition[k][j] = node.getMaterialPosition()[k];
                spatialPosition[k][j] = node.getSpatialPosition()[k];
            }
        }

        // Create an Element object and store it in elementArray
        elementArray[i] = Element(i + 1, problemDimension, nodeListForElement, materialPosition, spatialPosition, NGP, elementOrder[i], lambda, mu);
    }
}

#include "Initilization.hpp"
