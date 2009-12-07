/*
    Lawrence Velazquez
    30 Oct 2009
    http://www.codechef.com/problems/SUMTRIAN/
*/

#include <stdio.h>
#include <stdarg.h>

#define LOCAL
#ifdef LOCAL
static FILE *f;
#endif

static inline void init();
static inline int scan_int(const char *, int *);
static inline int **allocate_sums(int);
static inline void update(**int, int, int);
static inline void teardown();

int main(int argc, char const *argv[])
{
    int **sums;
    int n, m, p;
    int i, j, k;
    n = init();
        
    for (i = 0; i < n; ++i) {
        scan_int("%d", &m);
        sums = allocate_sums(m);
        for (j = 0; j < m; ++j) {
            for (k = 0; k <= j; ++k) {
                update(sums, j, k);
            }
        }
    }
    
    teardown();
    return 0;
}

static inline int init()
{
    int n;
    
    #ifdef LOCAL
    f = fopen("sumtrian.in", "r");
    fscanf(f, "%d", &n);
    
    #else
    scanf("%d", &n);
    
    #endif
    
    return n;
}

static inline int scan_int(const char *fmt, int *i)
{
    #ifdef LOCAL
    return fscanf(f, fmt, i);
    #else
    return scanf(fmt, i);
    #endif
}

static inline int **allocate_sums(int m)
{
    int **sums = (int **) malloc(sizeof(int *) * m);
    
    int i;
    for (i = 0; i < m; ++i) {
        *(sums + i) = (int *) malloc(sizeof(int) * (i + 1));
    }
    
    return sums;
}

static inline void update(int **s, int a, int b)
{
    if (a = 0)
    s[a][b]
}

static inline void teardown()
{
    #ifdef LOCAL
    fclose(f);
    #endif
}