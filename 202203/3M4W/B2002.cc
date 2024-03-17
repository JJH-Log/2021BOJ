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

int N, res;
map<string, int> m;
vector<int> w;
string s;
bool passed[1010];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> s;
		m[s] = i;
	}
	int now = 0;
	for (int i = 0; i < N; i++) {
		cin >> s;
		int tar = m[s];
		passed[tar] = true;
		if (tar == now) while (passed[now]) now++;
		else res++;
	}
	cout << res;

	return 0;
}