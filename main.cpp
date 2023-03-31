#include "Heap.h"
#include <iostream>
#include "HugeClass.h"
int main() {
    auto data_heap = new Heap<int *>(1);

    auto one = new int(100);
    auto two = new int(1);
    auto three = new int(10);
    auto four = new int(1190);



    data_heap->insert(one);
    data_heap->insert(two);
    data_heap->insert(three);
    data_heap->insert(four);

    std::cout << *data_heap << std::endl;

    delete data_heap;
}