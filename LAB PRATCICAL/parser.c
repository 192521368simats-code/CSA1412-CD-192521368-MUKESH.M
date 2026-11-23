#include <stdio.h>
#include <string.h>

/* Grammar:
   E -> TQ
   Q -> +TQ | epsilon
   T -> FR
   R -> *FR | epsilon
   F -> (E) | i
*/

static char input[100];
static size_t pos;

static int E(void);
static int Q(void);
static int T(void);
static int R(void);
static int F(void);

static int E(void)
{
    return T() && Q();
}

static int Q(void)
{
    if (input[pos] == '+') {
        pos++;
        return T() && Q();
    }
    return 1;
}

static int T(void)
{
    return F() && R();
}

static int R(void)
{
    if (input[pos] == '*') {
        pos++;
        return F() && R();
    }
    return 1;
}

static int F(void)
{
    if (input[pos] == 'i') {
        pos++;
        return 1;
    }

    if (input[pos] == '(') {
        pos++;
        if (E() && input[pos] == ')') {
            pos++;
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    if (fgets(input, sizeof input, stdin) == NULL) {
        puts("STRING REJECTED");
        return 0;
    }

    input[strcspn(input, "\r\n")] = '\0';
    pos = 0;

    if (E() && input[pos] == '\0')
        puts("STRING ACCEPTED");
    else
        puts("STRING REJECTED");

    return 0;
}
