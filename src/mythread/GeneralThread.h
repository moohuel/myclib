/*
 * GeneralThread.h
 *
 *  Created on: Jun 6, 2012
 */

#ifndef GeneralThread_H_
#define GeneralThread_H_

#include <pthread.h>

namespace mythread
{

class GeneralThread
{
private:
	pthread_t threadObj;
	bool isMutxCreated;
	bool isConditionInitiated;

protected:
	pthread_mutex_t mutx;
	pthread_cond_t threadCond;

public:
	GeneralThread();
	virtual ~GeneralThread();

	bool start();
	virtual void run();
	void join();
	void wait();
	void wait(int timeSecond);
	void notify();
	void notifyAll();

private:
	static void* runJob(void* me);
	void initMutex();
	void initCondition();
};

}

#endif /* GeneralThread_H_ */
