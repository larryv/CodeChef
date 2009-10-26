/*
    Lawrence Velazquez
    26 Aug 2009
    http://www.codechef.com/problems/FCTRL/
*/

#include <stdio.h>

// #define LOCAL

#ifdef LOCAL
#define READ(ptr) (fscanf(f, "%d", ptr))
#else
#define READ(ptr) (scanf("%d", ptr))
#endif

int main(int argc, char const *argv[])
{
    int i, n, t, q0, q1, z;
    
    #ifdef LOCAL
    FILE *f = fopen("fctrl.in", "r");
    #endif
    READ(&t);
    
    for (i = 0; i < t; ++i, z = 0) {
        READ(&n);
        for (q0 = n, q1 = q0 / 5; q0 != 0; q0 = q1, q1 = q0 / 5)
            z += q1;
        printf("%d\n", z);
    }
    
    #ifdef LOCAL
    if (fclose(f) == EOF)
        return 1;
    #endif
    return 0;
}