/*
    Lawrence Velazquez
    8 Aug 2009
    http://www.codechef.com/problems/INTEST/
*/

#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t n, k;
    scanf("%u %u", &n, &k);
    
    uint32_t x = 0;
    uint32_t i, y;
    for (i = 0; i < n; ++i) {
        scanf("%u", &y);
        if (y % k == 0)
            ++x;
    }
    printf("%u", x);
    
    return 0;
}