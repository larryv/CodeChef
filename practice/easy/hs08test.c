/*
    Lawrence Velazquez
    8 Aug 2009
    http://www.codechef.com/problems/HS08TEST/
*/

#include <stdio.h>

int main()
{
    int x;
    float y;
    
    scanf("%d %6f", &x, &y);
    
    if ((x + 0.5) <= y && x % 5 == 0) {
        printf("%.2f", y - (x + 0.5));
    } else {
        printf("%.2f", y);
    }
    
    return 0;
}
