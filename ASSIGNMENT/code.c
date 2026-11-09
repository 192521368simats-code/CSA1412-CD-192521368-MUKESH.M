
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[256];
char *p;
char temp[512][64];
int tempCount = 0;
int tempIndex = 0;
int error = 0;

void skipSpaces()
{
    while (*p == ' ' || *p == '\t')
        p++;
}

char *saveValue(const char *s)
{
    if (tempIndex >= 512)
    {
        error = 1;
        return NULL;
    }

    strcpy(temp[tempIndex], s);
    return temp[tempIndex++];
}

char *newTemp(char *left, char op, char *right)
{
    char name[64];

    if (error || left == NULL || right == NULL)
        return NULL;

    sprintf(name, "t%d", ++tempCount);
    char *result = saveValue(name);

    if (result != NULL)
        printf("%s = %s %c %s\n", result, left, op, right);

    return result;
}

char *expression();
char *term();
char *factor();

char *factor()
{
    char token[64];
    int i = 0;

    skipSpaces();

    if (*p == '(')
    {
        p++;
        char *result = expression();
        skipSpaces();

        if (*p != ')')
            error = 1;
        else
            p++;

        return result;
    }

    if (*p == '-')
    {
        p++;
        char *value = factor();
        return newTemp("0", '-', value);
    }

    if (isalnum((unsigned char)*p) || *p == '_')
    {
        while (isalnum((unsigned char)*p) || *p == '_')
        {
            if (i < 63)
                token[i++] = *p;
            else
                error = 1;

            p++;
        }

        token[i] = '\0';
        return saveValue(token);
    }

    error = 1;
    return NULL;
}

char *term()
{
    char *left = factor();

    while (!error)
    {
        skipSpaces();

        if (*p == '*' || *p == '/')
        {
            char op = *p++;
            char *right = factor();
            left = newTemp(left, op, right);
        }
        else
            break;
    }

    return left;
}

char *expression()
{
    char *left = term();

    while (!error)
    {
        skipSpaces();

        if (*p == '+' || *p == '-')
        {
            char op = *p++;
            char *right = term();
            left = newTemp(left, op, right);
        }
        else
            break;
    }

    return left;
}

int main()
{
    char lhs[64] = "";
    char *result;

    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';
    p = input;

    /* Check for an assignment such as x = a + b */
    skipSpaces();

    if (isalpha((unsigned char)*p) || *p == '_')
    {
        char *start = p;

        while (isalnum((unsigned char)*p) || *p == '_')
            p++;

        char *end = p;
        skipSpaces();

        if (*p == '=' && p[1] != '=')
        {
            int length = end - start;

            if (length >= 64)
                error = 1;
            else
            {
                strncpy(lhs, start, length);
                lhs[length] = '\0';
                p++;
            }
        }
        else
            p = start;
    }

    result = expression();
    skipSpaces();

    if (error || result == NULL || *p != '\0')
    {
        printf("Invalid expression!\n");
        return 1;
    }

    if (lhs[0] != '\0')
        printf("%s = %s\n", lhs, result);
    else
        printf("Final Result = %s\n", result);

    return 0;
}
