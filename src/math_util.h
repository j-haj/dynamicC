#ifndef __MATH_UTIL_H
#define __MATH_UTIL_H

long nearest_power_2(long n)
{
	long base = 2;
	while (base < n)
		base *= 2;
	return base;
}

#endif // __MATH_UTIL_H
