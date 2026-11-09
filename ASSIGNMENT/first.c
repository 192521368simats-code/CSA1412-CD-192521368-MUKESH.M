 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char production[10][10];
char first[10];
int n, count = 0;

void addToFirst(char c)
{
    int i;
    for (i = 0; i < count; i++)
        if (first[i] == c)
            return;

    first[count++] = c;
}

void findFirst(char c)
{
    int i, j;

    if (!isupper((unsigned char)c))
    {
        addToFirst(c);
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (production[i][0] == c)
        {
            for (j = 2; production[i][j] != '\0'; j++)
            {
                char symbol = production[i][j];

                if (symbol == '|')
                    break;

                if (symbol == '#')
                {
                    addToFirst('#');
                    break;
                }

                if (!isupper((unsigned char)symbol))
                {
                    addToFirst(symbol);
                    break;
                }

                findFirst(symbol);

                int hasEpsilon = 0;
                for (int k = 0; k < count; k++)
                    if (first[k] == '#')
                        hasEpsilon = 1;

                if (!hasEpsilon)
                    break;
            }
        }
    }
}

int main()
{
    char symbol;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use # for epsilon):\n");
    for (int i = 0; i < n; i++)
        scanf("%9s", production[i]);

    printf("Enter non-terminal: ");
    scanf(" %c", &symbol);

    count = 0;
    findFirst(symbol);

    printf("FIRST(%c) = { ", symbol);
    for (int i = 0; i < count; i++)
        printf("%c ", first[i]);
    printf("}\n");

    return 0;
}
