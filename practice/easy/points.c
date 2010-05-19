/*
    Lawrence Velazquez
    26 Dec 2009
    http://www.codechef.com/problems/POINTS/
*/

#include <stdio.h>
#include <stdint.h>

/* The SCAN_INT macro requires its arg to be an int pointer. */
#ifdef LOCAL
    static FILE *f;
    #define SCAN_INT(n)     fscanf(f, "%u", (unsigned int *) n)
    #define SCAN_POINT(p)   fscanf(f, "%u %u", \
                                   (unsigned int *) &p.x, \
                                   (unsigned int *) &p.y)
#else
    #define SCAN_INT(n)     scanf("%u", (unsigned int *) n)
    #define SCAN_POINT(p)   scanf("%u %u", \
                                  (unsigned int *) &p.x, \
                                  (unsigned int *) &p.y)
#endif


struct point {
    uint16_t x;
    uint16_t y;
};

static void init(uint32_t *);
static void sort_points(struct point *);

int main(int argc, char const *argv[])
{
    uint32_t t, n;
    init(&t);
    
    size_t i, j;
    for (i = 0; i < t; ++i) {
        SCAN_INT(&n);
        struct point a[n];
        
        for (j = 0; j < n; ++j) {
            SCAN_POINT(a[j]);
            printf("(%u, %u)\n", a[j].x, a[j].y);
        }
    }
    
    return 0;
}

static void sort_points(struct point pts[])
{
    
}

static void init(uint32_t *n)
{
    #ifdef LOCAL
    f = fopen("points.in", "r");
    #endif
    
    SCAN_INT(n);
}