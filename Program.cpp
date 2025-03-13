//
// Created by Piotr on 13.03.2025.
//

#include "Program.h"

// #include <vector>

#include "Helper.h"

#include "Semaphore.h"

void Program::mainProgram() {
    Helper helper;
    int philosophers = helper.getCountOfPhilosophers();//gettin how many philosophers are there

    Semaphore::count = philosophers;//initialization of number of semphores

    std::vector<Semaphore> chopsticks(Semaphore::count);
    Semaphore initilization;
    initilization.initChopsticks(chopsticks);


    std::vector<Philosopher> philosophs(philosophers);
    Semaphore example;
    example.setArray(philosophs);

    // Philosopher philo;
    // philo.getSemaphores(chopsticks);//
    //zastapic to wskaznikamixD

    philosophs[0].doWork();


    for(int i = 0 ; i < philosophers ; i++) {


    }



}
