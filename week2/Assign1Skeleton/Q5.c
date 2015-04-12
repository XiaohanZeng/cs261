/* CS261- Assignment 1 - Q.5*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (i % 2 == 0 && word[i] <= 'z' && word[i] >= 'a')
        {
            word[i] = toUpperCase(word[i]);
        }
        if (i % 2 == 1 && word[i] <= 'Z' && word[i] >= 'A')
        {
            word[i] = toLowerCase(word[i]);
        }
    }

}

int main(){
    /*Read word from the keyboard using scanf*/
    char word[200]; 
    scanf("%s", word);
    /*Call sticky*/
    sticky(word);
    /*Print the new word*/
    printf("word: %s \n", word);
    return 0;
}
