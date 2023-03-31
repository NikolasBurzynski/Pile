# Pile!

Pile is a templated max_heap implementation. It supports insert and extract max functionality. What is cool about Pile is that it utilized move semantics to allow for more efficient memory managment when dealing with large data sizes. Additionally, the templated class is setup to allow both pure data storage in heap nodes as well as pointers to data in heap nodes. Either way, the heap's memory will be managed properly allowing for the ease of use of the user. 

Another cool feature is the the printing of the data will work with both pure data as well as pointers to data. If the heap holds pointers to data, it will dereference those pointers and print the result.