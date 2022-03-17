//searches.cpp
#include <vector>
#include <string>
#include "sorts.h"
//Taken from textbook, adjusted for vectors of strings
int linear_search(std::vector<std::string> &a, int size, std::string value)
{  
   for (int i = 0; i < size; i++)
   {  
      if (a[i] == value)
      {
         return i;
      }
   }
   return -1;
}

//Taken from textbook, adjusted for vectors of strings
int binary_search(std::vector<std::string> &a, int from, int to, std::string value)
{  
   if (from > to) 
   { 
      return -1; 
   }

   int mid = (from + to) / 2;
   if (a[mid] == value)
   {
      return mid;
   }
   else if (a[mid] < value)
   {
      return binary_search(a, mid + 1, to, value);
   }
   else
   {
      return binary_search(a, from, mid - 1, value);
   }
}

