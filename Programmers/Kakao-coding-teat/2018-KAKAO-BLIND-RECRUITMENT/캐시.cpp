#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0)
        return cities.size() * 5;
    vector<string> cache;
    int answer = 0;
    for (int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        string temp = cities[i];
        int chk = 0;
        for (int j = 0; j < cache.size(); j++) {
            if (temp == cache[j]) {
                cache.erase(cache.begin() + j);
                cache.push_back(temp);
                answer++;
                chk = 1;
                break;
            }
        }
        if (chk == 0) {
            answer += 5;
            if (cache.size() >= cacheSize)
                cache.erase(cache.begin());
            cache.push_back(temp);
        }
    }
    return answer;
}