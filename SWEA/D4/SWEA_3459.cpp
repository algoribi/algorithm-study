#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        long long num, add = 1, fl = 0, temp = 1;
        scanf("%ld", &num);
        while (add < num) {
            printf("add : %ld \n", add);
            if (fl == 0) {
                temp *= 4;
                fl = 0;
            } else
                fl = 1;
            add += temp;
        }
        if (fl == 1)
            printf("#%d Alice\n", i + 1);
        else
            printf("#%d Bob\n", i + 1);
    }
    return 0;
}