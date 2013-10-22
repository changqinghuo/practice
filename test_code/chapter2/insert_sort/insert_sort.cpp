#include <iostream.h>
#include "stdlib.h"
#include "sort_algorithm.h"
void InsertionSort::sort(int* array, int size)
{
   
	int key=0;
	int j=0;
	for(int i=1; i<size; i++)
	{
		key=array[i];
		j=i-1;
		while(j>=0 && array[j]>key)
		{
			array[j+1]=array[j];
			j--;
		}
	
		array[j+1]=key;	 
		
	}
}

void BubbleSort::sort(int *array, int size)
{
	int key=0;
	for(int i=0; i<size; i++)
	{
		 key=array[i];
		for(int j=i+1; j<size; j++)
		{
		   	if(key>array[j])
			{
			  array[i]=array[j];
			  array[j]=key;
			  key=array[i];
			  
			  
			}
		}
	}
}
void MergeSort::sort(int* array, int size)
{
	sub_sort(array, 0, size-1);
}
void MergeSort::sub_sort(int* array, int p, int r)
{
	int n;
	if(p < r)
	{
      n=(r + p)/2;
	  sub_sort(array, p,  n);
	  sub_sort(array, n+1, r);
	  Merge(array, p, n, r);
	 
	  
	}
}
void MergeSort::Merge(int* array, int p, int n, int r)
{
	if (p > r)
		return;
	int *first_array =new int[n-p+1];
	int *second_array= new int[r-n];
	for( int i=0 ; i < (n-p+1); i++)
	{
           first_array[i]= array[p+i];
	}
	for( int j=0; j< (r-n); j++)
	{
		second_array[j]= array[n+1+j];
	}
	int first_index=0;
	int second_index=0;
	int  merge_index=p;
    while(first_index<=n-p && second_index <=r-n-1)
	{
		if(first_array[first_index]<second_array[second_index] )
			array[merge_index++]=first_array[first_index++];
		else
			array[merge_index++] =second_array[second_index++];
	}
	while(first_index<=n-p)
		array[merge_index++]=first_array[first_index++];
	while(second_index<=r-n-1)
			array[merge_index++] =second_array[second_index++];

	delete[]  first_array;
	delete[]  second_array;
}
void HeapSort::sort(int* array, int size)
{
	
   m_array= new int[size +1];
   for(int i=0; i<size; i++)
   {
	   m_array[i+1]= array[i];
   }
   BuildHeap(m_array,size);
   for(i=1; i<=10; i++)
   {
	   cout<<m_array[i]<<endl;
   }
   int tmp;
   for(int j=size; j>=1; j--)
   {
	   MaxHeapify(m_array, 1, j);
	   tmp=m_array[1];
	   m_array[1] = m_array[j];
	   m_array[j]=tmp;
   }
   for(int k=1; k<size+1 ; k++)
   {
	   array[k-1]=m_array[k];
   }
   delete[] m_array;

   

};
void HeapSort::MaxHeapify(int* heap, int root_index , int heapsize)
{
	int left_index=2*root_index;
	int right_index=2*root_index+1;
	int largest_index = root_index;
	int tmp;
	if(left_index<=heapsize && heap[root_index]>= heap[left_index] )
	{
        largest_index = root_index;
	}
	else if(left_index<=heapsize && heap[root_index] < heap[left_index] )
	{
		largest_index= left_index;
	}
	 if(right_index<=heapsize && heap[largest_index] < heap[right_index] )
	{
		largest_index= right_index;
	}
	 if(largest_index != root_index)
	 {
           tmp=heap[largest_index];
		   heap[largest_index]= heap[root_index];
		   heap[root_index]= tmp;
		   MaxHeapify(heap, largest_index, heapsize);
	 }
	
}
void HeapSort::BuildHeap(int* heap, int heapsize)
{
   for(int i=heapsize/2; i>0; i--)
   {
	   MaxHeapify(heap, i, heapsize);
   }
}
void QuickSort::sort(int* array, int size)
{
   SubSort(array, 0, size -1);
}
int QuickSort::Partition(int* array, int p, int r)
{
	int pivot = array[r];
	int left = p -1;
	int tmp;
	for(int j=p; j<r; j++)
	{
		if(array[j] <= pivot)
		{
			left ++;
            tmp = array[j];
			array[j] = array[left];
			array[left] = tmp;

		}
	}
	array[r] = array[left +1];
	array[left +1] =pivot;
	return left +1;
	
}
void QuickSort::SubSort(int* array, int p , int r)
{
	if(p< r)
	{
	int index=Partition(array,p , r);
	SubSort(array, p, index -1 );
	SubSort(array, index +1  , r);
	}
}
int main()
{
	int array[10]={2,3,1,5,4,8,9, 7,6,0	};
	Sort* insert_obj=new InsertionSort();
	//insert_obj->sort(array,10);
	insert_obj= new QuickSort();
	insert_obj->sort(array, 10);
	for(int i=0; i<10; i++)
	{
		cout<<array[i]<<endl;
	}

	cout<<"asdfasdf"<<endl;
	system("Pause");
	return 0;
	
}