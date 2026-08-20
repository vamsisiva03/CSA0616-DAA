#include <stdio.h>

struct Activity {
    int start;
    int finish;
};

int main() {
    int n, i, j;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity a[n], temp;

    printf("Enter start and finish times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &a[i].start, &a[i].finish);
    }

    // Sort activities by finish time
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i].finish > a[j].finish) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nSelected Activities:\n");

    i = 0;
    printf("(%d, %d)\n", a[i].start, a[i].finish);

    for(j = 1; j < n; j++) {
        if(a[j].start >= a[i].finish) {
            printf("(%d, %d)\n", a[j].start, a[j].finish);
            i = j;
        }
    }

    return 0;
}