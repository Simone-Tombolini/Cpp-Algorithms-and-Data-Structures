#ifndef _MERGESORT
#define _MERGESORT
#include<utility>

typedef int type_index;
using namespace std;

template<typename T> void merge(T* array, type_index left, type_index avg, type_index right)
{
	type_index i = left;
	type_index j = avg + 1;
	type_index k = 0;
	T *temp_array = new T[(right - left) + 1];
	while (i<=avg && j<=right)
	{
		if (array[i] < array[j])
		{
			temp_array[k] = array[j];
			++j;
		}
		else
		{
			temp_array[k] = array[i];
			++i;
		}
		++k;

	}

	while (i<=avg)
	{
		temp_array[k] = array[i];
		++i;
		++k;
	}

	while (j <= right)
	{
		temp_array[k] = array[j];
		++j;
		++k;
	}
	for (type_index i = left; i <= right; ++i) 
	{
		array[i] = temp_array[i - left];
	}
	delete[] temp_array;

}

template<typename T> void merge_sort(T *array, int left, int right) 
{
	if (left < right)
	{

		int avg = (left + right) / 2;
		merge_sort(array, left, avg);
		merge_sort(array, avg + 1, right);
		merge(array, left, avg, right);
	}
}


#endif
