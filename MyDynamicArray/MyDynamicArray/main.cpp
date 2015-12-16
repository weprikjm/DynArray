#include "Defs.h"
#include "MyDynamicArray.h"
#include <iostream>
#include <time.h>

typedef unsigned int uint;

int main()
{
	srand(time(NULL));
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
	bye[0] = 10;
	hello.Find(3);

	//printf("%d\n",hello[0]);
	
	//printf("%d\n", hello[0]);
	
	printf("%d\n", hello[0]);
	
	hello.ShrinkToFit();
	
	//hello.MultiplePop(&bye,num);

	MyDynamicArray<int> bubble;

	int	random;
	int lowest = 0;
	int highest = 1000;
	bubble.Clear();
	
	/*
	bubble.PushBack(5);
	bubble.PushBack(8);
	bubble.PushBack(3);
	bubble.PushBack(1);
	bubble.PushBack(4);
	bubble.PushBack(2);
	*/
	
	
	for (int i = 0; i < 10000; i++)
	{
		random = lowest + (rand() % (highest - lowest));
		bubble.PushBack(random);
	}
	
	//bubble.PrintArray();

	double repetitions = bubble.BubbleSortOptimized();

	printf("\n\n\n\n\n");
	bubble.PrintArray();


	//hello.ShowInt();
	//printf("\n\n");
	//bye.ShowInt();
	printf("\n\n%d", repetitions);
	//bye.Flip();
	//bye.ShowInt();
	
	getchar();
	return 0;
}