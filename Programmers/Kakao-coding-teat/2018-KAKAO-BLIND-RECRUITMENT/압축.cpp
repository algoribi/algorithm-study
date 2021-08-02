#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dic = {"-", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P",
                          "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    for (int i = 0; i < msg.size(); i++) {
        int save;
        string temp = "";
        while (1) {
            temp.push_back(msg[i]);
            auto iter = find(dic.begin(), dic.end(), temp);
            if (iter != dic.end()) {
                save = iter - dic.begin();
                i++;
            } else {
                answer.push_back(save);
                dic.push_back(temp);
                i--;
                break;
            }
        }
    }
    return answer;
}