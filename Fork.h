//
// Created by Piotr on 13.03.2025.
//

#ifndef FORK_H
#define FORK_H
// #include <mutex>


class Fork {
public:
    Fork(int state);
    int state = 0;//0 means locked 1 means free
    static int count;//num of all chopsticks
    int index;

    // std::mutex fork_mutex;  // Each fork gets its own mutex


};



#endif //FORK_H
