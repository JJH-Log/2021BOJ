#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <regex>
#define MOD 1000000007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct word_info {
	string word;
	int cnt;
};

bool cmp(word_info a, word_info b) {
	if (a.cnt == b.cnt) {
		if (a.word.size() == b.word.size()) return a.word < b.word;
		return a.word.size() > b.word.size();
	}
	return a.cnt > b.cnt;
}

map<string, int> m;
word_info v[100000];
int idx, tar, N, M;
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s.size() < M) continue;
		if (m.count(s)) tar = m[s];
		else {
			tar = m[s] = idx;
			v[tar].word = s;
			idx++;
		}
		v[tar].cnt++;
	}
	sort(v, v + idx, cmp);
	for (int i = 0; i < idx; i++) cout << v[i].word << '\n';

	return 0;
}