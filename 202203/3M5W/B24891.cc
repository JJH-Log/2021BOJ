#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int L, N;
int w[5];
bool lock[20];

string s[20];
set<string> res;

void backTracking(int cnt) {
	if (cnt == L) {
		vector<string> tmp;
		for (int i = 0; i < L; i++) tmp.push_back(s[w[i]]);
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < L; j++) {
				if (tmp[i][j] != tmp[j][i]) return;
			}
		}
		string ans = "";
		for (int i = 0; i < L; i++) ans += tmp[i];
		res.insert(ans);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!lock[i]) {
			lock[i] = true;
			w[cnt] = i;
			backTracking(cnt + 1);
			lock[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> L >> N;
	for (int i = 0; i < N; i++) cin >> s[i];
	backTracking(0);
	if (!res.size()) cout << "NONE";
	else {
		string ans = (*res.begin());
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < L; j++) cout << ans[L * i + j];
			cout << '\n';
		}
	}


	
	return 0;
}