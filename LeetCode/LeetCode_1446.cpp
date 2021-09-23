class Solution {
public:
    int maxPower(string s) {
        int ans = 1, point = 0;
        char c= s[0];
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != c) {   
                 point = i;
                 c = s[i];
            }
            else if (s[i] == c) {
                if (ans < i - point + 1)
                    ans = i - point + 1;              
            }                        
        }
        return ans;
    }
};