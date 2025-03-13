//
// Created by Piotr on 13.03.2025.
//

#include "Philosopher.h"

void Philosopher::wait() {//he tries to grab a fork

}

void Philosopher::signal() {

}

void Philosopher::doWork() {
    wait();
}

void Philosopher::getSemaphores(std::vector<Semaphore> & sema) {
    semaphores = sema;
}
