#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[200];
        int i = 0;

            printf("Enter an expression: ");
                fgets(s, sizeof(s), stdin);

                    while (s[i] != '\0') {
                            if (isspace(s[i])) {
                                        i++;
                                                }
                                                        else if (isalpha(s[i]) || s[i] == '_') {
                                                                    printf("%c", s[i++]);
                                                                                while (isalnum(s[i]) || s[i] == '_')
                                                                                                printf("%c", s[i++]);
                                                                                                            printf(" -> IDENTIFIER\n");
                                                                                                                    }
                                                                                                                            else if (isdigit(s[i])) {
                                                                                                                                        while (isdigit(s[i]))
                                                                                                                                                        printf("%c", s[i++]);
                                                                                                                                                                    printf(" -> NUMBER\n");
                                                                                                                                                                            }
                                                                                                                                                                                    else if (strchr("+-*/=<>", s[i])) {
                                                                                                                                                                                                printf("%c -> OPERATOR\n", s[i++]);
                                                                                                                                                                                                        }
                                                                                                                                                                                                                else if (strchr("();{},", s[i])) {
                                                                                                                                                                                                                            printf("%c -> SPECIAL SYMBOL\n", s[i++]);
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                            else {
                                                                                                                                                                                                                                                        printf("%c -> INVALID TOKEN\n", s[i++]);
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                        return 0;
                                                                                                                                                                                                                                                                        }
