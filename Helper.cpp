//
// Created by Piotr on 13.03.2025.
//

#include "Helper.h"
#include <iostream>


int Helper::getCountOfPhilosophers() {
    std::cout<<"Philosophers count: ";
    std::cin.clear(); // Clear the error flag
    std::cin >> countOfPhilosophers;
    std::cout<<"Count of philosophers: "<<countOfPhilosophers << std::endl;
    return countOfPhilosophers;
}
