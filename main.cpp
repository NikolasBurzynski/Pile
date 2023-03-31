#include "Heap.h"
#include <iostream>
#include "HugeClass.h"
#include <stack>


int main() {
    auto my_heap = new Heap<HugeClass>();
    my_heap->insert(HugeClass(100, 90));
    my_heap->insert(HugeClass(10000, 76));
    my_heap->insert(HugeClass(900000, 43));
    my_heap->insert(HugeClass(10, 1));

    std::cout << *my_heap << std::endl;

    auto max = my_heap->extractMax();
    max = my_heap->extractMax();
    max = my_heap->extractMax();
    max = my_heap->extractMax();

    std::cout << max << std::endl;
    my_heap->insert(HugeClass(100, 90));
    my_heap->insert(HugeClass(10000, 76));
    my_heap->insert(HugeClass(900000, 43));
    my_heap->insert(HugeClass(10, 1));
    std::cout << *my_heap << std::endl;

    delete my_heap;

}