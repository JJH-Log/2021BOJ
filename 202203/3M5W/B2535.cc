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
#define MOD 998244353
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct info {
	int ct, num, score;
};

bool compare(info a, info b) {
	return a.score > b.score;
}

info v[100];
int N;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i].ct >> v[i].num >> v[i].score;
	sort(v, v + N, compare);

	cout << v[0].ct << ' ' << v[0].num << '\n';
	cout << v[1].ct << ' ' << v[1].num << '\n';

	if (v[0].ct == v[1].ct) {
		int j = 2;
		while (v[0].ct == v[j].ct) j++;
		cout << v[j].ct << ' ' << v[j].num << '\n';
	}
	else cout << v[2].ct << ' ' << v[2].num << '\n';


	return 0;
}