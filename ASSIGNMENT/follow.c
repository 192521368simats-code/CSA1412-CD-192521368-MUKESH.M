
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[10][10];
char follow[10];
int n, count = 0;

void add(char c)
{
    for (int i = 0; i < count; i++)
        if (follow[i] == c)
            return;

    follow[count++] = c;
}

void findFollow(char c)
{
    if (prod[0][0] == c)
        add('$');

    for (int i = 0; i < n; i++)
    {
        for (int j = 2; prod[i][j] != '\0'; j++)
        {
            if (prod[i][j] == c)
            {
                if (prod[i][j + 1] != '\0')
                {
                    char next = prod[i][j + 1];

                    if (!isupper((unsigned char)next))
                    {
                        if (next != '#')
                            add(next);
                    }
                    else
                    {
                        add(next);
                    }
                }
                else if (prod[i][0] != c)
                {
                    findFollow(prod[i][0]);
                }
            }
        }
    }
}

int main()
{
    char symbol;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (example: E=TR):\n");
    for (int i = 0; i < n; i++)
        scanf("%9s", prod[i]);

    printf("Enter non-terminal: ");
    scanf(" %c", &symbol);

    count = 0;
    findFollow(symbol);

    printf("FOLLOW(%c) = { ", symbol);
    for (int i = 0; i < count; i++)
        printf("%c ", follow[i]);

    printf("}\n");
    return 0;
}
