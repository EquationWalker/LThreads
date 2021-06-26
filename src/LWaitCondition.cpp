#include "../include/LWaitCondition.h"

LWaitCondition::LWaitCondition()
{
    pthread_cond_init(&cond, NULL);
}

LWaitCondition::~LWaitCondition()
{
    pthread_cond_destroy(&cond);
}

void LWaitCondition::wait(LMutex* mutex)
{
    pthread_cond_wait(&cond, &mutex->mutex);
}

void LWaitCondition::wakeOne()
{
    pthread_cond_signal(&cond);
}

void LWaitCondition::wakeAll()
{
    pthread_cond_broadcast(&cond);
}