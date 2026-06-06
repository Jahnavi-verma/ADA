#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int p[n], dir[n];

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        dir[i] = -1; 
    }

    while (1) {
        
        for (int i = 0; i < n; i++)
            printf("%d ", p[i]);
        printf("\n");

        int mobile = 0, pos = -1;

        
        for (int i = 0; i < n; i++) {
            if (dir[i] == -1 && i > 0 && p[i] > p[i - 1]) {
                if (p[i] > mobile) {
                    mobile = p[i];
                    pos = i;
                }
            }

            if (dir[i] == 1 && i < n - 1 && p[i] > p[i + 1]) {
                if (p[i] > mobile) {
                    mobile = p[i];
                    pos = i;
                }
            }
        }

        if (mobile == 0)
            break;

        int next = pos + dir[pos];

        
        int temp = p[pos];
        p[pos] = p[next];
        p[next] = temp;

        
        temp = dir[pos];
        dir[pos] = dir[next];
        dir[next] = temp;

        pos = next;

        
        for (int i = 0; i < n; i++) {
            if (p[i] > mobile)
                dir[i] = -dir[i];
        }
    }

    return 0;
}