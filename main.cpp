#include "Heap.h"
#include <iostream>
#include "HugeClass.h"
int main() {
    // auto data_heap = new Heap<HugeClass>(1);
    // data_heap->insert(HugeClass(100));
    // data_heap->insert(HugeClass(100));

    auto data_heap = new Heap<int>(1);
    data_heap->insert(100);
    data_heap->insert(29);
    data_heap->insert(22);
    data_heap->insert(34);
    data_heap->insert(267);
    data_heap->insert(232);
    data_heap->insert(12);

    std::cout << *data_heap << std::endl;
    delete data_heap;
}