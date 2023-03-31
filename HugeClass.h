#ifndef HUGE_CLASS_H
#define HUGE_CLASS_H
#include <iostream>

class HugeClass {
    private:
        int * large_data;
        int data_size;
        int my_num;

    public:
        HugeClass(): large_data(nullptr), data_size(100), my_num(0){
            large_data = new int[data_size]; 

            
        }

        HugeClass(int dataSize, int my_num): large_data(nullptr), data_size(dataSize), my_num(my_num) {
            large_data = new int[data_size]; 
        }

        HugeClass(const HugeClass & rhs) {
            large_data = new int[rhs.data_size];
            data_size = rhs.data_size;
            my_num = rhs.my_num;
            for(int i = 0; i < data_size; i++) {
                large_data[i] = rhs.large_data[i];
            }
        }

        HugeClass(HugeClass&& other): large_data(other.large_data) { //move constructor
            data_size = other.data_size;
            my_num = other.my_num;
            other.large_data = nullptr;
        }

        HugeClass & operator= (HugeClass && rhs) { //move operator =
            if(this != &rhs) {
                delete[] large_data;
                data_size = rhs.data_size;
                large_data = rhs.large_data;
                my_num = rhs.my_num;
                rhs.large_data = nullptr;
            }
            return *this;
        }

        HugeClass & operator= (const HugeClass & rhs) {
            my_num = rhs.my_num;
            data_size = rhs.data_size;
            for(int i = 0; i < 10000; i++) {
                large_data[i] = rhs.large_data[i];
            }
            return *this;
        }

        bool operator< (const HugeClass & rhs) {
            return my_num < rhs.my_num;
        }

        ~HugeClass() {
            delete[] large_data;
        }

        friend std::ostream& operator << (std::ostream & os, const HugeClass & hc) {
            os << hc.my_num;
            return os;
        }


};


#endif