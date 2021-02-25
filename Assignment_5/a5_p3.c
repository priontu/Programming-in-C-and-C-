/*
CH-230-A
a5_p3.c
Priontu Chowdhury
p.chowdhury@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

//count_lower(..) counts number of lowercase characters.
int count_lower(char *str)
{
    int count = 0;
    char ch;

    for (int i = 0; *(str + i) != '\n'; i++)
    {
        ch = *(str + i);
        if (ch > 'a' && ch < 'z')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char *line = (char *)malloc(50 * sizeof(char)); //Dynamic memory allocation.
    if (line == NULL)
        exit(1);
    while (1)
    {
        fgets(line, 50 * sizeof(char), stdin);

        if (*(line) == '\n')
        {
            exit(0); //Exit the program.
        }

        int result = count_lower(line); //Counting lowercase characters.

        printf("Number of lowercase characters: %d\n", result);
    }

    free(line); //De-allocating memory.

    return 0;
}