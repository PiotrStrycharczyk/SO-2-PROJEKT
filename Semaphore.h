//
// Created by Piotr on 13.03.2025.
//

#ifndef SEMAPHORE_H
#define SEMAPHORE_H
#include <vector>

#include "Philosopher.h"


class Semaphore {
public:
    int state = 0;//0 means locked 1 means free
    static int count;//num of all chopsticks
    std::vector<Philosopher> philosophs;

    void initChopsticks(std::vector<Semaphore> &);
    void setArray(std::vector <Philosopher> &);

};



#endif //SEMAPHORE_H
