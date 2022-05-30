// 103. WAP to Reverse a user given string
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

void reverseString(char* str, int length) {
    for(int i = 0; i < length/2; i++) {
        int temp = str[i];
        str[i] = str[length - 1 + i];
        str[length - 1 + i] = temp;
    }

    std::cout << "Reversed string: "<< str << std::endl;
}


int main()
{
    char str[20];
    std::cout << "Enter a string: " << std::endl;
    gets(str);

    int length = strlen(str);
    reverseString(str, length);

    return 0;
}