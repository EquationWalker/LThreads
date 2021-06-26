#include "../include/LSemaphore.h"

LSemaphore::LSemaphore(int n)
{
    if (n < 0)
        n = 0;
    sem_init(&sem, 0, n);
}

LSemaphore::~LSemaphore()
{
    sem_destroy(&sem);
}

void LSemaphore::acquire()
{
    sem_wait(&sem);
}

void LSemaphore::tryAcquire()
{
    sem_trywait(&sem);
}

void LSemaphore::release(int n)
{
    if (n <= 0)
        return;
    while (n--)
        sem_post(&sem);
}

int LSemaphore::available() const
{
    int val;
    sem_getvalue(&sem, &val);
    return val;
}