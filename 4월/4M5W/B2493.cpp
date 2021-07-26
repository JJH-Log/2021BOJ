#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<int> v;
string S;

int make_number(int a, int b) {
	int i;
	int result = 0;
	for (i = a; i <= b; i++) {
		if (S[i] >= '0' && S[i] <= '9') {
			result *= 10;
			result += S[i] - '0';
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t, p, cnt, T, temp;
	int l, r, rr;
	int N;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> S >> N;
		v.clear();
		l = 0; r = N; rr = 0;
		for (i = 0; i < S.size(); i++) {
			if (S[i] == 'R') rr ^= 1;
			else {
				if (rr) r--;
				else l++;
			}
		}
		cin >> S;
		if (r < l) cout << "error\n";
		else {
			p = 1; cnt = 0;
			for (i = 0; i < S.size(); i++) {
				if (S[i] == ',') {
					if (cnt >= l && cnt < r) v.push_back(make_number(p, i - 1));
					p = i; cnt++;
				}
			}
			if (cnt >= l && cnt < r) v.push_back(make_number(p, i - 1));
			if (rr) reverse(v.begin(), v.end());
			cout << "[";
			for (i = 0; i < v.size(); i++) {
				cout << v[i];
				if (i != v.size() - 1) cout << ',';
			}
			cout << "]\n";
		}
	}
	
	return 0;
}