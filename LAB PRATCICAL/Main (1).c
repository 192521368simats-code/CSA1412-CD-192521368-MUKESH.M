
#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, k;
        char lhs[20][20], op1[20][20];
            char op[20], op2[20][20];
                int removed[20] = {0};

                    printf("Enter number of expressions: ");
                        scanf("%d", &n);

                            printf("\nEnter expressions (Example: a = b + c)\n");

                                for (i = 0; i < n; i++) {
                                        printf("Expression %d: ", i + 1);
                                                scanf("%s = %s %c %s",
                                                              lhs[i], op1[i], &op[i], op2[i]);
                                                                  }

                                                                      printf("\nOptimized Code:\n");

                                                                          for (i = 0; i < n; i++) {
                                                                                  if (removed[i])
                                                                                              continue;

                                                                                                      for (j = 0; j < i; j++) {
                                                                                                                  if (!removed[j] &&
                                                                                                                                  op[i] == op[j] &&
                                                                                                                                                  strcmp(op1[i], op1[j]) == 0 &&
                                                                                                                                                                  strcmp(op2[i], op2[j]) == 0) {

                                                                                                                                                                                  printf("%s = %s\n", lhs[i], lhs[j]);
                                                                                                                                                                                                  removed[i] = 1;
                                                                                                                                                                                                                  break;
                                                                                                                                                                                                                              }
                                                                                                                                                                                                                                      }

                                                                                                                                                                                                                                              if (!removed[i])
                                                                                                                                                                                                                                                          printf("%s = %s %c %s\n",
                                                                                                                                                                                                                                                                             lhs[i], op1[i], op[i], op2[i]);
                                                                                                                                                                                                                                                                                 }

                                                                                                                                                                                                                                                                                     return 0;
                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                     