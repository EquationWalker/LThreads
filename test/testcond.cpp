#include "../include/LWaitCondition.h"
#define NUM_THREADS  3
#define TCOUNT 10
#define COUNT_LIMIT 12

int count = 0;
LMutex count_mutex;
LWaitCondition count_threshold_cv;

void *inc_count(void *t) //增加count
{
    int i;
    long my_id = (long)t;

    for (i=0; i < TCOUNT; i++)
    {
        count_mutex.lock();
        count++;

        if (count == COUNT_LIMIT) //满足条件后
        {
            printf("inc_count(): thread %ld, count = %d  Threshold reached. ",my_id, count);
            count_threshold_cv.wakeOne();//通知
            printf("Just sent signal.\n");
        }
        printf("inc_count(): thread %ld, count = %d, unlocking mutex\n",my_id, count);

        //这里释放锁的同时 sleep 1 秒中可以保证线程2和线程3交替获得锁并执行
        count_mutex.unlock();
        sleep(1);
    }//end for
    pthread_exit(NULL);
}

void *watch_count(void *t) //检查条件变量
{
    long my_id = (long)t;

    printf("Starting watch_count(): thread %ld\n", my_id);

    count_mutex.lock();
    while (count < COUNT_LIMIT)//这里用while防止虚假唤醒
    {
        printf("watch_count(): thread %ld Count= %d. Going into wait...\n", my_id,count);
        count_threshold_cv.wait(&count_mutex);//阻塞后自动释放锁
        printf("watch_count(): thread %ld Condition signal received. Count= %d\n", my_id,count);
        printf("watch_count(): thread %ld Updating the value of count...\n", my_id,count);
        count += 125;
        printf("watch_count(): thread %ld count now = %d.\n", my_id, count);
    }
    printf("watch_count(): thread %ld Unlocking mutex.\n", my_id);
    count_mutex.unlock();
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int i, rc; 
    long t1=1, t2=2, t3=3;
    pthread_t threads[3];//3个线程
    pthread_attr_t attr;//attr


    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_create(&threads[0], &attr, watch_count, (void *)t1);//线程1关注count值
    pthread_create(&threads[1], &attr, inc_count, (void *)t2);//线程2增加count值
    pthread_create(&threads[2], &attr, inc_count, (void *)t3);//线程3增加count值

    for (i = 0; i < NUM_THREADS; i++) 
        pthread_join(threads[i], NULL);
    //等待所有线程完成
    
    printf ("Main(): Waited and joined with %d threads. Final value of count = %d. Done.\n", NUM_THREADS, count);

    /* Clean up and exit */
    pthread_attr_destroy(&attr);
    pthread_exit (NULL);

}
