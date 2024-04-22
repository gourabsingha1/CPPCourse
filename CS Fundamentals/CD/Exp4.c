#include <stdio.h>
#include <conio.h>
#include <ctype.h>

// Write a C program to test whether a given identifier is valid or not

int main() {
    char a[10];
    int i = 1;
    printf("\n Enter an identifier: ");
    gets(a);

    if (!isalpha(a[0])) {
        printf("\n Not a valid identifier");
    }

    for (i = 1; a[i] != '\0'; i++)
    {
        if (!isdigit(a[i]) && !isalpha(a[i])) {
            printf("\n Not a valid identifier");
            return 0;
        }
    }
    printf("\n Valid identifier");
    getch();

    return 0;
}

// Input:
//
// Enter an identifier: 1aqw