#pragma once
#include "LMutex.h"

class LMutexLocker final
{
    L_DISABLE_COPY(LMutexLocker)
public:
    inline explicit LMutexLocker(LMutex *mutex) noexcept
    {
        assert(mutex != NULL); // cannot null

        this->mutex = mutex;
        isLock = true;
        mutex->lock();
    }

    inline ~LMutexLocker() noexcept
    {
        unlock();
    }

    inline void relock() noexcept
    {
        if (!isLock)
            mutex->lock();
    }
    inline void unlock() noexcept
    {
        if (isLock)
            mutex->unlock(), isLock = false;
    }

private:
    LMutex *mutex;
    bool isLock;
};