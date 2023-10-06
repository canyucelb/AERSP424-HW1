//
//  question_2.cpp
//  yucel_homework1
//
//  Created by BARAN CAN YUCEL on 10/5/23.
//



#include <iostream>
#include <vector>
#include<cstdlib>
#include<ctime>
#include "question_2.hpp"


// Question 2
// With ∆𝑡 = 0.01 𝑠 and this feedback control law, write a program to predict the roll rate of the aircraft up to 5 seconds and print out the result at every time step.

//  Roll damping coefficient and aileron effectiveness is picked randomly from interval [-1,1]
// the time step is given 0.01 seconds and total simulation time is 5 seconds.
// initial roll rate is given 1 radian / second

// Defining the constants for the solution
const double lp = 0.19, time_step = 0.01, simulation_time = 5.0, initial_roll_rate = 1.0;

// Function for calculating the roll rate for next time steps with feedback control law delta_t = -K * pt

double roll_rate_calculation(double p, double K, double delta_t) {
    return p + (lp * p - K * p) * delta_t;

    // initialized the formula for autopilot with a feedback control law given in the question

}

int main() {
    // random number selection for feedback value to control gain K in [-3,3] interval
    unsigned long seed = static_cast<unsigned long>(std::time(0));
    std::srand(static_cast<unsigned int>(seed));
    int random_int = std::rand() % 6001 - 3000;
    // Scaling random integer to for obtain K variable in [-3,3] range
    double K = static_cast<double>(random_int) / 1000.0;
    // Initializing the rolling rate and time
    double p = initial_roll_rate, t = 0.0;
    // Creating a vector for storing roll rate for each time step
    std::vector<double> roll_rates;

    // Simulation
    while (t <= simulation_time) {  // Corrected the loop termination condition
        // Roll rate calculation for the next time step
        p = roll_rate_calculation(p, K, time_step);
        // Storing the roll rate in the vector
        roll_rates.push_back(p);
        // Printing the result for simulation at each current time step
        std::cout << "Simulation Time (seconds): " << t << " Rolling Rate (radian/seconds): " << p << std::endl;
        // Time update
        t += time_step;  // Updated the time
    }

    return 0;
}
