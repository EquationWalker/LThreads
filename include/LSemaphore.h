#pragma once
#include "common.h"
#include <semaphore.h>

class LSemaphore final
{
    L_DISABLE_COPY(LSemaphore)
public:
    explicit LSemaphore(int n = 1) noexcept;
    ~LSemaphore() noexcept;

    void acquire() noexcept;
    void tryAcquire() noexcept;

    int available() const;
    void release(int n = 1) noexcept;

private:
    mutable sem_t sem;
};