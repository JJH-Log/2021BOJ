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

struct info{
	int x, out, idx; //1:out 0:in
};

struct cmp{
	bool operator()(info A, info B){
		if(A.x == B.x) return A.out > B.out;
		return A.x > B.x;
	}
};

priority_queue<info, vector<info>, cmp> pq;
int g[100001];
int N, M, cnt, num;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		pq.push({x1, 0, i});
		pq.push({x2, 1, i});
	}
	num = 1;
	while(!pq.empty()){
		info now = pq.top(); pq.pop();
		if(now.out){
			cnt--;
			if(cnt == 0) num++;
		}
		else{
			cnt++;
			g[now.idx] = num;
		}
	}

	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		cout << (g[a] == g[b]) << '\n';
	}

	return 0;
}