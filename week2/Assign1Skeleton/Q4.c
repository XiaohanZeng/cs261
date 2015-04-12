/* CS261- Assignment 1 - Q.4*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/ 
    for (int i = 0; i < n - 1; i++)
    {
        for (int q = 0; q < n - i - 1; q++)
        {
            if (students[q].score > students[q + 1].score)
            {
                struct student swap = students[q + 1];
                students[q + 1] = students[q];
                students[q] = swap;
            }
        }
    }
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
    int IDgroup[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19 };

    for (int i = 0; i < 20; i++)
    {
        struct student s;
        int tempIndex = rand() % (20 - i);
        s.id = IDgroup[tempIndex];
        removeAtDynArr(IDgroup, tempIndex, 20 - i);
        s.score = rand() % 100;
        students[i] = s;
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;
    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(sizeof(int) * 2 * n);
    /*Generate random IDs and scores for the n students, using rand().*/
    generate(students);
    /*Print the contents of the array of n students.*/
    for (int i = 0; i < n; i++)
    {
        printf("ID %d, Score %d \n", students[i].id, students[i].score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    /*Print the contents of the array of n students.*/
    printf("sorted students\n");
    for (int i = 0; i < n; i++)
    {
        printf("ID %d, Score %d \n", students[i].id, students[i].score);
    }
    return 0;
}
