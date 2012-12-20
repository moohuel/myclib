/*
 * TimeUtil.cpp
 *
 *  Created on: Aug 23, 2012
 */

#include "TimeUtil.h"
#include <pthread.h>

using namespace mytime;

TimeUtil::TimeUtil()
{

}

TimeUtil::~TimeUtil()
{
}

void TimeUtil::myMillisecSleep(int intervalMillisecond)
{
	long sec = 0;
	long milliSec = intervalMillisecond;

	if(intervalMillisecond >= 1000)
	{
		sec = intervalMillisecond / 1000;
		milliSec = intervalMillisecond % 1000;
	}

	timespec tv;
	tv.tv_sec = sec;
	tv.tv_nsec = milliSec * 1000000l;

	nanosleep(&tv, NULL);
}

timeval TimeUtil::currentTime()
{
	timeval curTime;
	gettimeofday(&curTime, NULL);
	return curTime;
}

