#ifndef HUGE_CLASS_H
#define HUGE_CLASS_H
#include <iostream>

class HugeClass {
    private:
        int * large_data;
        int data_size;

    public:
        HugeClass(): large_data(nullptr), data_size(100) {
            std::cout << "Default Constructor" << std::endl;
            large_data = new int[data_size]; 

            
        }

        HugeClass(int dataSize): large_data(nullptr), data_size(dataSize){
            std::cout << "Value Constructor" << std::endl;
            large_data = new int[data_size]; 
        }

        HugeClass(const HugeClass & rhs) {
            std::cout << "Copy Constructor" << std::endl;
            large_data = new int[rhs.data_size];
            data_size = rhs.data_size;
            for(int i = 0; i < data_size; i++) {
                large_data[i] = rhs.large_data[i];
            }
        }

        HugeClass(HugeClass&& other): large_data(other.large_data) { //move constructor
            std::cout << "Move Constructor" << std::endl;
            data_size = other.data_size;
            other.large_data = nullptr;
        }

        HugeClass & operator= (HugeClass && rhs) { //move operator =
            std::cout << "Move Operator=" << std::endl;
            if(this != &rhs) {
                delete[] large_data;
                large_data = rhs.large_data;
                rhs.large_data = nullptr;
            }
            return *this;
        }

        HugeClass & operator= (const HugeClass & rhs) {
            std::cout << "Assignment Operator" << std::endl;
            for(int i = 0; i < 10000; i++) {
                large_data[i] = rhs.large_data[i];
            }
            return *this;
        }

        bool operator< (const HugeClass & rhs) {
            return true;
        }

        ~HugeClass() {
            delete[] large_data;
        }


};


#endif