#include "Philosopher.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>  // For std::unique_ptr

int Philosopher::sharedCounter = 0;
std::vector<std::unique_ptr<std::mutex>> Philosopher::forks;  // Vector of mutex pointers

void Philosopher::createForks(int count) {
    forks.clear();
    for (int i = 0; i < count; i++) {
        forks.push_back(std::make_unique<std::mutex>());  // Allocate mutex dynamically
    }
}

void Philosopher::eat(int id) {
    int leftFork = id;
    int rightFork = (id + 1) % sharedCounter;

    std::cout << "Philosopher " << id << " is hungry." << std::endl;

    // Lock both forks using std::unique_lock and std::lock()
    std::unique_lock<std::mutex> leftLock(*forks[leftFork], std::defer_lock);
    std::unique_lock<std::mutex> rightLock(*forks[rightFork], std::defer_lock);

    std::lock(leftLock, rightLock);

    std::cout << "Philosopher " << id << " is eating." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate eating

    std::cout << "Philosopher " << id << " has finished eating." << std::endl;
}

void Philosopher::think(int id) {
    std::cout << "Philosopher " << id << " is thinking." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Simulate thinking
}

void Philosopher::dine(int id) {
    while (true) {
        think(id);
        eat(id);
    }
}
