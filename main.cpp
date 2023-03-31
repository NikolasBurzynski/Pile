#include "Heap.h"
#include <iostream>
#include "HugeClass.h"

int HugeClass::instanceNum = 0;

int main() {
    auto data_heap = new Heap<HugeClass>();

    data_heap->insert(HugeClass(100));



    std::cout << *data_heap << std::endl;


    


}