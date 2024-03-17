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

int N, M;
string tar, v[1000];
int total, cnt[4], ans[1000];
string res;

int getDist(int a, int b){
	int tmp = 0;
	for(int i = 0; i < M; i++) if(v[a][i] != v[b][i]) tmp++;
	return tmp;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> v[i];
	tar = "ACGT"; res = "";
	for (int i = 0; i < M; i++){
		memset(cnt, 0, sizeof cnt);
		for (int j = 0; j < N; j++) cnt[tar.find(v[j][i])]++;
		int tmp = 0;
		for (int j = 0; j < 4; j++) if(cnt[tmp] < cnt[j]) tmp = j;
		res += tar[tmp];
		total += N - cnt[tmp];
	}
	cout << res << '\n' << total;

	return 0;
}