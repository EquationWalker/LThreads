#include "../include/LMutex.h"

LMutex::LMutex(RecursiveMode mode) noexcept
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    if (mode == Recursive)
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex, &attr);
}
LMutex::~LMutex() noexcept
{
    pthread_mutex_destroy(&mutex);
}
void LMutex::lock() noexcept
{
    pthread_mutex_lock(&mutex);
}

bool LMutex::tryLock() noexcept
{
    return 0 == pthread_mutex_trylock(&mutex);
}

void LMutex::unlock() noexcept
{
    pthread_mutex_unlock(&mutex);
}