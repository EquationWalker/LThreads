#pragma once
#include "LMutex.h"

class LWaitCondition final 
{
public:
    LWaitCondition();
    ~LWaitCondition();

    void wait(LMutex* mutex);
    void wakeOne();
    void wakeAll();
private:
    pthread_cond_t cond;
    L_DISABLE_COPY(LWaitCondition)
};