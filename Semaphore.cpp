//
// Created by Piotr on 13.03.2025.
//

#include "Semaphore.h"

int Semaphore::count = 0;

void Semaphore::initChopsticks(std::vector<Semaphore> & semaphores) {
    for(int i = 0 ; i < count ; i++) {
        Semaphore semaphore;
        semaphores[0].state = 1;//all free
    }
}

void Semaphore::setArray(std::vector<Philosopher> &phi) {
    philosophs = phi;
}
