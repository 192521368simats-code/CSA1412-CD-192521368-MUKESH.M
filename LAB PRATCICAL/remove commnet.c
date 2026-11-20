
#include <stdio.h>

int main() {
    char s[1000], c;
        int i = 0, j = 0, state = 0;

            printf("Enter the C code:\n");

                while ((c = getchar()) != EOF && c != '~')
                        s[i++] = c;
                            s[i] = '\0';

                                for (i = 0; s[i]; i++) {
                                        if (state == 0) {
                                                    if (s[i] == '/' && s[i+1] == '/') {
                                                                    state = 1;
                                                                                    i++;
                                                                                                }
                                                                                                            else if (s[i] == '/' && s[i+1] == '*') {
                                                                                                                            state = 2;
                                                                                                                                            i++;
                                                                                                                                                        }
                                                                                                                                                                    else if (s[i] != ' ' && s[i] != '\t' &&
                                                                                                                                                                                         s[i] != '\n')
                                                                                                                                                                                                         putchar(s[i]);
                                                                                                                                                                                                                 }
                                                                                                                                                                                                                         else if (state == 1) {
                                                                                                                                                                                                                                     if (s[i] == '\n')
                                                                                                                                                                                                                                                     state = 0;
                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                     else if (state == 2) {
                                                                                                                                                                                                                                                                                 if (s[i] == '*' && s[i+1] == '/') {
                                                                                                                                                                                                                                                                                                 state = 0;
                                                                                                                                                                                                                                                                                                                 i++;
                                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                                                         }

                                                                                                                                                                                                                                                                                                                                             printf("\n");
                                                                                                                                                                                                                                                                                                                                                 return 0;
                                                                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                                                                                 