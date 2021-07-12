#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

map<char, int> w;
vector<int> v;
vector<bool> mask;
vector<string> digit;
int C;

int calculate() {
	int result = 0;
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < digit[i].size(); j++) result += v[w[digit[i][j]]];
		if(i) result *= 10;
	}
	//cout << result << ' ' << v[0] << ' ' << v[1] << endl;
	return result;
}


int ans(int cnt) {
	int result = 0;
	if (cnt == C) return calculate();
	for (int i = 0; i < 10; i++) {
		if (mask[i]) {
			mask[i] = false;
			v[cnt] = i;
			result = max(result, ans(cnt + 1));
			mask[i] = true;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	digit.resize(8, "");
	mask.resize(10, true);
	int i, j, N;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		for (j = 0; j < s.size(); j++) {
			if (!w.count(s[j])) w[s[j]] = 0;
			digit[j] += s[j];
		}
	}
	i = 0;
	for (auto it = w.begin(); it != w.end(); i++, it++) it->second = i;
	C = w.size();
	v.resize(C, 0);
	cout << ans(0);
	
	return 0;
}