// algorithm study
// BOJ_4378_트ㅏㅊ;

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> Keyboard = {"`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"};
    string s;
    while (getline(cin, s)) {
        for (char c : s) {
            if (c == ' ')
                cout << " ";
            else {
                int chk = 0;
                for (int i = 0; i < Keyboard.size(); i++) {
                    for (int j = 0; j < Keyboard[i].size(); j++) {
                        if (c == Keyboard[i][j]) {
                            cout << Keyboard[i][j - 1];
                            chk = 1;
                            break;
                        }
                    }
                    if (chk == 1)
                        break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}