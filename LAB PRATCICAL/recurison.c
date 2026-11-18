#include <stdio.h>
#include <string.h>

int main()
{
    char nt, production[100];
    char alpha[50], beta[50];
    int i = 0, j = 0;

    puts("Enter Non-Terminal:");
    scanf(" %c", &nt);

    puts("Enter Production (Example: Aa|b):");
    scanf("%99s", production);

    // Check whether left recursion exists
    if (production[0] == nt)
    {
        puts("\nLeft Recursion Found");

        // Extract recursive part (alpha)
        i = 1;
        while (production[i] != '|' &&
               production[i] != '\0')
        {
            alpha[j++] = production[i++];
        }
        alpha[j] = '\0';

        // Extract non-recursive part (beta)
        j = 0;

        if (production[i] == '|')
            i++;

        while (production[i] != '\0')
        {
            beta[j++] = production[i++];
        }
        beta[j] = '\0';

        // Generate new grammar
        puts("\nAfter Removing Left Recursion:");

        printf("%c -> %s%c'\n", nt, beta, nt);
        printf("%c' -> %s%c' | epsilon\n", nt, alpha, nt);
    }
    else
    {
        puts("No Left Recursion Found");
    }

    return 0;
}
