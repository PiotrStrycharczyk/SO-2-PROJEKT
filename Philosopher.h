//
// Created by Piotr on 13.03.2025.
//

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H
#include "Fork.h"
#include <vector>


class Philosopher {
public:
    Philosopher();  // Constructor
    static int sharedCounter;

    void eat(int id);//want to grab a fork
    void think(int id);
    void dine(int id);
    static void createForks(int count);
    static std::vector<Fork> forks;

    void putOffFork(int id);
    bool pickFork(int index);


};



#endif //PHILOSOPHER_H
