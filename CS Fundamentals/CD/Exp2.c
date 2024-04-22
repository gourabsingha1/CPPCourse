#include <stdio.h>

// Write a C program to identify whether a given line is a comment or not

int main() {
    char com[30];
    int i = 2;
    printf("\nEnter Text : ");
    gets(com);

    if (com[0] == '/') {
        if (com[1] == '/') {
            printf("\nIt is a Comment.");
            return 0;
        }
        else if (com[1] == '*') {
            for (i = 2; i + 1 < 30; i++)
            {
                if (com[i] == '*' && com[i + 1] == '/') {
                    printf("\nIt is a Comment.");
                    return 0;
                }
            }
        }
    }
    printf("\nIt is Not a Comment.");

    return 0;
}

// Input:
//
// Enter Text: // yes