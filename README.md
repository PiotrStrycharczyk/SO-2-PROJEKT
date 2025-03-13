The Dining-Philosophers Problem

semafors ---> forks


when one philosopher tries grab a fork ---> executing a wait() on semaphore
//eating, doing nothing
releasing his fork by executing signal() on the appropriate semaphores

If some of the Philosopher takes fork nobody else can take it also.

semaphore chopstick[5];
initialization all emenets of chopsticks to 1(free) 0 means its used by 
some process
Using only semaphores still can create a deadlock lets suppose that all 
philosophers want to eat at the same time and each grabs their left chopstick
All the lements of chopstick will now be equal to 0
When each philosopher tries to grab his right chopstick he will be delayed forever
How to solve it? If philosopher wants to eat we can give him this oportunity
only if both of his chopsticks are available

Philospphers represent proceses
Chopsticks represent resources
Thread(philo) which want to use Chopstick is blocking mutex