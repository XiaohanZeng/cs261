/* CS261- Assignment 1 - Q.2*/
/* Name:Xiaohan Zeng
 * Date: 04/11/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    /*Print the values of x, y and z*/
    printf("x is %d, y is %d, z is %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int temp = foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("foo return %d\n", temp);
    /*Print the values of x, y and z again*/
    printf("x is %d, y is %d, z is %d\n", x, y, z);
    /*Is the return value different than the value of z?  Why? Because c is passed by value in foo, not the address. So any change on c is local.*/
    return 0;
}
    
    
