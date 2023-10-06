//  question_7.cpp
//  yucel_homework1
//
//  Created by BARAN CAN YUCEL on 10/5/23.
//

// Question 7 

// Include necessary libraries
#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate the dot product of two vectors from question_4.cpp
double dot_product(const std::vector<double>& w, const std::vector<double>& x) {
    // Check if the vectors are of the same size
    if (w.size() != x.size()) {
        std::cerr << "Vectors are not the same size for calculation!" << std::endl;
        return 0.0;
    }

    // Initialize the result to 0
    double result = 0.0;

    // Calculate the dot product by multiplying corresponding elements and adding to the result
    for (size_t i = 0; i < w.size(); ++i) {
        result += w[i] * x[i];
    }

    return result;
}

// Function to calculate the sigmoid of a number from question_5.cpp
double sigmoid(double z) {
    // Sigmoid function is 1 / (1 + exp(-z))
    return 1.0 / (1.0 + exp(-z));
}

// Function to calculate the gradient of the cost from question_6.cpp
double gradient_cost(double y_predict, double y_actual) {
    // Gradient cost function is 2 * (predicted_value - actual_value)
    return 2 * (y_predict - y_actual);
}

// Function to calculate the gradient of weights
std::vector<double> gradient_weights(const std::vector<double>& w, const std::vector<double>& x, double y_actual) {
    // Initialize a vector to store the gradients
    std::vector<double> gradient(w.size(), 0.0);

    // Calculate the dot product of w and x
    double z = dot_product(w, x);

    // Calculate the sigmoid of the dot product
    double sigmoid_z = sigmoid(z);

    // Calculate the gradient of the cost
    double dC = gradient_cost(sigmoid_z, y_actual);

    // Calculate the gradient of weights for each weight
    for (size_t i = 0; i < w.size(); ++i) {
        gradient[i] = dC * sigmoid_z * (1 - sigmoid_z) * x[i];
    }

    return gradient;
}

// Function to update the weights
std::vector<double> update_weights(const std::vector<double>& w, const std::vector<double>& dw, double alpha) {
    // Initialize a vector to store the updated weights
    std::vector<double> updated_weights(w.size(), 0.0);

    // Update each weight element using the formula: new_weight = old_weight - learning_rate * gradient
    for (size_t i = 0; i < w.size(); ++i) {
        updated_weights[i] = w[i] - alpha * dw[i];
    }

    return updated_weights;
}

int main() {
    // Set the actual value (y)
    double y = 1.0;

    // Initialize the weights (w) and input values (x)
    std::vector<double> w = {0.0001, 0.0001, 0.0001};
    std::vector<double> x = {124, 31.89, 20.945};

    // Set the learning rate (alpha)
    double alpha = 0.001;

    // Calculate the gradient of weights
    std::vector<double> gradient_w = gradient_weights(w, x, y);

    // Update the weights
    std::vector<double> updated_weights = update_weights(w, gradient_w, alpha);

    // Print the results
    std::cout << "Gradient of Weights are: ";
    for (size_t i = 0; i < gradient_w.size(); ++i) {
        std::cout << gradient_w[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Updated Weights are: ";
    for (size_t i = 0; i < updated_weights.size(); ++i) {
        std::cout << updated_weights[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

