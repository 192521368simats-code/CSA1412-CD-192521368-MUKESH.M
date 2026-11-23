
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], stack[100];
        int i = 0, j = 0;

            printf("Enter input (use i for id): ");
                scanf("%99s", input);

                    strcat(input, "$");

                        stack[0] = '$';
                            stack[1] = '\0';

                                printf("\nSTACK\t\tINPUT\t\tACTION\n");

                                    while(input[i] != '$')
                                        {
                                                // SHIFT operation
                                                        stack[++j] = input[i];
                                                                stack[j + 1] = '\0';

                                                                        printf("%s\t\t%s\t\tSHIFT\n",
                                                                                       stack, input + i + 1);

                                                                                               i++;

                                                                                                       // REDUCE id -> E
                                                                                                               if(j > 0 && stack[j] == 'i')
                                                                                                                       {
                                                                                                                                   stack[j] = 'E';
                                                                                                                                               printf("%s\t\t%s\t\tREDUCE E -> id\n",
                                                                                                                                                                  stack, input + i);
                                                                                                                                                                          }

                                                                                                                                                                                  // REDUCE E * E -> E
                                                                                                                                                                                          if(j >= 3 &&
                                                                                                                                                                                                     stack[j] == 'E' &&
                                                                                                                                                                                                                stack[j-1] == '*' &&
                                                                                                                                                                                                                           stack[j-2] == 'E')
                                                                                                                                                                                                                                   {
                                                                                                                                                                                                                                               j -= 2;
                                                                                                                                                                                                                                                           stack[j] = 'E';
                                                                                                                                                                                                                                                                       stack[j + 1] = '\0';

                                                                                                                                                                                                                                                                                   printf("%s\t\t%s\t\tREDUCE E -> E * E\n",
                                                                                                                                                                                                                                                                                                      stack, input + i);
                                                                                                                                                                                                                                                                                                              }

                                                                                                                                                                                                                                                                                                                      // REDUCE E + E -> E
                                                                                                                                                                                                                                                                                                                              if(j >= 3 &&
                                                                                                                                                                                                                                                                                                                                         stack[j] == 'E' &&
                                                                                                                                                                                                                                                                                                                                                    stack[j-1] == '+' &&
                                                                                                                                                                                                                                                                                                                                                               stack[j-2] == 'E')
                                                                                                                                                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                                                                                                                                                                   j -= 2;
                                                                                                                                                                                                                                                                                                                                                                                               stack[j] = 'E';
                                                                                                                                                                                                                                                                                                                                                                                                           stack[j + 1] = '\0';

                                                                                                                                                                                                                                                                                                                                                                                                                       printf("%s\t\t%s\t\tREDUCE E -> E + E\n",
                                                                                                                                                                                                                                                                                                                                                                                                                                          stack, input + i);
                                                                                                                                                                                                                                                                                                                                                                                                                                                  }
                                                                                                                                                                                                                                                                                                                                                                                                                                                      }

                                                                                                                                                                                                                                                                                                                                                                                                                                                          if(strcmp(stack, "$E") == 0)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                  printf("\nSTRING ACCEPTED\n");
                                                                                                                                                                                                                                                                                                                                                                                                                                                                      else
                                                                                                                                                                                                                                                                                                                                                                                                                                                                              printf("\nSTRING REJECTED\n");

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  return 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  