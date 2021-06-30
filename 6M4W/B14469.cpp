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
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, x, y, N;
	int t;
	pair<int, int> now;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> x >> y;
		pq.push({ x, y });
	}
	t = 0;
	while (!pq.empty()) {
		now = pq.top();
		if (t <= now.first) t = now.first + now.second;
		else t += now.second;
		pq.pop();
	}
	cout << t;
	return 0;
}