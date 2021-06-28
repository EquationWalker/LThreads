#include "../include/LWaitCondition.h"

LWaitCondition::LWaitCondition() noexcept
{
    pthread_cond_init(&cond, NULL);
}

LWaitCondition::~LWaitCondition() noexcept
{
    pthread_cond_destroy(&cond);
}

void LWaitCondition::wait(LMutex *mutex, unsigned long time) noexcept
{
    assert(mutex != NULL); // cannot null
    if (time < 0)
        time = -time;
    if (0 == time)
        pthread_cond_wait(&cond, &mutex->mutex);
    else
    {
        struct timespec tt;
        tt.tv_sec = time;
        tt.tv_nsec = 0;
        pthread_cond_timedwait(&cond, &mutex->mutex, &tt);
    }
}

void LWaitCondition::wakeOne() noexcept
{
    pthread_cond_signal(&cond);
}

void LWaitCondition::wakeAll() noexcept
{
    pthread_cond_broadcast(&cond);
}