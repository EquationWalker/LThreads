#include "../include/LRunnable.h"
#include "../include/LThread.h"
#include "../include/LMutexLocker.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

LMutex mutex;

class MyRunnable : public LRunnable
{
public:
    void run() noexcept
    {
        LMutexLocker locker(&mutex);
        for (int i = 1; i < 3; i++)
            cout << "thread id " << LThread::currentThreadId() << endl;
    }
};

int main()
{
    MyRunnable a;

    LThread *ths[4];

    for (int i = 0; i < 4; i++)
    {
        ths[i] = new LThread(&a);
        ths[i]->start();
    }

    for (int i = 0; i < 4; i++)
    {
        ths[i]->wait();

        delete ths[i];
    }

   // delete[] ths;

    return 0;
}
