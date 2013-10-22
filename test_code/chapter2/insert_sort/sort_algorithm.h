#include <iostream.h>
class Sort{
public:
	virtual void sort(int* array, int size)=0;
	void GetComplexity();
};
class InsertionSort: public Sort
{
public:
	void sort(int* array, int size);
	void GetComplexity();
};
class BubbleSort:public Sort
{
public:
	void sort(int *array, int size);
	void GetComplexity();
};
class  MergeSort:public Sort
{
public:
	void sort(int* array, int size);
	void GetComplexity();
private:
	void Merge(int* array, int p,int n,int r);
	void sub_sort(int* array, int p,int r);
};
class HeapSort:public Sort
{
public:
	void sort(int* array, int size);
	void GetComplexity();
private:
	int* m_array;
	int m_size;
    void	MaxHeapify(int* heap, int root_index , int heapsize);
    void	BuildHeap(int* heap, int heapsize);
	

};
class QuickSort:public Sort
{
public:
	void sort(int* array, int size);
	void GetComplexity();
private:
	int Partition(int* array, int p, int r);
	void SubSort(int* array, int p , int r);
	

};