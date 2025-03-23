_**The Dining-Philosophers Problem**_

1. Run Project\
To run project type in cmd in directory with project:\
g++ -o program main.cpp Program.cpp Philosopher.cpp Helper.cpp -static\
program


2. Problem\
There are n philosophers sitting next to each other at a table, with n forks available.
Each philosopher can be in one of two states:
Thinking – the philosopher sits and does nothing (simulated by a 1-second wait).
Eating – the philosopher picks up two forks, eats for 5 seconds, and then releases the forks.
If a fork is already taken by another philosopher, it cannot be used at the same time.
This can lead to a deadlock, where philosophers are stuck waiting indefinitely because 
each one is holding a fork and waiting for the other fork to become available.
In this problem, philosophers represent processes, and forks represent resources.


3. Threads and critical sections\
Each philosopher is represented by a separate thread.
Each thread runs an infinite loop, continuously alternating between thinking and eating.
A deadlock occurs when multiple philosophers (threads) are waiting for forks that are 
already held by others, creating a circular dependency where no philosopher can proceed.
Synchronization Mechanism:
Forks are stored in a std::vector of mutexes – each mutex represents a single fork.
A fork (mutex) can only be locked by one philosopher at a time.
If a fork is already in use, the philosopher waits until it is released.
Philosophers must acquire both forks before they can eat.

Key Functions:
std::lock() – Locks the mutex, preventing other threads from accessing the resource.

std::unlock() – Releases the mutex, making the fork available to other philosophers.


