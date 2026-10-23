#include <stdio.h>

void hanoi(int n, int from, int to)
{

    if (n > 0)
    {

        hanoi(n - 1, from, 6 - from - to);

        printf("Disk %d: %d -> %d\n", n, from, to);

        hanoi(n - 1, 6 - from - to, to);
    }
}

int main(void)
{

    hanoi(3, 1, 3);

    return 0;
}
