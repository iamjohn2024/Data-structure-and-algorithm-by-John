#include <stdio.h>
#include <limits.h>

int main()
{
    int x = 1;
    int negativex = -x;
    if(negativex == ~x)
         printf("one's complement\n");
    else if(negativex == ~x + 1)
         printf("two's complement\n");
    else if(negativex == (x ^ (1 << (sizeof(x) * CHAR_BIT - 1))))
         printf("sign/magnitude\n");
    else
         printf("what the heck kind of machine are you on??\n");
}
