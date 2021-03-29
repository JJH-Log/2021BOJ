#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

vector<pair<int,int>> v;

int main() {
	int i, N, token;
	int p1 = 0, p2 = 0, result = 0, total = 0;
	string s;
	cin >> N;
	cin >> s;

	v.resize(26, make_pair(0,100001));
	while (true) {
		if (total <= N) {
			if (p2 == s.length()) break;
			if ((p2 - p1) > result) result = p2 - p1;
			token = s[p2] - 'a';
			if (v[token].first == 0) {
				v[token].first = 1;
				total++;
			}
			v[token].second = p2;
			p2++;
		}
		else {
			token = 0;
			for (i = 0; i < 26; i++) {
				if (v[i].second < v[token].second) token = i;
			}
			p1 = v[token].second + 1;
			v[token].first = 0;
			v[token].second = 100001;
			total--;
		}
	}
	if ((p2 - p1) > result) result = p2 - p1;
	cout << result;
	return 0;
}