//sorts.cpp
#include <string>
#include <vector>
#include "sorts.h"

//Taken from textbook, adjusted for strings, swaps two string variable values
void swap (std::string &x, std::string &y)
{
    std::string temp = x;
    x = y;
    y = temp;
}

// Bubble sort optimized by group: Yosuf, Joahan, Boesong, Abdurrahman, returns number of swaps
int bubble_sort (std::vector<std::string> &a, int size)
{
    int total = 0;
    for (int j = 0; j < size; j++)
    {
		int count_swap = 0;					//counter for number of swaps in a single loop						
        for (int i = 0; i < size-1; i++)    //changed to size - 1, bubble sort only needs to reach second to last element
        {                                   //also solves out of bounds error by not checking element after last element
            if (a[i+1] < a[i])
            {
                swap(a[i+1],a[i]);          //swaps next element with current element if next is smaller than current
                count_swap++;
            }
        }
        total = total + count_swap;
        if (count_swap == 0)				//If no swaps in a loop, array is sorted, exits function
            return total;
        
    }
    return total;
}

//Function taken from textbook, adjusted for vectors, finds position of minimum value
int min_position(std::vector<std::string> a, int from, int to)
{
   int min_pos = from;
   for (int i = from + 1; i <= to; i++)
   {
      if (a[i] < a[min_pos]) { min_pos = i; }
   }
   return min_pos;
}

//Taken from textbook, adjusted for vectors, also counts and returns number of swaps
int selection_sort(std::vector<std::string> &a, int size)
{
	int next; // The next position to be set to the minimum
	int count = 0;
	for (next = 0; next < size - 1; next++)
	{
		// Find the position of the minimum starting at next
		int min_pos = min_position(a, next, size - 1);
		// Swap the next element and the minimum
		swap(a[next], a[min_pos]);
		count++;
	}
	return count;
}

//Taken from textbook, adjusted for vectors
void merge(std::vector<std::string> a, int from, int mid, int to)
{  
   int n = to - from + 1; // Size of the range to be merged 
   // Merge both halves into a temporary array b 
   // We allocate the array dynamically since its size is only
   // known at run time--see Section 7.4
   std::string* b = new std::string[n];

   int i1 = from;
      // Next element to consider in the first half 
   int i2 = mid + 1;
      // Next element to consider in the second half 
   int j = 0; // Next open position in b 

   // As long as neither i1 nor i2 is past the end, move the smaller
   // element into b
  
   while (i1 <= mid && i2 <= to)
   {  
      if (a[i1] < a[i2])
      {  
         b[j] = a[i1];
         i1++;
      }
      else
      {  
         b[j] = a[i2];
         i2++;
      }
      j++;
   }

   // Note that only one of the two while loops below is executed

   // Copy any remaining entries of the first half
   while (i1 <= mid)
   {  
      b[j] = a[i1];
      i1++;
      j++;
   }
   // Copy any remaining entries of the second half
   while (i2 <= to)
   {  
      b[j] = a[i2];
      i2++;
      j++;
   }

   // Copy back from the temporary array
   for (j = 0; j < n; j++)
   {
      a[from + j] = b[j];
   }

   // The temporary array is no longer needed.
   delete[] b;
}

//Taken from textbook, adjusted for vectors
void merge_sort(std::vector<std::string> a, int from, int to)
{
	if (from == to) { return; }
	int mid = (from + to) / 2;
	// Sort the first and the second half
	merge_sort(a, from, mid);
	merge_sort(a, mid + 1, to);
	merge(a, from, mid, to);
}

//Takwn from textbook, adjusted for vectors of strings
void insertion_sort(std::vector<std::string> a, int size)
{
   for (int i = 1; i < size; i++)
   {
      std::string next = a[i];
      // Move all larger elements up
      int j = i;
      while (j > 0 && a[j - 1] > next)
      {
         a[j] = a[j - 1];
         j--;
      }
      // Insert the element
      a[j] = next;
   }
}

//Taken from textbook, adapted for vectors of strings
int partition(std::vector<std::string> a, int from, int to)
{
   std::string pivot = a[from];
   int i = from - 1;
   int j = to + 1;
   while (i < j)
   {
      i++; while (a[i] < pivot) { i++; }
      j--; while (a[j] > pivot) { j--; }
      if (i < j) { swap(a[i], a[j]); }
   }
   return j;
}

//Taken from textbook, adapted for vectors of strings
void quicksort(std::vector<std::string> a, int from, int to)
{
   if (from >= to) { return; }
   int p = partition(a, from, to);
   quicksort(a, from, p);
   quicksort(a, p + 1, to);
}

//Finds timing of two sorting functions chosen by user
void sorttime(std::vector<std::string> file1, std::vector<std::string> file2, std::vector<std::string> file3, int sort1, int sort2)
{
	double sorttotal1=0, sorttotal2=0, unsorttotal1=0, unsorttotal2=0;
	using namespace std::chrono;
	switch(sort1)
	{
		case 1:			//Bubble
			for(int i = 0; i < 9; i++)
			{
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				bubble_sort(std::vector<std::string> a, int size)
				high_resolution_clock::time_point t2 = high_resolution_clock::now();
				duration<double> time_span1 = duration_cast<duration<double>> (t2-t1);
				unsorttotal1 += time_span1.count();
				
				high_resolution_clock::time_point t3 = high_resolution_clock::now();
				bubble_sort (std::vector<std::string> &a, int size)
				high_resolution_clock::time_point t4 = high_resolution_clock::now();
				duration<double> time_span2 = duration_cast<duration<double>> (t4-t3);
				sorttotal1 += time_span2.count();
			}
			break;
		case 2:			//Selection
			break;
		case 3:			//Merge
			break;
		case 4:			//Insertion
			break;
		case 5:			//Quick
			break;
	}
}
