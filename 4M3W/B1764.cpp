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


map<string, int> m;
vector<string> ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, N, M;
	string s1;

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> s1;
		m[s1] = 1;
	}
	for (i = 0; i < M; i++) {
		cin >> s1;
		if (m.count(s1)) {
			ans.push_back(s1);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

}
