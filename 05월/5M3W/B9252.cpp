#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
using namespace std;


vector<vector<string>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	string s1, s2;
	cin >> s1 >> s2;
	s1 = 'a' + s1;
	s2 = 'b' + s2;
	v.resize(s1.size(), vector<string>(s2.size(), "."));
	for (i = 1; i < s1.size(); i++) {
		for (j = 1; j < s2.size(); j++) {
			if (s1[i] == s2[j]) v[i][j] = v[i - 1][j - 1] + s1[i];
			else {
				if (v[i - 1][j].size() <= v[i][j - 1].size()) v[i][j] = v[i][j - 1];
				else v[i][j] = v[i - 1][j];
			}
		}
	}
	cout << size(v[s1.size() - 1][s2.size() - 1]) - 1 << "\n";
	cout << v[s1.size() - 1][s2.size() - 1].substr(1);
	return 0;
}