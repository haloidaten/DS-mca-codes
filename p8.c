#include <stdio.h>

void unionSet(int x[], int y[], int n)
{
    int z[50], i;

    printf("\nUnion of A and B: ");
    for (i = 0; i < n; i++)
        z[i] = x[i] || y[i];

    for (i = 0; i < n; i++)
        printf("%d ", z[i]);
}

void intersection(int x[], int y[], int n)
{
    int z[50], i;

    printf("\nIntersection of A and B: ");
    for (i = 0; i < n; i++)
        z[i] = x[i] && y[i];

    for (i = 0; i < n; i++)
        printf("%d ", z[i]);
}

void difference(int x[], int y[], int n)
{
    int z[50], i;

    printf("\nDifference A - B: ");
    for (i = 0; i < n; i++)
        z[i] = x[i] && !y[i];

    for (i = 0; i < n; i++)
        printf("%d ", z[i]);
}

int main()
{
    int n, m, o, i, j, u[50];
    int a[50], b[50], bita[50], bitb[50];
    int ch;

    printf("Enter the size of universal set: ");
    scanf("%d", &n);

    printf("Enter the elements of universal set:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &u[i]);

    printf("Enter the size of set A: ");
    scanf("%d", &m);

    while (m > n)
    {
        printf("Size is greater than universal set. Enter again: ");
        scanf("%d", &m);
    }

    printf("Enter the elements of set A:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);

    printf("Enter the size of set B: ");
    scanf("%d", &o);

    while (o > n)
    {
        printf("Size is greater than universal set. Enter again: ");
        scanf("%d", &o);
    }

    printf("Enter the elements of set B:\n");
    for (i = 0; i < o; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < n; i++)
    {
        bita[i] = 0;
        bitb[i] = 0;

        for (j = 0; j < m; j++)
            if (u[i] == a[j])
                bita[i] = 1;

        for (j = 0; j < o; j++)
            if (u[i] == b[j])
                bitb[i] = 1;
    }

    printf("\nBit string of A: ");
    for (i = 0; i < n; i++)
        printf("%d ", bita[i]);

    printf("\nBit string of B: ");
    for (i = 0; i < n; i++)
        printf("%d ", bitb[i]);
    do
    {
    

        printf("\n\n1. Union");
        printf("\n2. Intersection");
        printf("\n3. Difference (A - B)");
        printf("\n4. exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                unionSet(bita, bitb, n);
                break;

            case 2:
                intersection(bita, bitb, n);
                break;

            case 3:
                difference(bita, bitb, n);
                break;

            default:
                printf("\nInvalid choice!");
        }
    }while (ch!=4);

return 0;
}