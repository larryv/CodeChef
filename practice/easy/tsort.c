/*
     Lawrence Velazquez
     19 Dec 2009
     http://www.codechef.com/problems/TSORT/
     
     NOTE: The preprocessor macro definitions LOCAL and DEBUG are
     defined in a makefile that I use to do CodeChef compilations
     on my local machine.
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


/* The maximum value of each integer in the list. */
#define K   1000000

/* The chosen sort. */
#define SORT counting_sort

static void counting_sort(uint32_t *, uint32_t);
static void init(uint32_t *);
static void read(uint32_t *, uint32_t);

int main(int argc, char const *argv[])
{
    /*
        t: Number of numbers in list to be sorted. (t <= 1,000,000)
        A: Array storing the sorted list. Length is t.
    */    
    uint32_t t;
    init(&t);
    
    uint32_t A[t];
    SORT(A, t);
    
    uint32_t i;
    for (i = 0; i < t; ++i)
        printf("%u\n", A[i]);
    
    return 0;
}

static void counting_sort(uint32_t B[], uint32_t n)
{
    /* The final loop sets i = -1 at termination, so leave as signed int. */
    int32_t i;
    
    /* Initialize auxiliary space */
    uint32_t C[K + 1];
    memset(C, 0, (K + 1) * sizeof(uint32_t));
    
    /* Read in input */
    uint32_t A[n];
    for (i = 0; i < n; ++i) {
        SCAN_INT(&A[i]);
        ++C[A[i]];  /* Let C[i] be the number of elements equal to i */
    }
    
    /* Now let C[i] be the number of elements <= i */
    for (i = 1; i <= K; ++i)
        C[i] += C[i - 1];
    
    for (i = n - 1; i >= 0; --i) {
        B[C[A[i]] - 1] = A[i];
        --C[A[i]];
    }
}

static void init(uint32_t *n)
{
    #ifdef LOCAL
    f = fopen("tsort.in", "r");
    #endif
    
    SCAN_INT(n);
}

static void read(uint32_t *a, uint32_t n)
{
    while (n-- > 0)
        SCAN_INT(a++);
}