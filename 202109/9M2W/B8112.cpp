#define _CRT_SECURE_NO_WARNINGS
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
#define MOD 100000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<bool> vtd;
queue<pair<int, string>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, next;
	pair<int, string> now;
	string result;
	cin >> T;
	while (T--) {
		cin >> N;
		vtd.resize(N + 1, false);
		result = "BRAK";
		q.push({ 1, "1" });
		vtd[1] = true;
		while (!q.empty()) {
			now = q.front();
			q.pop();
			next = (now.first * 10) % N;
			if (!next) {
				result = now.second + "0";
				break;
			}
			if (!vtd[next]) {
				vtd[next] = true;
				q.push({ next, now.second + "0" });
			}
			next = (next + 1) % N;
			if (!next) {
				result = now.second + "1";
				break;
			}
			if (!vtd[next]) {
				vtd[next] = true;
				q.push({ next, now.second + "1" });
			}
		}
		if (N == 1) cout << 1 << '\n';
		else cout << result << '\n';
		vtd.clear();
		q = queue<pair<int, string>>();
	}
	return 0;
}