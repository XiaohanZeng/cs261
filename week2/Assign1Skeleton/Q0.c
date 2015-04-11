/* CS261- Assignment 1 - Q. 0*/
/* Name: Xiaohan Zeng
 * Date: 04/11/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
    printf("Value pointed to by input is %d\n", *iptr);
     /*Print the address pointed to by iptr*/
    printf("Address pointed to by input is %x\n", iptr);
     /*Print the address of iptr itself*/
    printf("Address of input itself %x\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x;

    /*print the address of x*/
    printf("Adress of x = %d\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("Value of x = %d\n", x);
    return 0;
}
