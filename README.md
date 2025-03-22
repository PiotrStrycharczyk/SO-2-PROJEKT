_**The Dining-Philosophers Problem**_

1. Run Project\
To run project type in cmd in directory with project:\
a) g++ -o program main.cpp Program.cpp Philosopher.cpp Helper.cpp -static\
b) program

2. Problem\
There are n philosophers siting next to each other on the table. There are also n Forks.
Philosopher can be in 2 states: eating state or thinking state. Eating means taking
2 forks and in this situtaion neighbour can't eat. 
If some of the Philosophers takes fork nobody else can take it also. It can lead to
a deadlock where philosophers can't eat bacause of not free forks.
Thinking means sitting next to the table and doing nothing.
Philosophers represent proceses and forks represent resources.

3. Threads and critical sections\
Each philosopher represent one thread. Every thread is in infinity while loop
(thinking then eating etc.)\
\
A deadlock occurs when multiple threads (or philosophers, in this case) 
are waiting on resources (forks) that are being held by other threads,
creating a circular dependency where no thread can proceed.\
In my code if a fork is in use by another philosopher, the current philosopher will be blocked.
The philosopher will wait until both forks are available before proceeding.\
My forks are being hold in vector. Vector of mutexes. Each mutex represent one fork.\
forks ---> vector of mutexes representing forks.\
std::unique_lock is to acquire the mutex lock\
std::defer_lock argument means that the lock is not acquired immediately\
std::lock ---> lock all passed arguments at the same time guarantees deadlock-free
beahaviour

