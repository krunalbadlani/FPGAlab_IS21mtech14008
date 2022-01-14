#include <stdio.h>
#include <stdlib.h>

int main()
{
    int u[8] = { 0, 0, 0, 0, 1, 1, 1, 1};
    int v[8] = { 0, 0, 1, 1, 0, 0, 1, 1};
    int w[8] = { 0, 1, 0, 1, 0, 1, 0, 1};
    int i, expression_ans;

    for (i = 0; i < 8; i++) {

        // using the given logic
        expression_ans = ((!(u[i]))||v[i]) & ((!(v[i]))||(!(w[i])));

        printf("\n (%d'+%d).(%d'+%d') = %d",
               u[i], v[i], v[i], w[i], expression_ans);
    }
}
