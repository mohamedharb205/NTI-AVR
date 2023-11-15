#include <stdio.h>
#include <stdlib.h>



static short int Array[256];
static short int Hash[16];


int main()
{
    short int Array[256];
    // Generate random integer values in the range [0, 255] and store them in the array.
    for (int i = 0; i < 256; i++)
    {
        Array[i] = rand() % 256;
    }

    // Print the array.
    printf("This is image data 256 u8 elements \n");
    for (int i = 0; i < 256; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n \n");


    Array[5]=18;
    for (int i = 0; i < 256; i++)
    {
        Hash[i%16] = Array[i] ^ Array[i+16];
    }


    printf("This is the Hash function data 16 u8 elements \n");
    for (int i = 0; i < 16; i++)
    {
        printf("%d ", Hash[i]);
    }
    printf("\n");

    return 0;
}














