/*
CH-230-A
a6_p2.c
Priontu Chowdhury
p.chowdhury@jacobs-university.de
*/

#include <stdio.h>

int main()
{ //Declaration and taking input:
    unsigned char letter;
    scanf("%c", &letter);
    //Outputting integer and LSB:
    printf("The decimal representation is: %d\n", letter);
    printf("The least significant bit is: %d", letter & 1);

    return 0;
}