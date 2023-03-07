#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include "Utils/Vectors.hpp"

namespace Utils
{
    template <typename T, std::size_t N>
    class SparseArray
    {
      protected:
        std::vector<int> inUse;
        std::array<T, N> elems;
      public:
        SparseArray() {}
        ~SparseArray() {}
        //Dynamically add Element at the back of the list and returns its index
        //returns -1 if no more place
        int addElement(T elem) {
            if (inUse.size() == elems.size()) {
                /*//create new array up to size
                //copy array to new array
                //update last value
                size_t k = elems.size()+1;
                std::array<T, k> newArr;
                std::copy(this->elems.begin(), this->elems.end(), newArr)
                newArr[this->elems.size()] = elem;
                inUse.push_back(k);
                arr = newArr;*/
                std::cerr<<"not enough place to add Element"<<std::endl;
                return -1;
            }
            int lowest = inUse.empty() ? 0 : VectorUtils::findSmallestMissinginSortedArray(inUse);
            this->elems[lowest] = elem;
            this->inUse.push_back(lowest);
            return lowest;
        }

        bool insertAt(T elem, int idx) {
          // if (elems.size() = idx)
          //   elems.insert
            bool exists = std::find(inUse.begin(), inUse.end(), idx) != inUse.end();
            if (elems.size() < idx-1 || !exists)
                return false;
            this->elems[idx] = elem;
            this->inUse.push_back(idx);
        }
        void removeElem(int idx) {
            bool exists = std::find(inUse.begin(), inUse.end(), idx) != inUse.end();
            if (idx < 0 || idx >= N || !exists ) {
                std::cout << "Error: Index out of range" << std::endl;
                return;
            }
            inUse.erase(inUse.begin()+idx);

        }
        void updateElem(T *elem, int idx) { elems[idx] = elem; }
        /*void setList(T *newList)
        {
            this->elems = std::to_array(newList);
        }*/
        //getter
        T getElemAt(int idx) { return elems[idx]; }
        T &front() { return elems[VectorUtils::getXtremes(this->inUse, false)]; }
        T &back() { return elems[VectorUtils::getXtremes(this->inUse, true)]; }

        std::vector<int> getUsedId() { return this->inUse; }

        std::array<T, N> &getList() { return this->elems; }

        T *getShortList() {
            T *Short;
            int sIdx = 0;

            for (auto &idx : inUse) {
                Short[sIdx] = this->elems[idx];
            }
        }

        // virtual void printArray() { return; };
    };
} // namespace name