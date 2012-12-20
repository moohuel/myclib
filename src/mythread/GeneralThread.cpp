/*
 * GeneralThread.cpp
 *
 *  Created on: Jun 6, 2012
 */

#include "GeneralThread.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

using namespace mythread;

GeneralThread::GeneralThread()
{
	isMutxCreated = false;
	isConditionInitiated = false;

	initMutex();
	initCondition();
}

GeneralThread::~GeneralThread()
{
}

bool GeneralThread::start()
{
	int result = pthread_create(&threadObj, NULL, &GeneralThread::runJob, this);

	if(result != 0)
	{
		printf("pthread_create fail. result=%d \n", result);
		return false;
	}
	return true;
}

void GeneralThread::run()
{
	printf("---------- run --------------\n");
}

void GeneralThread::join()
{
	pthread_join(threadObj, NULL);
}

void GeneralThread::wait()
{
	pthread_cond_wait(&threadCond, &mutx);
}

void GeneralThread::wait(int timeSecond)
{
	timeval tv;
	gettimeofday(&tv, NULL);

	timespec ts;
	ts.tv_sec = tv.tv_sec + timeSecond;
	ts.tv_nsec = tv.tv_usec * 1000;

	int result = pthread_cond_timedwait(&threadCond, &mutx, &ts);
}

void GeneralThread::notify()
{
	int result = pthread_cond_signal(&threadCond);
}

void GeneralThread::notifyAll()
{
	int result = pthread_cond_broadcast(&threadCond);
}

//private
void* GeneralThread::runJob(void* me)
{
	GeneralThread *generalThread = (GeneralThread*)me;
	generalThread->run();
	return NULL;
}

void GeneralThread::initMutex()
{
	if(isMutxCreated == true)
		return;

	int mutxInitResult = pthread_mutex_init(&mutx, NULL);
	if(mutxInitResult != 0)
	{
		printf("pthread_mutex_init fail. result=%d \n", mutxInitResult);
	}
	else
	{
		isConditionInitiated = true;
	}
}

void GeneralThread::initCondition()
{
	//threadCond = PTHREAD_COND_INITIALIZER; // warning: extended initializer lists only available with -std=c++0x or -std=gnu++0x
	if(isConditionInitiated == true)
		return;

	int result = pthread_cond_init(&threadCond, NULL);
	if(result != 0)
	{
		printf("initCondition fail. result=%d \n", result);
	}
	else
	{
		isConditionInitiated = true;
	}
}
