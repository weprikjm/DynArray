


template <class TYPE>
class MyDynamicArray
{
public:
	MyDynamicArray() : capacity(DYNARRAYBLOCK), sizeArray()
	{
		data = new TYPE[DYNARRAYBLOCK];
		capacity = DYNARRAYBLOCK;
		sizeArray = 0;
	}

	MyDynamicArray(const MyDynamicArray<TYPE>& dynArray) : sizeArray(dynArray->sizeArray)
	{	
		capacity = MAX(DYNARRAYBLOCK, dynArray->capacity);
		data = new TYPE[capacity];
		memset(data, 0, capacity);
		memcpy(data, dynArray->data, sizeArray * sizeof(TYPE));
	}

	MyDynamicArray(int size)
	{
		capacity = DYNARRAYBLOCK + ((size / DYNARRAYBLOCK));
		sizeArray = 0;
		data = new TYPE[capacity];
		memset(data, 0, capacity);

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

	void PushBack(TYPE element)//Simple data
	{
		if (sizeArray == capacity)
		{
			capacity += DYNARRAYBLOCK;
			TYPE* tmp = new TYPE[capacity];

			memcpy(tmp, data, sizeArray);
			delete[] data;
			data = tmp;
		}
		
		data[sizeArray++] = element;

	}




	bool Pop(TYPE& buffer)
	{
		if (sizeArray > 0)
		{
			buffer = this->data[--sizeArray];
			return true;
		}
		return false;
	}

	int MultiplePop(MyDynamicArray<TYPE>* buffer, const uint num)
	{
		int sizeStart = num;
		

		if (sizeStart <= sizeArray)
		{
			for (int i = 0; i < sizeStart; i++)
			{
				TYPE element;
				
				this->Pop(element);
				buffer->PushBack(element);
			}
			return num;
		}
		else
		{
			int initialSizeArray = sizeArray;
			int numElementsCopied = 0;
			for (; numElementsCopied < initialSizeArray; numElementsCopied++)
			{
				TYPE element;

				this->Pop(element);
				buffer->PushBack(element);
			}
			return numElementsCopied;
		
		}

		return num;

	}



	TYPE At(const int index)const
	{
		if (index < sizeArray)
		{
			return data[index];
		}
		return NULL;
	}

	 TYPE* Find(TYPE* object)const	
	{
		TYPE* found = NULL;
		for (int index = 0; index < sizeArray < index++)
		{
			if (object == data[index])
			{
				found = data[index];
				return found;
			}
				
		}
		return found;
	
	}

	 TYPE Find(TYPE object)const
	 {
		 TYPE found = 0;
		 for (int index = 0; index < sizeArray; index++)
		 {
			 if (object == data[index])
			 {
				 found = data[index];
				 
				 return found;
			 }

		 }
		 return found;

	 }


	void ShowInt()const
	{
		for (int index = 0; index < sizeArray; index++)
		{
			printf("%d",data[index]);
		}
	
	}

	void Flip()
	{
		int size = sizeArray - 1;
	
		for (int i = 0; i <= sizeArray / 2; i++)
		{
			Swap(this->data[i], this->data[size - i]);
		}

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