#include<stdio.h>
#include <iostream>

#define ARSIZE 5

int print_array(int* parray, int size) {

    int i = 0;
    if (parray == NULL || size == 0) {
        return 0;
    }
    for (i = 0; i < size; i++) {
        printf("%d", parray[i]);
    }
    printf("\n");
    return 0;
}

int delete_val(int* parray, int size, int delval) {

    int i = 0;
    int j = 0;
    if (parray == NULL || size == 0) {
        return 0;
    }
    for (i = 0; i < size; i++) {
        if (parray[i] != delval) {
            parray[j] = parray[i];
            j++;
        }
    }
    return j;
}

int main() {

    int arr[ARSIZE];
    int array_size;
    std::cin >> array_size;
    for (size_t i = 0; i < array_size; i++)
    {
        std::cin >> arr[i];
    }
    int delval;
    std::cin >> delval;
    print_array(arr, array_size);
    array_size = delete_val(arr, array_size, delval);
    print_array(arr, array_size);
    return 0;
}
