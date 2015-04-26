
#include <stdio.h>

int main()
{
    float inch;
    float cm;
    printf("please enter the inches number you want to convert.\n");
    scanf("%f", &inch);
    cm = inch*2.5;
    printf("%f inch equals to %f cm \n", inch, cm);

    return 0;

}
