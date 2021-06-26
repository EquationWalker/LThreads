#pragma once
#include "common.h"
#include "LRunnable.h"

class LThread
{
    L_DISABLE_COPY(LThread)
public:
    typedef pthread_t HANDLE;

    LThread(LRunnable *fun) noexcept;
    ~LThread() noexcept;

    void start() noexcept;
    void detach() noexcept;

    void wait() noexcept;

    virtual void run() noexcept;

    static HANDLE currentThreadId() noexcept;
    static void exit() noexcept;

private:
    HANDLE pth;
    LRunnable *runnable = nullptr;
    bool isRunning = false;
    bool isDetached = false;

    static void *threadFunc(void *arg) noexcept;
};