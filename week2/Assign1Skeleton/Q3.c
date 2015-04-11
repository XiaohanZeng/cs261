/* CS261- Assignment 1 - Q.3*/
/* Name: Xiaohan Zeng
 * Date: 04/11/2015
 * Solution description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    for (int i = 0; i < n - 1; i++)
    {
        for (int q = 0; q < n - i - 1; q++)
        {
            if (number[q] > number[q + 1])
            {
                int swap = number[q +1];
                number[q + 1] = number[q];
                number[q] = swap;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *number = malloc(sizeof(int) * n);
    /*Fill this array with random numbers, using rand().*/
    for (int i = 0; i < n; i++)
    {
        number[i] = rand() % 20;
    }
    /*Print the contents of the array.*/
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", number[i]);

    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(number, n);
    /*Print the contents of the array.*/    
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", number[i]);

    }
    return 0;
}
