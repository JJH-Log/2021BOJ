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

int N, res, ans;
int v[100000];
int w[100000];
string s;

void flip(int idx){
	if(idx > 0) w[idx - 1] ^= 1;
	w[idx] ^= 1;
	if(idx < N - 1) w[idx + 1] ^= 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> s;
	for (int i = 0; i < N; i++) v[i] = s[i] - '0';
	cin >> s;
	for (int i = 0; i < N; i++) v[i] = v[i] ^ (s[i] - '0');
	
	for (int i = 0; i < N; i++) w[i] = v[i];
	res = 1e9; ans = 0;
	for (int i = 1; i < N; i++) if(w[i - 1]) ans++, flip(i);
	if(!w[N - 1]) res = min(res, ans);

	for (int i = 0; i < N; i++) w[i] = v[i];
	ans = 0; flip(0);
	for (int i = 1; i < N; i++) if(w[i - 1]) ans++, flip(i);
	if(!w[N - 1]) res = min(res, ans + 1);

	cout << (res == 1e9? -1 : res);

	return 0;
}