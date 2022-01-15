// updated code using NAND logic
// author:- Krunal Badlani
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int u[8] = { 0, 0, 0, 0, 1, 1, 1, 1};
    int v[8] = { 0, 0, 1, 1, 0, 0, 1, 1};
    int w[8] = { 0, 1, 0, 1, 0, 1, 0, 1};
    int a, b, i, expression_ans;

    for (i = 0; i < 8; i++) {

       a=!(!(w[i]&&w[i])&&v[i]);
        b=!(!(v[i]&&v[i])&&!(u[i]&&u[i]));

        // using NAND logic
        expression_ans = !(!(!(a&&a)&&!(a&&a))&& !(!(b&&b)&&!(b&&b)));

        printf("\n (%d'+%d).(%d'+%d') = %d",
               u[i], v[i], v[i], w[i], expression_ans);
    }
}
