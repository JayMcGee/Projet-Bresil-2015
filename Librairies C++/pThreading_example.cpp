/*
 * TestMultiThreading.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: Pat's Machine
 */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MODULE_NAME            "TestMultiThreading"
#define MODULE_AUTHOR          "Patrick Ireland"
#define MODULE_VERSION         "2014-03-27 16:30"
#define MOUDLE_PROCESSOR       "BeagleBoneBlack"
#define MODULE_LANGUAGE        "C++"
#define MODULE_TYPE            "source"
#define MODULE_WHO_AM_I        "TMUL"

class TestThread
{
#define ANSWER_TO_THE_UNIVERSE 42

private:
	sem_t                    * ptrStartSemaphore;
	pthread_mutex_t          * ptrPThreadMutex;

public:
	TestThread(sem_t * argPtrStartSemaphore, pthread_mutex_t * argPtrPThreadMutex)
	{
		printf("%s - ENTER TestThread::TestThread()\n", MODULE_WHO_AM_I);
		ptrStartSemaphore = argPtrStartSemaphore;
		ptrPThreadMutex = argPtrPThreadMutex;
	}   // TestThread()

	~TestThread(void)
	{
	}   // ~TestThread()

	int threadMain(void)
	{
		printf("%s - ENTER TestThread::threadMain()\n", MODULE_WHO_AM_I);
		int executionCount = 0;
		sem_wait(ptrStartSemaphore);
		printf("%s - ENTER TestThread Method loop\n", MODULE_WHO_AM_I);
		while(true)
	    {
	    	pthread_mutex_lock(ptrPThreadMutex);
	    	printf("%s - method 3 execution %d\n", MODULE_WHO_AM_I, ++executionCount);
	    	pthread_mutex_unlock(ptrPThreadMutex);
	    	if (executionCount > 20) break;
	    	sleep(1);
	    }   // while(true)
		pthread_exit(0);
		return(ANSWER_TO_THE_UNIVERSE);
	}   // int threadMain()
};

void * thread1Method(void * argv);
void * thread2Method(void * args);
void * thread3Method(void * argv);

// Used to pass addresses of sem and mutex to threads
typedef struct ThreadData
{
    sem_t                * ptrSem;
    pthread_mutex_t      * ptrMutex;
}  threadData, * ptrThreadData;

#define ARGV_PROGRAM_NAME      0
#define ARGV_COUNT             1

int main (int argc, char ** argv)
{
    printf("%s - ENTER %s\n", MODULE_WHO_AM_I, argv[ARGV_PROGRAM_NAME]);
    printf("%s - %s version %s\n", MODULE_WHO_AM_I, MODULE_NAME, MODULE_VERSION);
    printf("%s - argc = %d\n", MODULE_WHO_AM_I, argc);

    for (int idxArgv = 0; idxArgv < argc; idxArgv++)
    {
        printf ("%s - argv[%d] = %s\n", MODULE_WHO_AM_I, idxArgv, argv[idxArgv]);
    }   // for (int idxArgv = 0; idxArgv < argc; idxArgv++)

    printf("%s - semaphore inits\n", MODULE_WHO_AM_I);
    sem_t                          sem1;
    sem_t                          sem2;
    sem_t                          sem3;
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);

    printf("%s - mutex init\n", MODULE_WHO_AM_I);
    pthread_mutex_t                mutex;
    pthread_mutex_init(&mutex, NULL);

    printf("%s - prepare data for threads\n", MODULE_WHO_AM_I);
    threadData myData1;
    myData1.ptrSem = &sem1;
    myData1.ptrMutex = &mutex;

    threadData myData2;
    myData2.ptrSem = &sem2;
    myData2.ptrMutex = &mutex;

    threadData myData3;
    myData3.ptrSem = &sem3;
    myData3.ptrMutex = &mutex;

    printf("%s - create the threads\n", MODULE_WHO_AM_I);
    pthread_t                  threadID1;
    pthread_t                  threadID2;
    pthread_t                  threadID3;
    pthread_create(&threadID1, NULL, thread1Method, (void *) &myData1);
    pthread_create(&threadID2, NULL, thread2Method, (void *) &myData2);
    pthread_create(&threadID3, NULL, thread3Method, (void *) &myData3);

    printf("%s - let threads execute\n", MODULE_WHO_AM_I);
    sem_post(&sem1);
    sem_post(&sem2);
    sem_post(&sem3);
    sleep(40);
    return (0);
}   // int main ()

// Thread 1 is method example
void * thread1Method(void * argv)
{
	printf("%s - ENTER thread1Method\n", MODULE_WHO_AM_I);
	sem_t                    * ptrSem = ((ptrThreadData) argv)->ptrSem;
	pthread_mutex_t          * ptrMutex = ((ptrThreadData) argv)->ptrMutex;
	int executionCount = 0;
	sem_wait(ptrSem);
	printf("%s - ENTER thread1Method loop\n", MODULE_WHO_AM_I);
	while(true)
    {
    	pthread_mutex_lock(ptrMutex);
    	printf("%s - method 1 execution %d\n", MODULE_WHO_AM_I, ++executionCount);
    	pthread_mutex_unlock(ptrMutex);
    	if (executionCount > 20) break;
    	sleep(1);
    }   // while(true)
	pthread_exit(0);
	return NULL;
}   // void * thread1Method(void * args)

// Thread 2 is method example
void * thread2Method(void * argv)
{
	printf("%s - ENTER thread2Method\n", MODULE_WHO_AM_I);
	sem_t                    * ptrSem = ((ptrThreadData) argv)->ptrSem;
	pthread_mutex_t          * ptrMutex = ((ptrThreadData) argv)->ptrMutex;
	int executionCount = 0;
    sem_wait(ptrSem);
	printf("%s - ENTER thread2Method loop\n", MODULE_WHO_AM_I);
    while(true)
    {
    	pthread_mutex_lock(ptrMutex);
    	printf("%s - method 2 execution %d\n", MODULE_WHO_AM_I, ++executionCount);
    	pthread_mutex_unlock(ptrMutex);
    	sleep(2);
    	if (executionCount > 20) break;
    }   // while(true)
	pthread_exit(0);
	return NULL;
}   // void * thread2Method(void * args)

// Thread 3 is class example
void * thread3Method(void * argv)
{
	printf("%s - ENTER thread3Method\n", MODULE_WHO_AM_I);
	sem_t                    * ptrSem = ((ptrThreadData) argv)->ptrSem;
	pthread_mutex_t          * ptrMutex = ((ptrThreadData) argv)->ptrMutex;
    printf("%s - create class\n", MODULE_WHO_AM_I);
    TestThread * ptrTestThread = new TestThread(ptrSem, ptrMutex);
    int threadStatus = ptrTestThread->threadMain();
	printf("%s - LEAVE thread3Method, threadStatus = %d\n", MODULE_WHO_AM_I, threadStatus);
    return NULL;
}   // void * thread3Method(void *)