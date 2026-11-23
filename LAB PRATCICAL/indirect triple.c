
#include <stdio.h>

int main()
{
    int n, i;

        char op[10][10];
            char arg1[10][20];
                char arg2[10][20];

                    int pointer[10];

                        printf("Enter number of triples: ");
                            scanf("%d", &n);

                                printf("\nEnter Operator, Arg1 and Arg2:\n");

                                    for(i = 0; i < n; i++)
                                        {
                                                printf("\nTriple %d:\n", i);

                                                        printf("Operator: ");
                                                                scanf("%9s", op[i]);

                                                                        printf("Argument 1: ");
                                                                                scanf("%19s", arg1[i]);

                                                                                        printf("Argument 2: ");
                                                                                                scanf("%19s", arg2[i]);

                                                                                                        pointer[i] = i;
                                                                                                            }

                                                                                                                printf("\n\nTRIPLE TABLE\n");
                                                                                                                    printf("---------------------------------\n");
                                                                                                                        printf("Index\tOperator\tArg1\tArg2\n");

                                                                                                                            for(i = 0; i < n; i++)
                                                                                                                                {
                                                                                                                                        printf("%d\t%s\t\t%s\t%s\n",
                                                                                                                                                       i, op[i], arg1[i], arg2[i]);
                                                                                                                                                           }

                                                                                                                                                               printf("\nPOINTER TABLE\n");
                                                                                                                                                                   printf("-------------------------\n");
                                                                                                                                                                       printf("Pointer\tTriple Index\n");

                                                                                                                                                                           for(i = 0; i < n; i++)
                                                                                                                                                                               {
                                                                                                                                                                                       printf("P%d\t%d\n", i, pointer[i]);
                                                                                                                                                                                           }

                                                                                                                                                                                               return 0;
                                                                                                                                                                                               }
                                                                                                                                                                                               