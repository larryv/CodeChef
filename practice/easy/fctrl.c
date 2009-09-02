/*
    Lawrence Velazquez
    10 Aug 2009
    http://www.codechef.com/problems/FCTRL/
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int t, n;
    scanf("%d", &t);

    int i, j, k;
    for (i = 0; i < t; ++i) {
        scanf("%d", &n);
        k = 0;
        for (j = 5; j <= n; j = j + 5) {
            while (j % (int)pow(5, k) == 0)
                ++k;
        }
        printf("%d\n", k);
    }
    return 0;
}