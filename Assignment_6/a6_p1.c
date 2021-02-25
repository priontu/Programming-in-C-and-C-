#include <stdio.h>

#define SWAP(V1, V2, T) \
    {                   \
        T K = V1;       \
        V1 = V2;        \
        V2 = K;         \
    }

int main()
{
    int intVar1;
    int intVar2;

    double dVar1;
    double dVar2;

    scanf("%d", &intVar1);
    scanf("%d", &intVar2);

    scanf("%lf", &dVar1);
    scanf("%lf", &dVar2);

    SWAP(intVar1, intVar2, int);
    SWAP(dVar1, dVar2, double);

    printf("After swapping:\n");
    printf("%d\n", intVar1);
    printf("%d\n", intVar2);
    printf("%lf\n", dVar1);
    printf("%lf\n", dVar2);

    return 0;
}
