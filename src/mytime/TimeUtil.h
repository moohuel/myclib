/*
 * TimeUtil.h
 *
 *  Created on: Aug 23, 2012
 */

#include <sys/time.h>

#ifndef TIMEUTIL_H_
#define TIMEUTIL_H_

namespace mytime
{

class TimeUtil
{
public:
	TimeUtil();
	virtual ~TimeUtil();

	static void myMillisecSleep(int intervalMilisecond);
	static timeval currentTime();
};

} /* namespace epub_httpd */
#endif /* TIMEUTIL_H_ */
