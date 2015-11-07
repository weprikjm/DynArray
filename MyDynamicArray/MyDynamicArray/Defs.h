#ifndef __DEFS_H__ 
#define __DEFS_H__

typedef unsigned int uint;

#define MAX(a,b) (a > b) ? a : b
#define MIN(a,b) (a < b) ? a : b	

#define DYNARRAYBLOCK 32

template
<class TYPE>
void Swap(TYPE& a, TYPE& b)
{
	TYPE c = b;
	b = a;
	a = c;
}







#define NULL 0

#endif