class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> m;
        m[5] = 0;
        m[10] = 0;
        for (int i = 0; i < bills.size(); i++) {
            cout<<m[5]<<", "<<m[10]<<endl;
            if (bills[i] == 5) {
                m[5]++;
                continue;
            }
            if (bills[i] == 10 && m[5] < 1)
                return false;
            else if(bills[i] == 10 && m[5] >= 1) {
                m[5]--;
                m[10]++;
            }
            if (bills[i] == 20) {
                if (m[10] >= 1 && m[5] >= 1) {
                    m[10]--;
                    m[5]--;
                } else if (m[10] < 1 && m[5] >= 3)
                    m[5] -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};
