/*
    Lawrence Velazquez
    9 Aug 2009
    http://www.codechef.com/problems/TEST/
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    scanf("%d", &c);
    while (c != 42) {
        printf("%d\n", c);
        scanf("%d", &c);
    }
    return 0;
}