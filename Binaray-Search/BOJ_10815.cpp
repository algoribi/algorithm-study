// BOJ_10815_숫자 카드

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

vector<int> card;

int search(int num) {
    int start = 0, end = card.size() - 1;

    while (1) {
        if (start > end)
            return -1;

        int mid = (int)((start + end) / 2);
        if (card[mid] > num)
            end = mid - 1;
        else if (card[mid] < num)
            start = mid + 1;
        else if (card[mid] == num)
            return 0;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    card.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &card[i]);
    }
    sort(card.begin(), card.end());

    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
        int pick;
        scanf("%d", &pick);
        int flag = search(pick);
        if (flag == -1) {
            printf("0 ");
            continue;
        } else {
            printf("1 ");
        }
    }
    printf("\n");

    return 0;
}