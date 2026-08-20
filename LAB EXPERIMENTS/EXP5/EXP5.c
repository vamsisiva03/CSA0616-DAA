#include <stdio.h>
#include <limits.h>

int optimalBST(int keys[], int freq[], int n) {
    int cost[n][n];
    int i, j, k, L;

    for (i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (L = 2; L <= n; L++) {
        for (i = 0; i <= n - L; i++) {
            j = i + L - 1;
            cost[i][j] = INT_MAX;

            int sum = 0;
            for (k = i; k <= j; k++)
                sum += freq[k];

            for (k = i; k <= j; k++) {
                int c = sum;

                if (k > i)
                    c += cost[i][k - 1];
                if (k < j)
                    c += cost[k + 1][j];

                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n, i;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];

    printf("Enter keys:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &keys[i]);

    printf("Enter frequencies:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    printf("Cost of Optimal BST = %d\n", optimalBST(keys, freq, n));

    return 0;
}