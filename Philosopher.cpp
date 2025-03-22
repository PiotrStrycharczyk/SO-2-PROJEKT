#include "Philosopher.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

int Philosopher::philosopherCount;
std::vector<std::unique_ptr<std::mutex>> Philosopher::forks;
std::vector<std::string> Philosopher::states; //not in use yet

void Philosopher::createForks(int count) {
    forks.clear();
    states.resize(count, "Thinking"); // Ustawienie początkowego stanu
    for (int i = 0; i < count; i++) {
        forks.push_back(std::make_unique<std::mutex>());
    }
}

void Philosopher::updateDisplay() {
    std::cout << "\r";
    for (const auto &state : states) {
        std::cout << state << " | ";
    }
    std::cout << std::flush;
}

void Philosopher::eat(int id) {
    int leftFork = id;
    int rightFork = (id + 1) % philosopherCount;

    std::cout << "Philosopher " << id << " is hungry." << std::endl;

    std::unique_lock leftLock(*forks[leftFork], std::defer_lock);//uniqe lock is like menager(wrapper) of each mutex when unique lock is destroyed for ex mutex is blocked
    std::unique_lock rightLock(*forks[rightFork], std::defer_lock);//preapring 'lock' which will be closed later
    //dereferention of pointer

    std::lock(leftLock, rightLock);//closing

    std::cout << "Philosopher " << id << " is eating." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "Philosopher " << id << " has finished eating." << std::endl;

}

void Philosopher::think(int id) {
    std::cout << "Philosopher " << id << " is thinking." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Philosopher::dine(int id) {
    while (true) {
        think(id);
        eat(id);
    }
}
