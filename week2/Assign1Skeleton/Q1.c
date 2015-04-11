/* CS261- Assignment 1 - Q.1*/
/* Name:Xiaohan Zeng
 * Date:04/11/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student *tenStudent = malloc(sizeof(int) * 2 * 10);
    /*return the pointer*/
    return tenStudent;
}

void removeAtDynArr(int IDgroup[10], int index, int size)
{
    for (int i = index; i < size - 1; i++)
    {
        IDgroup[i] = IDgroup[i + 1];
    }
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    int IDgroup[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    for (int i = 0; i < 10; i++)
    {
        struct student s;
        int tempIndex = rand() % 10;
        s.id = IDgroup[tempIndex];
        removeAtDynArr(IDgroup, tempIndex, 10 - i);
        s.score = rand() % 100;
        students[i] = s;
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for (int i = 0; i < 10; i++)
    {
        printf("ID %d, Score %d", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
