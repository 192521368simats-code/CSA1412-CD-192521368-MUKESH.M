
#include <stdio.h>
#include <string.h>

int main()
{
    char nt, a[50], b[50];
    int i = 0;

    printf("Enter Non-Terminal: ");
    scanf(" %c", &nt);

    printf("Enter First Production: ");
    scanf("%s", a);

    printf("Enter Second Production: ");
    scanf("%s", b);

    while (a[i] != '\0' && b[i] != '\0' &&
           a[i] == b[i])
    {
        i++;
    }

    if (i == 0)
    {
        printf("\nNo Left Factoring Required.\n");
    }
    else
    {
        printf("\nGrammar After Left Factoring:\n");

        printf("%c -> ", nt);

        for (int j = 0; j < i; j++)
        {
            printf("%c", a[j]);
        }

        printf("%c'\n", nt);

        printf("%c' -> %s | %s\n",
               nt, a + i, b + i);
    }

    return 0;
}
