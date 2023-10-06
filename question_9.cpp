//  question_9.cpp
//  yucel_homework1
//
//  Created by BARAN CAN YUCEL on 10/5/23.
//

// Question 9
//The final 𝑤 is pretty mush the neural network model. We will need to see if it can actually classify the aircraft engine.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to compute the sigmoid of a value form question_5.cpp 
double sigmoid(double z) 
{
    return 1.0 / (1.0 + exp(-z));
}

// Function to predict the engine type of an aircraft y_predict = sigmoid* (w^t * x)
string predict_engine_type(const vector<double>& w, const vector<double>& x) {
    double z = 0.0;
    for (size_t i = 0; i < w.size(); ++i)
     {
        z += w[i] * x[i];
    }

    // y_predict = 
    double y_predict = sigmoid(z);

    // . If 𝑦𝑝𝑟𝑒𝑑𝑖𝑐𝑡 > 0.5, it means your classifier think an aircraft uses a jet engine; otherwise, it uses a turboprop engine
    if (y_predict > 0.5) {
        return "Jet";
    } 
    else {
        return "Turboprop";
    }
}

int main() {
    // Define the trained weights (w) obtained from question_8.cpp. Weights are trained as (w): 0.217053, -0.458169, -0.014794
    vector<double> trained_weights = {0.217053, -0.458169, -0.014794}; 
    // Let’s we have four new aircraft date, which are also taken from faa.gov
    vector<vector<double>> new_aircraft_data = {
        {87.0, 38.67, 6.000},
        {79.0, 52.08, 8.000},
        {92.0, 33.75, 7.804},
        {91.0, 59.25, 16.000}
    };

    // Engine type prediction
    std::cout << "Engine Type is: " << endl;
    for (size_t i = 0; i < new_aircraft_data.size(); ++i) 
    {
        const vector<double>& aircraft = new_aircraft_data[i];
        
        string engine_type = predict_engine_type(trained_weights, aircraft);
        
        std::cout << "Aircraft " << (i + 1) << " is: "<< engine_type << endl;
    }

    return 0;
}
