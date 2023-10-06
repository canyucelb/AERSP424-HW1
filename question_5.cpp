//
//  question_5.cpp
//  yucel_homework1
//
//  Created by BARAN CAN YUCEL on 10/5/23.
//


#include <iostream>
#include <cmath>

using namespace std; // Add this line

// Question 5
// Write a function named “sigmoid” that computes the following equation.
double sigmoid(double z) {
    // Defining the sigmoid function 1 / (1 + exp(-z))
    return 1.0 / (1.0 + exp(-z));
}

// Write another function named “gradient_sigmoid” that computes the mentioned equation.
double gradient_sigmoid(double z) {
    // Sigmoid calculation of z input
    double sigmoid_z = sigmoid(z);
    // Sigmoid function's gradient calculation
    return sigmoid_z * (1.0 - sigmoid_z);
}

// Test and compare your results with the given information.
int main() {
    double z = 0.0176835;

    // Sigmoid and gradient calculation
    double sigmoid_result = sigmoid(z), gradient_sigmoid_result = gradient_sigmoid(z);

    // Printing the results
    cout << "Sigmoid Result is: " << sigmoid_result << endl;
    cout << "Sigmoid Gradient Result is: " << gradient_sigmoid_result << endl;

    return 0;
}
