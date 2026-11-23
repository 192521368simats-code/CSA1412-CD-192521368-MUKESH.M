
#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

int E();
int Q();
int T();
int R();
int F();

// E -> TQ
int E()
{
    return T() && Q();
    }

    // Q -> +TQ | epsilon
    int Q()
    {
        if(input[pos] == '+')
            {
                    pos++;
                            if(T() && Q())
                                        return 1;
                                                return 0;
                                                    }
                                                        return 1;
                                                        }

                                                        // T -> FR
                                                        int T()
                                                        {
                                                            return F() && R();
                                                            }

                                                            // R -> *FR | epsilon
                                                            int R()
                                                            {
                                                                if(input[pos] == '*')
                                                                    {
                                                                            pos++;
                                                                                    if(F() && R())
                                                                                                return 1;
                                                                                                        return 0;
                                                                                                            }
                                                                                                                return 1;
                                                                                                                }

                                                                                                                // F -> (E) | i
                                                                                                                int F()
                                                                                                                {
                                                                                                                    if(input[pos] == 'i')
                                                                                                                        {
                                                                                                                                pos++;
                                                                                                                                        return 1;
                                                                                                                                            }

                                                                                                                                                if(input[pos] == '(')
                                                                                                                                                    {
                                                                                                                                                            pos++;

                                                                                                                                                                    if(E() && input[pos] == ')')
                                                                                                                                                                            {
                                                                                                                                                                                        pos++;
                                                                                                                                                                                                    return 1;
                                                                                                                                                                                                            }
                                                                                                                                                                                                                }

                                                                                                                                                                                                                    return 0;
                                                                                                                                                                                                                    }

                                                                                                                                                                                                                    int main()
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                        printf("PREDICTIVE PARSING\n");
                                                                                                                                                                                                                            printf("------------------\n");

                                                                                                                                                                                                                                printf("Enter input string (i for id): ");
                                                                                                                                                                                                                                    scanf("%99s", input);

                                                                                                                                                                                                                                        pos = 0;

                                                                                                                                                                                                                                            if(E() && input[pos] == '\0')
                                                                                                                                                                                                                                                    printf("\nSTRING ACCEPTED\n");
                                                                                                                                                                                                                                                        else
                                                                                                                                                                                                                                                                printf("\nSTRING REJECTED\n");

                                                                                                                                                                                                                                                                    return 0;
                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                    