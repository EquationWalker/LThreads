#pragma once
#include "LMutex.h"

class LWaitCondition final
{
    L_DISABLE_COPY(LWaitCondition)
public:
    LWaitCondition() noexcept;
    ~LWaitCondition() noexcept;

    // The calling thread must ensure that mutex is locked
    void wait(LMutex *mutex) noexcept;
    void wakeOne() noexcept;
    void wakeAll() noexcept;

private:
    pthread_cond_t cond;
};