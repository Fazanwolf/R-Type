/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Vectors
*/

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>

#ifndef VECTORS_HPP_
#define VECTORS_HPP_

namespace Utils {
    class VectorUtils {
        public:
        //return highest value if positive else return lowest
        static int getXtremes(std::vector<int> input, bool positive)
        {
            int min = input[0];
            for(int i = 0; i < input.size(); i++) {
                if ( (!positive && input[i] < min) || (positive && input[i] > min)) {
                    min = input[i];
                }
            }
            return min;
        }
    
        static int findFirstMissing(std::vector<int> arr, int start, int  end, int first)
        {
          if (start < end)
          {
            int mid = (start + end) / 2;
            /** Index matches with value
              at that index, means missing
              element cannot be upto that po*/
            if (arr[mid] != mid+first)
              return findFirstMissing(arr, start, mid, first);
            else
              return findFirstMissing(arr, mid + 1, end, first);
          }
          return start + first;
        }
        
        // Program to find Smallest
        // Missing in Sorted Array
        static int findSmallestMissinginSortedArray(std::vector<int> arr)
        {
          // Check if 0 is missing
          // in the array
          if(arr[0] != 0)
            return 0;
          // Check is all numbers 0 to n - 1
          // are present in array
          if(arr[arr.size() - 1] == arr.size() - 1)
            return arr.size();
          int first = arr[0];
          return findFirstMissing(arr, 0, arr.size() - 1, first);
        }
  };
}

#endif /* !VECTORS_HPP_ */