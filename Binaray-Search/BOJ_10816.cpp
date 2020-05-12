// BOJ_10815_숫자 카드 2

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

vector<int> card;
int n;

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
        else if (card[mid] == num) {
            if (mid == 0)
                return mid;
            else if (card[mid - 1] != num)
                return mid;
            else
                end = mid - 1;
        }
    }
}

int Back_search(int num) {
    int start = 0, end = card.size() - 1;

    while (1) {
        if (start > end)
            return -1;

        int mid = (int)((start + end) / 2);
        if (card[mid] > num)
            end = mid - 1;
        else if (card[mid] < num)
            start = mid + 1;
        else if (card[mid] == num) {
            if (mid == n - 1)
                return mid;
            else if (card[mid + 1] != num)
                return mid;
            else
                start = mid + 1;
        }
    }
}

int main() {
    scanf("%d", &n);
    card.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &card[i]);
    }
    sort(card.begin(), card.end());

    int m;
    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
        int pick;
        scanf("%d", &pick);
        int flag = search(pick);
        if (flag == -1) {
            printf("0 ");
            continue;
        }
        int back_flag = Back_search(pick);
        int count = back_flag - flag + 1;
        printf("%d ", count);
    }
    printf("\n");
    return 0;
}