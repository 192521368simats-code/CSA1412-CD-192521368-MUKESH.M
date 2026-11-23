
#include <stdio.h>
#include <string.h>

int main()
{
    char type[20];
        char identifiers[10][20];
            int n, i;

                printf("Enter data type (int/float): ");
                    scanf("%s", type);

                        printf("Enter number of identifiers: ");
                            scanf("%d", &n);

                                printf("Enter identifiers:\n");

                                    for(i = 0; i < n; i++)
                                        {
                                                scanf("%s", identifiers[i]);
                                                    }

                                                        printf("\nSyntax Directed Definition\n");
                                                            printf("--------------------------\n");

                                                                printf("Inherited Attribute: %s\n", type);

                                                                    printf("\nIdentifier\tData Type\n");
                                                                        printf("--------------------------\n");

                                                                            for(i = 0; i < n; i++)
                                                                                {
                                                                                        printf("%s\t\t%s\n", identifiers[i], type);
                                                                                            }

                                                                                                return 0;
                                                                                                }
                                                                                                