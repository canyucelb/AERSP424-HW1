//  question_9.cpp
//  yucel_homework1
//
//  Created by BARAN CAN YUCEL on 10/5/23.
//

// Question 8


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to compute the sigmoid of a value form question_5.cpp 
double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

// Function to compute the gradient of sigmoid from question_5.cpp
double gradient_sigmoid(double z) {
    double sig_z = sigmoid(z);
    return sig_z * (1.0 - sig_z);
}

// Function for a classifier will identify whether an aircraft uses either a jet or a turboprop engine from three other characteristics, i.e., (1) an approach speed, (2) a length of wingspan, and (3) maximum takeoff weight (MTOW).
vector<double> train_classifier(const vector<vector<double>>& aircraft_data, const vector<int>& engine_types, int max_iterations, double learning_rate) {
    // inital given weights
    vector<double> w = {0.0001, 0.0001, 0.0001};  

    vector<double> dW(w.size(), 0.0);

    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        for (size_t i = 0; i < aircraft_data.size(); ++i) {
            // Defining the input & output data (x,y)
            vector<double> x = aircraft_data[i];
            double y = engine_types[i];

            // Dot product calculation
            double z = 0.0;
            for (size_t j = 0; j < w.size(); ++j) {
                z += w[j] * x[j];
            }

            // Cost gradient calculation
            double dC = 2 * (sigmoid(z) - y);

            // Update weights
            for (size_t j = 0; j < w.size(); ++j) {
                dW[j] = dC * gradient_sigmoid(z) * x[j];
                w[j] -= learning_rate * dW[j];
                
                // Checking weights whether they are in [-1,1] interval
                w[j] = max(min(w[j], 1.0), -1.0);
            }
        }
    }

    return w;
}

std::vector<int> fit(std::vector<std::vector<double>> data, std::vector<double> weights){
    std::vector<int> result;
    for(size_t i=0;i<data.size();i++){
        auto d = data[i];
        double z = 0;
        for(size_t j=0;j<d.size();j++){
            z+= d[j]*weights[j];
        }
        int c = std::round(sigmoid(z));
        result.push_back(c);
    }
    return result;
}

int main() {
    // aircraft data (approach speed, wingspan and MTOW)
    vector<vector<double>> aircraft_data = {
        {124.0, 31.89, 20.945},
        {74.0, 51.08, 9.170},
        {103.0, 34.67, 8.300},
        {77.0, 52.00, 9.400},
        {104.0, 35.63, 13.000},
        {92.0, 56.00, 12.500},
        {130.0, 31.29, 17.637},
        {73.0, 52.00, 9.600}
    };

    // engine types (1 = Jet, 0 = Turboprop)
    vector<int> engine_types = {1, 0, 1, 0, 1, 0, 1, 0};

    // Pick the number no less than 100 to be the maximum number of iterations.
    int max_iterations = 100000;  
    // Learning rate
    double learning_rate = 0.001;  

    // Training
    vector<double> trained_weights = train_classifier(aircraft_data, engine_types, max_iterations, learning_rate);

    // Printing the result
    cout << "Weights are trained as (w): ";
    for (size_t i = 0; i < trained_weights.size(); ++i) {
        cout << trained_weights[i] << " ";
    }
    cout << endl;

    auto labels = fit(aircraft_data, trained_weights);
    cout << "Estimated engine types are: ";
    for (size_t i = 0; i < labels.size(); ++i) {
        cout << labels[i] << " ";
    }
    cout << endl;


    return 0;
}
