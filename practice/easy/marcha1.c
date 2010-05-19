/*
    Lawrence Velazquez
    25 Dec 2009
    http://www.codechef.com/problems/MARCHA1/
*/

#include <stdio.h>
#include <stdint.h>

/*
    The SCAN_INT macro defined below requires n to be an int pointer
*/
#ifdef LOCAL
    static FILE *f;     /* Uses a local file for input */
    #define SCAN_INT(n)     fscanf(f, "%u", n)
#else
    #define SCAN_INT(n)     scanf("%u", n)
#endif

static void init(uint32_t *);

int main(int argc, char const *argv[])
{
    /*
        t: Total number of test cases. Roughly 100.
        n: Number of banknotes for a particular test case. Not more than 20.
        m: Amount the assailants want for a particular test case.
    */
    uint32_t t, n, m;
    init(&t);
    
    size_t i;
    for (i = 0; i < t; ++i) {
        SCAN_INT(&n);
        SCAN_INT(&m);
        
        
    }
    
    return 0;
}

static void init(uint32_t *n)
{
    #ifdef LOCAL
    f = fopen("marcha1.in", "r");
    #endif
    
    SCAN_INT(n);
}
