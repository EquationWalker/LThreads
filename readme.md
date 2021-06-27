# LThreads

## v0.1
    完成LMutex基本封装

## v0.2
    完成LWaitCondition封装

## v0.3
    提供锁的RAII接口

## v0.4
    封装semaphore,修补LMutexLocker

## v0.5
    初步实现LThread, 修补之前一些bug

## v0.6
    支持条件变量定时等待,完善LThread
    缺陷:LThread不是线程安全的,并发调度start将会导致错误