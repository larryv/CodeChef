/*
    Lawrence Velazquez
    26 Oct 2009
    http://www.codechef.com/problems/ONP/
*/

#include <stdio.h>
#include <ctype.h>

#define QUEUE_LEN 200

// #define LOCAL

#ifdef LOCAL
#define READCHAR() (getc(f))
#else
#define READCHAR() (getchar())
#endif

static char queue[QUEUE_LEN];
static int qptr;

static inline void init();
static inline int push(char);
static inline char pop();


int main(int argc, char const *argv[])
{
    int t, c, i;
    init();
    
    #ifdef LOCAL
    FILE *f = fopen("onp.in", "r");
    fscanf(f, "%d\n", &t);
    #else
    scanf("%d\n", &t);
    #endif
    
    for (i = 0; i < t; ++i) {
        while ((c = READCHAR()) != '\n') {
            if (c == ')')
                putchar(pop());
            else if (isalpha(c))
                putchar(c);
            else if (c != '(')
                push(c);
        }
        putchar('\n');
    }
    
    #ifdef LOCAL
    fclose(f);
    #endif
    return 0;
}

static inline void init()
{
    qptr = 0;
    int i;
    for (i = 0; i < QUEUE_LEN; ++i)
        queue[i] = '\0';    
}

static inline int push(char c)
{
    if (qptr >= QUEUE_LEN)
        return 0;
    queue[qptr++] = c;
    return 1;
}

static inline char pop()
{
    if (qptr <= 0)
        return 0;
    return queue[--qptr];
}