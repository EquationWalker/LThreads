#include "../include/LThread.h"
#include "../include/LMutexLocker.h"

LThread::LThread(LRunnable *fun) noexcept
{
    runnable = fun;
}

LThread::~LThread() noexcept
{
    wait();
}

void LThread::start() noexcept
{
    LMutexLocker locker(&mutex);
    if (running)
        return;
    running = true;
    finished = false;
    detached = false;
    pthread_create(&pth, NULL, threadFunc, reinterpret_cast<void *>(this));
}

void LThread::detach() noexcept
{
    LMutexLocker locker(&mutex);
    if (!running)
        return;
    pthread_detach(pth);
    detached = true;
}

void LThread::wait() noexcept
{
    LMutexLocker locker(&mutex);
    if (running && !detached)
        locker.unlock(), pthread_join(pth, NULL);
}

bool LThread::isRuning() const noexcept
{
    LMutexLocker locker(&mutex);
    return running;
}

bool LThread::isFinished() const noexcept
{
    LMutexLocker locker(&mutex);
    return finished;
}

bool LThread::isDetached() const noexcept
{
    LMutexLocker locker(&mutex);
    return detached;
}

void LThread::run() noexcept
{
    if (runnable != nullptr)
        runnable->run();
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

void *LThread::threadFunc(void *arg) noexcept
{
    pthread_cleanup_push(LThread::finish, arg);
    LThread *thr = reinterpret_cast<LThread *>(arg);
    thr->run();
    pthread_cleanup_pop(1);
    return nullptr;
}

void LThread::finish(void *arg) noexcept
{
    LThread *thr = reinterpret_cast<LThread *>(arg);
    LMutexLocker locker(&thr->mutex);
    thr->running = false;
    thr->finished = true;
}