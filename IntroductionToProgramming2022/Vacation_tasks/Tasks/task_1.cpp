#include <iostream>
using namespace std;

//program swapping two numbers using ptrs
int main() {
    int a = 3, b = 7;
    int *pa = &a, *pb = &b;
    std::cout << *pa << " " << *pb << std::endl;
    int x = *pa;
    *pa = *pb;
    *pb = x;
    std::cout << *pa << " " << *pb << std::endl;
    return 0;
}