#include "Defs.h"
#include "MyDynamicArray.h"
#include <iostream>

typedef unsigned int uint;

int main()
{
	MyDynamicArray<int> hello;

	hello.PushBack(0);
	hello.PushBack(1);
	hello.PushBack(2);
	hello.PushBack(3);
	hello.PushBack(4);
	hello.PushBack(5);
	hello.PushBack(6);
	hello.PushBack(7);

	int i = 0;
	//hello.Pop(i);

	int num = 10;
	MyDynamicArray<int> bye(num);
	
	hello.Find(3);



	hello.MultiplePop(&bye,num);
	hello.ShowInt();
	printf("\n\n");
	bye.ShowInt();
	bye.Flip();
	bye.ShowInt();
	
	getchar();
	return 0;
}