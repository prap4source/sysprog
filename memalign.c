#include <stdio.h>
#include <stdlib.h>

typedef struct {
        int a;
        int b;
} pair_t;

#define PAIRS 100
#define REPS 10000

int
main()
{
        int i, j;
        char *foo;
        pair_t *pairs;

        if ((foo = (char *) malloc((PAIRS + 1) * sizeof(pair_t))) == NULL) {
                fprintf(stderr, "Unable to allocate memory\n");
                exit(1);
        }

#ifdef ALIGNED
        pairs = (pair_t *) foo;
#else
        pairs = (pair_t *) (foo + 1);
#endif

        for (i = 0; i < PAIRS; i++) {
                pairs[i].a = i;
                pairs[i].b = i+5;
        }

        for (j = 0; j < REPS; j++) {
                int sum;

                for (i = 0; i < PAIRS; i++) {
                        sum += pairs[i].a + pairs[i].b;
                }
        }
}

