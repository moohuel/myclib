/*
 * YanglibMain.cpp
 *
 *  Created on: Dec 20, 2012
 */

#include <mystring/StringUtil.h>
#include <stdio.h>

using namespace mystring;

int main()
{
	const char* dest = "abcdefg";
	bool found = StringUtil::contains(dest, "abc");
	printf("found=%d\n", found);

	return 0;
}



