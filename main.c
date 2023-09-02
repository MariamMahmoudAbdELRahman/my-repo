#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;

    printf("enter your tasks");
    scanf("%s",choice);

    switch(choice)
    {

    case 1:
        printf("\nadd task");
        break;

    case 2:
        printf("\nview task");
        break;

    case 3:
        printf("\nremove task");
        break;

    default:
            printf("exit the program");
            break;

    }
}
