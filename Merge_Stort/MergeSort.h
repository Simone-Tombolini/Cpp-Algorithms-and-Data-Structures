#ifndef _MERGESORT
#define _MERGESORT
#include<utility>

typedef int type_index;
using namespace std;

/**
 * @brief merge phase of mergsort support method
 * given the already ordred 2 part of the array, the left and rigth index and the averege, this method merge the 2 array 
 * @pre the 2 part of the array must be ordered 
 * @tparam T type of the array
 * @param array the array to be ordered
 * @param left the left index
 * @param avg the averege
 * @param right the right index
 * 
 */
template<typename T> void merge(T* array, type_index left, type_index avg, type_index right)
{
	//saving the index in temp variables
	type_index i = left;
	type_index j = avg + 1;
	//setting index for the support array
	type_index k = 0;
	//creating support array
	T *temp_array = new T[(right - left) + 1];
	while (i<=avg && j<=right)
	{
		//filling the support array whit comparison, first the bigger
		if (array[i] < array[j])
		{
			temp_array[k] = array[j];
			++j;//moving index
		}
		else
		{
			temp_array[k] = array[i];
			++i;//moving index
		}
		++k;

	}
	//once one index is completed fill the other part
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
	//trandering the temp array in the normal one
	for (type_index i = left; i <= right; ++i) 
	{
		array[i] = temp_array[i - left];
	}
	//deallocating memory
	delete[] temp_array;

}
/**
 * @brief ording an array by mergesort algorithm
 * this funcion ordre in decrasing ordrer an arry, it require the < operator defind for the type of the array 
 * @tparam T type of the array
 * @param array the arrato to be ordered
 * @param left the left index, where the part to order start, set to 0 for order all the array
 * @param right the right index, where the part to order finish, set to the length of the array for order all the array
 */
template<typename T> void merge_sort(T *array, int left, int right) 
{
	if (left < right)//base case
	{
		//step case
		int avg = (left + right) / 2; // avg calculus
		//divide et impera phase
		merge_sort(array, left, avg);
		merge_sort(array, avg + 1, right);
		//merging the result
		merge(array, left, avg, right);
	}
}


#endif
