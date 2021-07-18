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
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXLEN 10000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<vector<int>> v;
vector<int> w;
queue<int> q;


int backTracking(int cnt, int idx, int som) {
	int result = 0;
	if (cnt == 7) {	
		if (som < 4) return 0;
		else {
			vector<int> check = { 1, 0, 0, 0, 0, 0, 0 };
			q.push(w[0]);
			while (!q.empty()) {
				int x = q.front() / 5;
				int y = q.front() % 5;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int dx = x + "2011"[i] - '1';
					int dy = y + "1120"[i] - '1';
					if (dx >= 0 && dx < 5 && dy >= 0 && dy < 5) {
						for (int j = 0; j < 7; j++) {
							if (!check[j] && w[j] == (5 * dx + dy)) check[j] = 1, q.push(w[j]);
						}
					}
				}
			}
			for (int j = 0; j < 7; j++) if (!check[j]) return 0;
			return 1;
		}
	}
	for (int i = idx; i < 25; i++) {
		w[cnt] = i;
		result += backTracking(cnt + 1, i + 1, som + v[i / 5][i % 5]);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v.resize(5, vector<int>(5, 0));
	w.resize(7, 0);
	string s;
	for (int i = 0; i < 5; i++) {
		cin >> s;
		for (int j = 0; j < 5; j++) if (s[j] == 'S') v[i][j] = 1;
	}
	cout << backTracking(0, 0, 0);
	
	return 0;
}