/*
     Lawrence Velazquez
     13 Dec 2009
     http://www.codechef.com/problems/SUMTRIAN/
     
     NOTE: The preprocessor macro definitions LOCAL and DEBUG are
     defined in a makefile that I use to do CodeChef compilations
     on my local machine.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y)   ((x) > (y) ? (x) : (y))


#ifdef LOCAL
static FILE *f;     /* Uses a local file for input */
#endif

static int init();
static int scan_int();
static int alloc_two_rows(int **, int);

int main(int argc, char const *argv[])
{
    int *vals[2];
    int n, m, i, j, k;
    int max;
    n = init();
    
    for (i = 0; i < n; ++i) {
        max = 0;
        m = scan_int();
        if (alloc_two_rows(vals, m) == 1)
            return 1;
        
        for (j = 1; j <= m; ++j) {
            for (k = 1; k <= j; ++k)
                vals[1][k] = scan_int() + MAX(vals[0][k-1], vals[0][k]);
            memcpy(&vals[0][1], &vals[1][1], k * sizeof(int));
        }
        
        for (k = 1; k <= m; ++k) {
            if (vals[1][k] > max)
                max = vals[1][k];
        }
        
        if (printf("%d\n", max) < 0)
            return 1;
    }
        
    return 0;
}

static int init()
{
    #ifdef LOCAL
    f = fopen("sumtrian.in", "r");
    #endif
    
    return scan_int();
}

static int scan_int()
{
    int n;
    
    #ifdef LOCAL
    fscanf(f, "%d", &n);
    #else
    scanf("%d", &n);
    #endif
    
    return n;
}

static int alloc_two_rows(int *m[], int n)
{
    /* Allocate two rows */
    m[0] = (int *) malloc((n + 1) * sizeof(int));
    m[1] = (int *) malloc((n + 1) * sizeof(int));    
    if (m[0] == NULL || m[1] == NULL)
        return 1;
    
    /* Zero out arrays */
    int i;
    for (i = 0; i <= n; ++i) {
        m[0][i] = m[1][0] = 0;
    }
    
    return 0;
}