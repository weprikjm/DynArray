



template <class TYPE>
class MyDynamicArray
{
public:
	MyDynamicArray() : capacity(BLOCK32), sizeArray()
	{
		data = new TYPE[BLOCK32];
		capacity = BLOCK32;
		sizeArray = 0;
	}

	MyDynamicArray(const MyDynamicArray<TYPE>& dynArray) : sizeArray(dynArray->sizeArray)
	{	
		capacity = MAX(DYNARRAYBLOCK, dynArray->capacity);
		data = new TYPE[capacity];
		memset(data, 0, capacity);
		memcpy(data, dynArray->data, sizeArray * sizeof(TYPE));
	}

	void PushBack(TYPE* element)
	{
		if (sizeArray == capacity)
		{
			capacity += DYNARRAYBLOCK;
			TYPE* tmp = new TYPE[capacity];
		
			memcpy(tmp,data,sizeArray);	
			delete[] data;
			data = tmp;
		}
		
		data[sizeArray++] = element;
		
	}


	~MyDynamicArray()
	{ 
		if (data != NULL)
			delete[] data; 
	}

private:
	TYPE* data = NULL;
	uint capacity = DYNARRAYBLOCK;
	uint sizeArray = 0;
};