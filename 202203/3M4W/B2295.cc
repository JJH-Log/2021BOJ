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


set<lld> s;
lld N, v[1000];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v, v + N);

	for (int i = 0; i < N; i++){
		for (int j = i; j < N; j++){
			s.insert(v[i] + v[j]);
		}
	}
	for (int i = N - 1; i >= 0; i--){
		for (int j = 0; j <= i; j++){
			if(s.count(v[i] - v[j])){
				cout << v[i];
				return 0;
			}
		}
	}

	return 0;
}