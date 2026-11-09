 
 #include <stdio.h>
 #include <ctype.h>
 #include <stdlib.h>

 char input[100];
 int pos = 0;

 void E();
 void T();
 void F();

 void match(char c) {
     if (input[pos] == c)
             pos++;
                 else {
                         printf("Invalid Expression\n");
                                 exit(0);
                                     }
                                     }

                                     void E() {
                                         T();
                                             while (input[pos] == '+') {
                                                     match('+');
                                                             T();
                                                                 }
                                                                 }

                                                                 void T() {
                                                                     F();
                                                                         while (input[pos] == '*') {
                                                                                 match('*');
                                                                                         F();
                                                                                             }
                                                                                             }

                                                                                             void F() {
                                                                                                 if (isalnum(input[pos])) {
                                                                                                         pos++;
                                                                                                             }
                                                                                                                 else if (input[pos] == '(') {
                                                                                                                         match('(');
                                                                                                                                 E();
                                                                                                                                         match(')');
                                                                                                                                             }
                                                                                                                                                 else {
                                                                                                                                                         printf("Invalid Expression\n");
                                                                                                                                                                 exit(0);
                                                                                                                                                                     }
                                                                                                                                                                     }

                                                                                                                                                                     int main() {
                                                                                                                                                                         printf("Enter an expression: ");
                                                                                                                                                                             scanf("%99s", input);

                                                                                                                                                                                 E();

                                                                                                                                                                                     if (input[pos] == '\0')
                                                                                                                                                                                             printf("Valid Expression\n");
                                                                                                                                                                                                 else
                                                                                                                                                                                                         printf("Invalid Expression\n");

                                                                                                                                                                                                             return 0;
                                                                                                                                                                                                             }
                                                                                                                                                                                                             