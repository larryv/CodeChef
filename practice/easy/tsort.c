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


/*
    The SCAN_INT macro defined below requires n to be an int pointer
*/
#ifdef LOCAL
    static FILE *f;     /* Uses a local file for input */
    #define SCAN_INT(n)     fscanf(f, "%d", n)
#else
    #define SCAN_INT(n)     scanf("%d", n)
#endif


/* The maximum value of each integer in the list. */
#define K   1000000

/* The chosen sort. */
#define SORT countingsort

static void countingsort(int32_t *, int32_t);
static void init(int32_t *);
static void read(int32_t *, int32_t);

int main(int argc, char const *argv[])
{
    /*
        t: Number of numbers in list to be sorted. (t <= 1,000,000)
        A: Array storing the sorted list. Length is t.
    */    
    int32_t t;
    init(&t);
    
    int32_t A[t];
    SORT(A, t);
    
    int32_t i;
    for (i = 0; i < t; ++i)
        printf("%d\n", A[i]);
    
    return 0;
}

static void countingsort(int32_t B[], int32_t n)
{
    int32_t i;

    /* Read in input */
    int32_t A[n];
    read(A, n);
    
    /* Initialize auxiliary space */
    int32_t C[K + 1];
    for (i = 0; i <= K; ++i)
        C[i] = 0;
    
    /* Let C[i] be the number of elements equal to i */
    for (i = 0; i < n; ++i)
        ++C[A[i]];
    
    /* Now let C[i] be the number of elements <= i */
    for (i = 1; i <= K; ++i)
        C[i] += C[i - 1];
    
    for (i = n - 1; i >= 0; --i) {
        B[C[A[i]] - 1] = A[i];
        --C[A[i]];
    }
}

static void init(int32_t *n)
{
    #ifdef LOCAL
    f = fopen("tsort.in", "r");
    #endif
    
    SCAN_INT(n);
}

static void read(int32_t *a, int32_t n)
{
    while (n-- > 0)
        SCAN_INT(a++);
}