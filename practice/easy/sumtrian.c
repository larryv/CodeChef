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

#define MAX(x, y)   ((x) > (y) ? (x) : (y))


#ifdef LOCAL
static FILE *f;
#endif

static inline int init();
static inline int scan_int();
static inline int alloc_ints(int ***, int);

int main(int argc, char const *argv[])
{
    int **vals;
    int n, m, p, i, j, k;
    long max;
    n = init();
    
    for (i = 0; i < n; ++i) {
        max = 0;
        m = scan_int();
        alloc_ints(&vals, m);
        
        #ifdef DEBUG
        printf("Beginning triangle scan.\n");
        #endif
        
        for (j = 1; j <= m; ++j) {
            for (k = 1; k <= j; ++k) {
                #ifdef DEBUG
                printf("reading: vals[%d][%d]\n", j, k);
                printf("up-left: %d\nup: %d\n", vals[j-1][k-1], vals[j-1][k]);
                #endif
                p = scan_int();
                vals[j][k] = p + MAX(vals[j-1][k-1], vals[j-1][k]);
            }
        }
        
        for (k = 1; k < j; ++k) {
            if (vals[j-1][k] > max)
                max = vals[j-1][k];
        }
        
        printf("%d\n", max);
        
    }
        
    return 0;
}

static inline int init()
{
    #ifdef LOCAL
    f = fopen("sumtrian.in", "r");
    #endif
    
    return scan_int();
}

static inline int scan_int()
{
    int n;
    
    #ifdef LOCAL
    fscanf(f, "%d", &n);
    #else
    scanf("%d", &n);
    #endif
    
    #ifdef DEBUG
    printf("Scanned: %d\n", n);
    #endif
    
    return n;
}

static inline int alloc_ints(int ***m, int n)
{
    #ifdef DEBUG
    printf("Beginning allocation.\n");
    #endif
    
    if ((*m = (int **) malloc((n + 1) * sizeof(int *))) == NULL)
        return 1;
    
    while (n >= 0) {
        #ifdef DEBUG
        printf("n: %d\n", n);
        #endif
        
        if (((*m)[n] = (int *) malloc((n + 2) * sizeof(int))) == NULL)
            return 1;
        (*m)[n][0] = (*m)[n][n+1] = 0;
        
        #ifdef DEBUG
        printf("m[%1$d][0] = %2$d\nm[%1$d][%3$d] = %4$d\n",
                n, (*m)[n][0], n+1, (*m)[n][n+1]);
        #endif
        
        --n;
    }
    
    #ifdef DEBUG
    printf("Exiting allocation.\n");
    #endif
    
    return 0;
}