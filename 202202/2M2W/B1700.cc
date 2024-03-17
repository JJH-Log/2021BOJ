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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

int N, K;
int v[100];
pii now[100];
map<int, int> m;
int link[100];
int res;

void assign(int idx, int X) {
	/* Check now & empty */
	for (int i = 0; i < N; i++) {
		if (now[i].second == X || now[i].second == 0) {
			now[i] = { idx, X };
			return;
		}
	}

	/* Check end & latest */
	int tar = 0, late = 0;
	for (int i = 0; i < N; i++) {
		if (link[now[i].first] == -1) {
			tar = i;
			break;
		}
		if (link[now[i].first] > late) {
			tar = i;
			late = link[now[i].first];
		}
	}
	now[tar] = { idx, X };
	res++;
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < K; i++) link[i] = -1;
	for (int i = 0; i < K; i++) {
		cin >> v[i];
		if (!m.count(v[i])) m[v[i]] = i;
		else link[m[v[i]]] = i, m[v[i]] = i;
	}
	res = 0;
	for (int i = 0; i < K; i++) assign(i, v[i]);
	cout << res;

	return 0;
}
