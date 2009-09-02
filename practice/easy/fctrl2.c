/*
    Lawrence Velazquez
    9 Aug 2009
    http://www.codechef.com/problems/FCTRL2/
*/

#include <stdio.h>
#include <string.h>

#ifndef MAX_LEN
#define MAX_LEN 200
#endif

void print_fac(int n);
void array_mult(char *a, int l, int n);

int main()
{
    int t;
    scanf("%d", &t);

    int c, i;
    for (i = 0; i < t; ++i) {
        scanf("%d", &c);
        print_fac(c);
        printf("\n");
    }
    return 0;
}

void print_fac(int n)
{
    char r[MAX_LEN];
    memset(r, 0, MAX_LEN);
    r[0] = 1;

    int i;
    for (i = 2; i <= n; ++i) {
        array_mult(r, MAX_LEN, i);
    }

    int start = 0;
    for (i = MAX_LEN - 1; i >= 0; --i) {
        if (start) {
            printf("%d", r[i]);
            continue;
        }
        if (r[i] != 0) {
            printf("%d", r[i]);
            start = 1;
        }
    }
}

void array_mult(char *a, int l, int n)
{
    char b[l];
    memcpy(b, a, l);
    memset(a, 0, l);

    int c, i, t;
    c = t = 0;
    for (i = 0; i < l; ++i) {
        t = c + b[i] * n;
        if (t < 10) {
            a[i] = t;
            c = 0;
        } else {
            a[i] = t % 10;
            c = t / 10;
        }
    }
}
