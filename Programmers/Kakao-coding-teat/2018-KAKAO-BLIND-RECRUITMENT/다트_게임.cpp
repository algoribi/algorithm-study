#include <iostream>
#include <string>

using namespace std;

int solution(string dartResult) {
    char score[10];
    int i = 0;
    int j = 0;
    int an[5];
    for (char c : dartResult) {
        score[i] = c;
        i++;
        if (c >= '0' && c <= '9') {
            if (i != 1) {
                j++;
            }
            if (c == '0' && score[i - 2] == '1') {
                j--;
                an[j] *= 10;
            } else {
                an[j] = c - '0';
            }
        } else if (c == 'S')
            continue;
        else if (c == 'D') {
            an[j] *= an[j];
        } else if (c == 'T') {
            an[j] = an[j] * an[j] * an[j];
        } else if (c == '*') {
            if (j == 0) {
                an[j] *= 2;
            } else {
                an[j - 1] *= 2;
                an[j] *= 2;
            }
        } else if (c == '#') {
            an[j] *= -1;
        }
    }
    int answer = 0;
    for (int i = 0; i < 3; i++) {
        answer += an[i];
    }
    return answer;
}