/*
 * StringUtil.h
 *
 *  Created on: Nov 19, 2012
 */

#ifndef STRINGUTIL_H_
#define STRINGUTIL_H_

namespace mystring
{

class StringUtil
{
public:
	StringUtil();
	virtual ~StringUtil();

	static bool contains(const char* dest, const char* targetCharacters);
	static void trimSpace(char *src, char *dest, int len);
};

} /* namespace epub_httpdd */
#endif /* STRINGUTIL_H_ */
