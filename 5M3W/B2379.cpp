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

vector<vector<int>> v;
vector<string> rv;
vector<string> rvc;

void makeTree(string s) {
	int i, d;
	v.clear();
	v.push_back(vector<int>({ 0, 0 }));
	d = 0;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			v[d].back()++;
			d++;
			if (v.size() < d + 1) v.push_back(vector<int>({ 0, 0 }));
			else v[d].push_back(v[d].back());
		}
		else d--;
	}
	return;
}


void parsing(string s, int d, int idx) {
	int i, len;
	len = v[d][idx] - v[d][idx - 1];
	if (!len) {
		rv.push_back(s + " 0");
		return;
	}
	else {
		for (i = 1; i <= len ; i++) parsing(s + " " + to_string(len), d + 1, v[d][idx - 1] + i);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t, T, FLAG; //d for depth
	string sv;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> sv;
		makeTree(sv);
		rv.clear();
		parsing("#", 0, 1);
		rvc.clear();
		rvc = rv;
		cin >> sv;
		makeTree(sv);
		rv.clear();
		parsing("#", 0, 1);

		sort(rv.begin(), rv.end());
		sort(rvc.begin(), rvc.end());
		FLAG = 1;
		if (rv.size() != rvc.size()) FLAG = 0;
		else {
			for (i = 0; i < rv.size() && FLAG; i++) if (rv[i] != rvc[i]) FLAG = 0;
		}
		cout << FLAG << '\n';
	}
	return 0;
}
