//
// Created by Piotr on 13.03.2025.
//

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H
#include "Semaphore.h"


class Philosopher {
public:
    void doWork();
    void wait();//want to grab a fork
    void signal();//releasing his fork

    std::vector<Semaphore> semaphores;
    void getSemaphores(std::vector<Semaphore> &);

};



#endif //PHILOSOPHER_H
