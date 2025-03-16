//
// Created by Piotr on 13.03.2025.
//
#ifndef FORK_H
#define FORK_H

class Fork {
public:

    Fork(int state);
    int state;//0 means locked 1 means free
    static int count;//num of all chopsticks
    int index;


};


#endif //FORK_H
