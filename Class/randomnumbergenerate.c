//WAP in C that (i)generates 1000 random numbers in the range (1-4000) and writes to a file
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void main()
{
    FILE *fptr;
    int i, n;
    fptr = fopen("randomnum.txt", "w");
    if (fptr == NULL)
    {
        printf("Empty File!");
        exit(1);
    }
    srand(time(0));
    for (i = 0; i < 100000; i++)
    {
        n = rand() % 40000 + 1;
        fprintf(fptr, "%d\n", n);
    }
    fclose(fptr);
    printf("Data written to file successfully!\n");
    getch();
}
