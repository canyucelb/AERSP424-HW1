//
//  question_1.cpp
//  yucel_homework1
//
//  Created by BARAN CAN YUCEL on 10/5/23.
//



#include <iostream>
#include <vector>

// Question 1
// With ∆𝑡 = 0.01 𝑠, write a program to predict the roll rate of the aircraft up to 5 seconds and print out the result at every time step.

//  Roll damping coefficient and aileron effectiveness is picked randomly from interval [-1,1]
// maximum aileron deflection is 1 radian and duration of the deflection is 2 seconds
// the time step is given 0.01 seconds and total simulation time is 5 seconds.
// initial roll rate is given 1 radian / second

// Defining the constants for the solution
const double lp = 0.19, l_delta = 0.3, max_aileron_deflection = 1.0, duration_deflection = 2.0, time_step = 0.01, simulation_time = 5.0, initial_roll_rate = 1.0;


// Function for calculating the roll rate for next time steps p(t+1) = pt + pt* delta_t

double roll_rate_calculation(double p, double delta, double delta_t) {
   
    return p + (lp * p + l_delta * delta) * delta_t;
    // initialized the formula given in the question
}

int main() {
    // Initializing the rolling rate and time
    double p = initial_roll_rate, t = 0.0;
    // Creating a vector for storing roll rate for each time step
    std::vector<double> roll_rates;

    // Simulation
    while (t <= simulation_time) {  // Corrected the loop termination condition
        double delta = 0.0;
        // Aileron deflection for 2 seconds
        if (t <= duration_deflection) {
            delta = max_aileron_deflection;
        }

        // Roll rate calculation for the next time step
        p = roll_rate_calculation(p, delta, time_step);
        // Storing the roll rate in the vector
        roll_rates.push_back(p);
        // Printing the result for simulation at each current time step
        std::cout << "Simulation Time (seconds): " << t << " Rolling Rate (radian/seconds): " << p << std::endl;
        // Time update
        t += time_step;  // Updated the time
    }

    return 0;
}

