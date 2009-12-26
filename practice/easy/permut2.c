/*
    Lawrence Velazquez
    26 Dec 2009
    http://www.codechef.com/problems/PERMUT2/
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
    The SCAN_INT macro defined below requires n to be an int pointer
*/
#ifdef LOCAL
    static FILE *f;     /* Uses a local file for input */
    #define SCAN_INT(n)     fscanf(f, "%u", n)
#else
    #define SCAN_INT(n)     scanf("%u", n)
#endif

int main(int argc, char const *argv[])
{
    #ifdef LOCAL
    f = fopen("permut2.in", "r");
    #endif
    
    uint32_t n, i;
    SCAN_INT(&n);
    while (n) {
        uint32_t a[n], b[n];    /* a is the permutation, b is its inverse */
        for (i = 0; i < n; ++i) {
            SCAN_INT(&a[i]);
            b[a[i] - 1] = i + 1;
        }                    
        if (memcmp(a, b, n * sizeof(uint32_t)))
            printf("not ");
        printf("ambiguous\n");
        SCAN_INT(&n);
    }
    
    return 0;
}
