
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
        int single = 0, multi = 0;

            printf("Enter C program:\n");
                fgets(s, sizeof(s), stdin);

                    for (int i = 0; s[i]; i++) {
                            if (s[i] == '/' && s[i+1] == '/') {
                                        single++;
                                                    break;
                                                            }
                                                                    if (s[i] == '/' && s[i+1] == '*') {
                                                                                multi++;
                                                                                            break;
                                                                                                    }
                                                                                                        }

                                                                                                            printf("Single-line comments: %d\n", single);
                                                                                                                printf("Multi-line comments: %d\n", multi);
                                                                                                                    printf("Total comments: %d\n", single + multi);

                                                                                                                        return 0;
                                                                                                                        }
                                                                                                                        