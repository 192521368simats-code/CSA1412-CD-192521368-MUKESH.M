
#include <stdio.h>
#include <string.h>

int main()
{
    char type[20];
        char id[10][20];
            int n, i;

                printf("Enter declaration type: ");
                    scanf("%s", type);

                        printf("Enter number of identifiers: ");
                            scanf("%d", &n);

                                for(i = 0; i < n; i++)
                                    {
                                            printf("Enter identifier %d: ", i + 1);
                                                    scanf("%s", id[i]);
                                                        }

                                                            printf("\nBOTTOM-UP EVALUATION\n");
                                                                printf("----------------------------\n");

                                                                    // Bottom-up processing
                                                                        printf("Step 1: Reduce identifiers\n");

                                                                            for(i = 0; i < n; i++)
                                                                                {
                                                                                        printf("id -> %s\n", id[i]);
                                                                                            }

                                                                                                printf("\nStep 2: Reduce identifier list\n");
                                                                                                    printf("L -> id");

                                                                                                        for(i = 1; i < n; i++)
                                                                                                            {
                                                                                                                    printf(" , id");
                                                                                                                        }

                                                                                                                            printf("\n\nStep 3: Reduce type\n");
                                                                                                                                printf("T -> %s\n", type);

                                                                                                                                    printf("\nStep 4: Reduce declaration\n");
                                                                                                                                        printf("D -> T L\n");

                                                                                                                                            printf("\nFINAL OUTPUT\n");
                                                                                                                                                printf("----------------------------\n");
                                                                                                                                                    printf("Identifier\tInherited Type\n");

                                                                                                                                                        for(i = 0; i < n; i++)
                                                                                                                                                            {
                                                                                                                                                                    printf("%s\t\t%s\n", id[i], type);
                                                                                                                                                                        }

                                                                                                                                                                            return 0;
                                                                                                                                                                            }
                                                                                                                                                                            