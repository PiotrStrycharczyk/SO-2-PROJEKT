#include "Program.h"
#include "Helper.h"
#include "Philosopher.h"

#include <iostream>
#include <vector>
#include <thread>

void Program::mainProgram() {
    Helper helper;
    Philosopher::philosopherCount = helper.getCountOfPhilosophers();
    int philosophers = Philosopher::philosopherCount;

    Philosopher::createForks(philosophers); // Static function to create forks

    std::vector<std::thread> threads;
    std::vector<Philosopher> philos;

    for (int i = 0; i < philosophers; i++) {
        philos.emplace_back();  // Create philosopher objects
    }

    for (int i = 0; i < philosophers; i++) {
        threads.emplace_back(&Philosopher::dine, &philos[i], i);
    }

    for (auto &t : threads) {
        t.join(); // Wait for all philosophers to finish
    }

    std::cout << "All philosophers have finished eating.\n";
}
