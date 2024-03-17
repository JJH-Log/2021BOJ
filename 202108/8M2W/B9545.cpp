#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> w;
vector<int> dd; //depth
vector<int> pr;
vector<int> color;
vector<int> cc;

int dfs(int now, int parent) {
	int ans, next;
	if (color[now] == 2) return -1;
	pr[now] = parent; 
	if (color[now] == 1) return now;
	color[now] = 1;

	for (next = 0; next < 26; next++) {
		if (w[now][next]) {
			ans = dfs(next, now);
			if (ans != -1) return ans;
			dd[now] = max(dd[now], 1 + dd[next]);
		}
	}
	color[now] = 2;
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, t, N, T;
	string s;
	cin >> T;
	for (t = 0; t < T; t++) {
		w.resize(26, vector<int>(26, 1));
		dd.resize(26, 0);
		color.resize(26, 0);
		pr.resize(26, 0);
		int ans;

		cin >> N;
		for (i = 0; i < N; i++) {
			cin >> s;
			w[s[0] - 'a'][s[1] - 'a'] = 0;
		}

		for (i = 0; i < 26; i++) {
			ans = dfs(i, -1);
			if (ans != -1) break;
		}
		if (ans != -1) {
			for (i = 0; i < 39; i++) {
				cc.push_back(ans);
				ans = pr[ans];
			}
			reverse(cc.begin(), cc.end());
		}
		else {
			int next, now = 0;
			for (i = 0; i < 26; i++) if (dd[i] > dd[now]) now = i;

			while (dd[now] > 0) {
				cc.push_back(now);
				for (next = 0; next < 26; next++) {
					if (w[now][next] && dd[next] + 1 == dd[now]) {
						now = next;
						break;
					}
				}
			}
			cc.push_back(now);
		}

		int len = (cc.size() + 1) / 2;
		for (i = 0; i < len; i++) {
			for (j = 0; j < len; j++) cout << (char)('a' + cc[i + j]);
			cout << '\n';
		}

		w.clear();
		dd.clear();
		color.clear();
		pr.clear();
		cc.clear();
	}

	return 0;
}
