#include "../include/LSemaphore.h"

LSemaphore::LSemaphore(int n) noexcept
{
    assert(n >= 0);
    sem_init(&sem, 0, n);
}

LSemaphore::~LSemaphore() noexcept
{
    sem_destroy(&sem);
}

void LSemaphore::acquire() noexcept
{
    sem_wait(&sem);
}

bool LSemaphore::tryAcquire() noexcept
{
    return 0 == sem_trywait(&sem);
}

void LSemaphore::release(int n) noexcept
{
    if (n <= 0)
        return;
    while (n--)
        sem_post(&sem);
}

int LSemaphore::available() const noexcept
{
    int val;
    sem_getvalue(&sem, &val);
    return val;
}