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

set<int> s;
vector<int> v;
vector<int> c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, result, temp, before, zf, l; //zeroflag
	cin >> N;

	result = 0;
	zf = 0;
	for (i = 0; i < N; i++) {
		cin >> temp;
		if (!temp) zf++;
		else v.push_back(temp), c.push_back(1);
	}
	sort(v.begin(), v.end());
	l = v.size();
	for (i = 0; i < l; i++) {
		for (j = i + 1; j < l; j++) {
			temp = v[i] + v[j];
			if (temp >= v[0] && temp <= v[l - 1]) s.insert(temp);
		}
	}
	for (i = 0; i < l; i++) { if (s.count(v[i])) c[i] = 2; }
	if (zf) {
		if (zf <= 2) { if (s.count(0)) result += zf; }
		else result += zf;
		for (i = 0; i < l; i++) {
			if (!i) before = v[0];
			else {
				if (before == v[i]) c[i] = c[i - 1] = 2;
				else before = v[i];
			}
		}
	}
	for (i = 0; i < l; i++) { if (c[i] == 2) result++; }
	//for (const auto& i : s) cout << i << ' ';
	cout << result;
	return 0;
}