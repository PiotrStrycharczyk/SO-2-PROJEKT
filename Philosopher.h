#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <vector>
#include <mutex>
#include <memory>  // For std::unique_ptr

class Philosopher {
public:
    static int sharedCounter;
    static std::vector<std::unique_ptr<std::mutex>> forks;  // Vector of mutex pointers

    static void createForks(int count);
    void dine(int id);
    void eat(int id);
    void think(int id);
};

#endif // PHILOSOPHER_H
