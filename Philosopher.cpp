//
// Created by Piotr on 13.03.2025.
//

#include "Philosopher.h"

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Mutex for synchronisation
int Philosopher::sharedCounter = 0;
std::vector<Fork> Philosopher::forks;

Philosopher::Philosopher() {}

void Philosopher::createForks(int count) {
    for(int i = 0 ; i < count ; i++) {
        Fork fork(1);//all of them initially are free (1)
        fork.index = i;
        forks.push_back(fork);
    }
}

bool Philosopher::pickFork(int index) {
    std::lock_guard<std::mutex> lock(mtx);
    if (forks[index].state == 1) {
        forks[index].state = 0;
        return true;
    }
    return false;
}


void Philosopher::eat(int id) {
    std::cout<<"Philosopher "<< id <<" is hungry: "<<std::endl;
    int leftFork = id;
    int rightFork = (id + 1) % sharedCounter;

    // Try to pick up both forks atomically
    if (!pickFork(leftFork) || !pickFork(rightFork)) {
        if (pickFork(leftFork)) forks[leftFork].state = 1; // Release left fork if right fork isn't available
        return;
    }

    // Eating
    std::cout << "Philosopher " << id << " is eating.\n";
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Simulate eating

    // Release both forks after eating
    putOffFork(id);
}

void Philosopher::putOffFork(int id) {
    int leftFork = id;
    int rightFork = (id + 1) % sharedCounter;

    std::lock_guard<std::mutex> lock(mtx); // Lock mutex to modify forks safely

    forks[leftFork].state = 1;  // Release left fork
    forks[rightFork].state = 1; // Release right fork

    std::cout << "Philosopher " << id << " has finished eating.\n";
}

void Philosopher::think(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));//thinking for 0.5s
    std::cout<<"Philosopher "<<id<<" is thinking"<<std::endl;
}

void Philosopher::dine(int id) {//infinity loop
    while (true) {
        think(id);
        eat(id);
    }
}
