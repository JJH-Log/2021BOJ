#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;
	int i, j;
	s1 = 'a' + s1;
	s2 = 'b' + s2;
	v.resize(s1.size(), vector<int>(s2.size(), 0));
	for (i = 1; i < s1.size(); i++) {
		for (j = 1; j < s2.size(); j++) {
			if (s1[i] == s2[j]) v[i][j] = v[i - 1][j - 1] + 1;
			else v[i][j] = max(v[i - 1][j], v[i][j - 1]);
		}
	}
	cout << v[i - 1][j - 1];
	return 0;
}