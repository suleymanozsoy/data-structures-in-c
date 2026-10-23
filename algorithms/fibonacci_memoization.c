#include <stdio.h>

int fib(int n, int memo[])
{

    if (n <= 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);

    return memo[n];
}

int main()
{

    int memo[47];

    for (int i = 0; i < 47; i++)
    {
        memo[i] = -1;
    }

    printf("%d\n", fib(6, memo));
}
