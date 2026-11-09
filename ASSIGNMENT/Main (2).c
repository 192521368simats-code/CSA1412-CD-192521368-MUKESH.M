
#include <stdio.h>

int main() {
    char s[1000], out[1000];
        int i, j = 0;

            printf("Enter code:\n");
                fgets(s, sizeof(s), stdin);

                    for (i = 0; s[i]; i++) {
                            if (s[i] == '/' && s[i+1] == '/') break;

                                    if (s[i] == '/' && s[i+1] == '*') {
                                                i += 2;
                                                            while (s[i] && !(s[i] == '*' && s[i+1] == '/')) i++;
                                                                        if (s[i]) i++;
                                                                                }
                                                                                        else if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
                                                                                                    out[j++] = s[i];
                                                                                                        }

                                                                                                            out[j] = '\0';
                                                                                                                printf("\nOutput:\n%s\n", out);

                                                                                                                    return 0;
                                                                                                                    }
                                                                                                                    