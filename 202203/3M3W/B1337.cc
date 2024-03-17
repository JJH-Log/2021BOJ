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

int v[50], N;
int res;

int check(int idx){
	int cnt = 0;
	for(int i = 1; i < 5 && idx + i < N; i++){
		if(v[idx + i] - v[idx] <= 4) cnt++; //중복이 없으므로 대충..
	}
	return 4 - cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);
	res = 5;
	for(int i = 0; i < N; i++) res = min(res, check(i));
	cout << res;

	return 0;
}