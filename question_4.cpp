//
//  question_4.cpp
//  yucel_homework1
//
//  Created by BARAN CAN YUCEL on 10/5/23.
//


#include <iostream>
#include <vector>
#include<cmath>

// Question 4
// Function to compute the dot product of two vectors
double dot_product(const std::vector<double>& w, const std::vector<double>& x) {
    // Check if the vectors are of the same size
    if (w.size() != x.size()) {
        std::cerr << "Vectors are not the same size for calculation!" << std::endl;
        return 0.0;  // Return 0 if the vectors are not the same size
    }

    // If the vectors have the same size, calculate the dot product
    double result = 0.0;  // Initialize the result to 0
    for (size_t i = 0; i < w.size(); ++i) {
        result += w[i] * x[i];  // Multiply corresponding elements and add to the result
    }

    return result;  // Return the dot product
}

int main() {
    // Test and compare your result with the following information for w, x, and z as given in the problem
    std::vector<double> w = {0.0001, 0.0001, 0.0001};  // Initial weights
    std::vector<double> x = {124, 31.89, 20.945};  // Input values

    double z = dot_product(w, x);

    std::cout << "Result of the dot product is: " << z << std::endl;

    return 0;
}
