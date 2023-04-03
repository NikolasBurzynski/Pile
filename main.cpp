#include "Heap.h"
#include <iostream>
#include "HugeClass.h"
#include <stack>


int main() {
    auto my_heap = new Heap<HugeClass *>(10);
    my_heap->insert(new HugeClass(100, 90));
    my_heap->insert(new HugeClass(10000, 76));
    my_heap->insert(new HugeClass(900000, 43));
    my_heap->insert(new HugeClass(10, 1));

    std::cout << *my_heap << std::endl;

    auto max = my_heap->extractMax();
    delete max;
    max = my_heap->extractMax();
    delete max;
    max = my_heap->extractMax();
    delete max;
    max = my_heap->extractMax();
    delete max;
    std::cout << *my_heap << std::endl;

    delete my_heap;

}