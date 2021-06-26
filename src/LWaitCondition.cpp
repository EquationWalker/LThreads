#include "../include/LWaitCondition.h"

LWaitCondition::LWaitCondition() noexcept
{
    pthread_cond_init(&cond, NULL);
}

LWaitCondition::~LWaitCondition() noexcept
{
    pthread_cond_destroy(&cond);
}

void LWaitCondition::wait(LMutex *mutex) noexcept
{
    assert(mutex != NULL); // cannot null
    pthread_cond_wait(&cond, &mutex->mutex);
}

void LWaitCondition::wakeOne() noexcept
{
    pthread_cond_signal(&cond);
}

void LWaitCondition::wakeAll() noexcept
{
    pthread_cond_broadcast(&cond);
}