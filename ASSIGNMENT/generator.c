#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char code[100];
    char result[20], op1[20], op2[20];
    char op;
    int i = 0, j = 0, k = 0;

    printf("Enter Three Address Code: ");
    scanf("%99s", code);

    // Extract result variable
    while(code[i] != '=' && code[i] != '\0')
        result[j++] = code[i++];

    result[j] = '\0';

    if(code[i] != '=')
    {
        printf("Invalid Input\n");
        return 1;
    }

    i++;

    // Extract first operand
    while(code[i] != '+' && code[i] != '-' &&
          code[i] != '*' && code[i] != '/' &&
          code[i] != '\0')
        op1[k++] = code[i++];

    op1[k] = '\0';

    if(code[i] == '\0')
    {
        printf("Invalid Expression\n");
        return 1;
    }

    op = code[i++];

    // Extract second operand
    k = 0;

    while(code[i] != '\0')
        op2[k++] = code[i++];

    op2[k] = '\0';

    if(strlen(result) == 0 || strlen(op1) == 0 ||
       strlen(op2) == 0)
    {
        printf("Invalid Expression\n");
        return 1;
    }

    // Generate assembly code
    printf("\nAssembly Language:\n");

    printf("MOV R0, %s\n", op1);

    switch(op)
    {
        case '+':
            printf("ADD R0, %s\n", op2);
            break;

        case '-':
            printf("SUB R0, %s\n", op2);
            break;

        case '*':
            printf("MUL R0, %s\n", op2);
            break;

        case '/':
            printf("DIV R0, %s\n", op2);
            break;

        default:
            printf("Invalid Operator\n");
            return 1;
    }

    printf("MOV %s, R0\n", result);

    return 0;
}
