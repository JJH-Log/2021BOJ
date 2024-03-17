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

map<string, string> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	int i, N, M;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> s1 >> s2;
		m[s1] = s2;
	}
	for (i = 0; i < M; i++) {
		cin >> s1;
		cout << m[s1] << "\n";
	}
	return 0;
}