#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000000
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

priority_queue<int> pq;
vector<int> v;
int N, M, L;

bool isProper(int bound) {
	priority_queue<int> temp;
	int now, cnt;
	temp = pq;
	cnt = 0;
	while (!temp.empty()) {
		now = temp.top();
		temp.pop();
		while (now > bound) {
			now -= bound;
			cnt++;
		}
		if (cnt > M) return false;
	}
	return true;
}

int ans(int l, int r) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	if (isProper(mid)) return ans(l, mid);
	else return ans(mid + 1, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, before, now;
	cin >> N >> M >> L;
	
	v.resize(N);
	for (i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	before = 0; now = 0;
	for(i=0;i<N;i++){
		now = v[i];
		pq.push(now - before);
		before = now;
	}
	pq.push(L - now);

	cout << ans(1, 1000);

	return 0;
}