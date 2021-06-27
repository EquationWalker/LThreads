#include "../include/LThread.h"

LThread::LThread(LRunnable* fun) noexcept
{
    runnable = fun;
}

LThread::~LThread() noexcept
{
    wait();
}

void LThread::start() noexcept
{
    if (isRunning) return;
    isRunning = true;
    pthread_create(&pth, NULL, threadFunc, reinterpret_cast<void*>(this));
}

void LThread::detach() noexcept
{
    if (!isRunning) return;
    pthread_detach(pth);
    isDetached = true;
}

void LThread::wait() noexcept
{
    if (isRunning && !isDetached)
        pthread_join(pth, NULL), isRunning = false;
}

void LThread::run() noexcept
{
    if (runnable != nullptr) runnable->run();
}

void LThread::yieldCurrentThread() noexcept
{
    sched_yield();
}

void LThread::exit() noexcept
{
    pthread_exit(NULL);
}

LThread::HANDLE LThread::currentThreadId() noexcept
{
    return pthread_self();
}

void* LThread::threadFunc(void* arg) noexcept
{
    LThread* thread = reinterpret_cast<LThread*>(arg);
    thread->run();
}