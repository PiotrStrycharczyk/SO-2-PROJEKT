#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <vector>
#include <mutex>
#include <memory>  // For std::unique_ptr

class Philosopher {
public:
    static int philosopherCount;
    static std::vector<std::unique_ptr<std::mutex>> forks;  // Vector of mutex pointers
    static std::vector<std::string> states;

    static void createForks(int count);
    void updateDisplay();
    void dine(int id);
    void eat(int id);
    void think(int id);
};

#endif // PHILOSOPHER_H
