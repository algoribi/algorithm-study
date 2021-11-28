#include<bits/stdc++.h>
using namespace std;

string solution(string source) {
	string answer = "";
	while (!source.empty()) {
		int alpha[26] = { 0 };
		int alpha2[26] = { 0 };
		string dest = "";
		string tempsource = "";
		for (char c : source) {
			if (alpha[c - 'a'] == 0) {
				dest += c;
				alpha[c - 'a'] = 1;
			}
		}

		for (int i = 0; i < source.size(); i++) {
			if (alpha[source[i] - 'a'] && alpha2[source[i] - 'a'] == 0) {
				alpha2[source[i] - 'a'] = 1;
			}
			else
				tempsource += source[i];
		}

		sort(dest.begin(), dest.end());
		answer += dest;
		source = tempsource;

	}
	return answer;
}