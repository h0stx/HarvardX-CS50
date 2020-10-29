#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,choice;
    printf("##########################WELCOME##########################\n");
    printf("                To My Simple Calculator");
    printf("\n\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
    printf("What You Want To Do : ");
    scanf("%d",&choice);
    printf("Number 1 : ");
    scanf("%d",&a);
    printf("Number 2 : ");
    scanf("%d",&b);

    switch(choice)
    {
    case 1:
        printf("%d + %d = %d\n",a,b,a+b);
        break;

    case 2:
        printf("%d - %d = %d\n",a,b,a-b);
        break;

    case 3:
        printf("%d x %d = %d\n",a,b,a*b);
        break;

    case 4:
        printf("%d / %d = %d\n",a,b,a/b);
        break;
    }
    printf("That was my project for cs50 !\n");
    printf("Good By :)\n");
}
