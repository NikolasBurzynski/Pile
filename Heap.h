#ifndef HEAP_HPP
#define HEAP_HPP

#include <type_traits>
#include <iostream>
#include <cmath>

template <typename T>
class Heap;

template<typename T>
typename std::enable_if<std::is_pointer<T>::value, std::ostream >::type & 
operator<< (std::ostream& os, const Heap<T> & heap) {
    int levels = log2(heap.size);
    for (int i = 0; i <= levels; i++) {
        os << "Level " << i << std::endl; 
        for (int j = (1 << i) - 1; j < (1 << (i+1)) - 1; j++) {
            if (j >= heap.size) break;
            std::cout << *heap.data_arr[j] << ", ";
        }
        std::cout << std::endl;
    }
    return os;
}

template<typename T>
typename std::enable_if<!std::is_pointer<T>::value, std::ostream >::type & 
operator<< (std::ostream& os, const Heap<T> & heap) {
    int levels = log2(heap.size);
    for (int i = 0; i <= levels; i++) {
        os << "Level " << i << std::endl; 
        for (int j = (1 << i) - 1; j < (1 << (i+1)) - 1; j++) {
            if (j >= heap.size) break;
            std::cout << heap.data_arr[j] << ", ";
        }
        std::cout << std::endl;
    }
    return os;
}

template <typename T>
typename std::enable_if<!std::is_pointer<T>::value, void>::type
destruct_helper(T * data_arr, int size) {
    //destructor for array holding data
    delete[] data_arr;
    return;
}

template<typename T>
typename std::enable_if<std::is_pointer<T>::value, void>::type
destruct_helper(T * data_arr, int size) {
    //destructor for array holding ptr to data
    for(int i = 0; i < size; i++) {
        delete data_arr[i];
    }
    delete[] data_arr;
    return;
}

template<typename T> //Compare helper for ptr to data in array
inline typename std::enable_if<std::is_pointer<T>::value, bool>::type
compare(T a, T b) {
    return (*a) < (*b);
}

template<typename T> //Compare helper for data in array
inline typename std::enable_if<!std::is_pointer<T>::value, bool>::type
compare(T& a, T& b) {
    return a < b;
}

template <typename T>
class Heap{
    private:
        T * data_arr;
        int size;
        int cap;
        void grow() {
            cap *= 2;
            T * new_loc = new T[cap];
            for(int i = 0; i < size; i++) {
                new_loc[i] = std::move(data_arr[i]);
                // new_loc[i] = data_arr[i];
            }
            delete[] data_arr;
            data_arr = new_loc;
        }

        inline int left_i(int i) {
            int index = 2*i + 1;
            return index < size ? index : -1; 
        }
        
        inline int right_i(int i) {
            int index = 2*i + 2;
            return index < size ? index : -1; 
        }

        inline int parent_i(int i) {
            if (i == 0) return -1;
            int index = (i - 1) / 2;
            return index >= 0 ? index : -1;
        }

        void push_back(T& data) {
            if (size == cap) {
                grow();
            }
            data_arr[size] = std::move(data);
            // data_arr[size] = data;
            size++;
        }    


    public:
        Heap(): cap(1), size(0), data_arr(nullptr){
            data_arr = new T[cap];
        };
        Heap(int startCap): cap(startCap), size(0), data_arr(nullptr){
            data_arr = new T[startCap];
        };

        ~Heap() {
            destruct_helper(data_arr, size);
        }

        friend std::ostream & operator<<<T>(std::ostream&, const Heap<T> &);

        void swap(int a, int b) {
            T temp(std::move(data_arr[a]));
            data_arr[a] = std::move(data_arr[b]);
            data_arr[b] = std::move(temp);
        }

        void bubble_up(int startIndex) {
            int index = startIndex;
            while(parent_i(index) >= 0 && compare(data_arr[parent_i(index)], data_arr[index])) {
                swap(index, parent_i(index));
                index = parent_i(index);
            }
        }

        void bubble_down(int startIndex) {
            int index = startIndex;
            while(left_i(index) >= 0) {
                if (right_i(index) >= 0) {
                    int higher = (compare(data_arr[left_i(index)], data_arr[right_i(index)])) ? 
                                    right_i(index) :
                                    left_i(index);
                    if(compare(data_arr[higher], data_arr[index])) return;
                    swap(index, higher);
                    index = higher;
                } else {
                    if(compare(data_arr[left_i(index)], data_arr[index])) return;
                    swap(index, left_i(index));
                    index = left_i(index);
                }
            }
        }

        void insert(T&& data) {
            push_back(data); //insert the data into the open space in the array
            bubble_up(size - 1);
        }

        void insert(T& data) {
            push_back(data); //insert the data into the open space in the array
            bubble_up(size - 1);
        }

        T&& extractMax() {
            if(size == 1) {
                size -=1;
                return std::move(data_arr[size]);
            } 
            else {
                swap(0, size - 1);
                size -= 1;
                bubble_down(0);
                return std::move(data_arr[size]);
            }
        }  
};

#endif