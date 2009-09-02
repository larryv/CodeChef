/*
    Lawrence Velazquez
    8 Aug 2009
    http://www.codechef.com/problems/INTEST/
*/

#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    int x = 0;
    int i, y;
    for (i = 0; i < n; ++i) {
        scanf("%d", &y);
        if (y % k == 0)
            ++x;
    }
    printf("%d", x);
    
    return 0;
}