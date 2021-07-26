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

priority_queue<lld, vector<lld>, greater<lld>> pq;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lld i, t, T;
	int temp;
	lld fa, fb;
	lld result;
	cin >> T;
	for (t = 0; t < T; t++) {
		cin >> N;
		for (i = 0; i < N; i++) {
			cin >> temp;
			pq.push(temp);
		}
		result = 0;
		while (pq.size() != 1) {
			fa = pq.top();
			pq.pop();
			fb = pq.top();
			pq.pop();
			result += fa + fb;
			pq.push(fa + fb);
		}
		while(!pq.empty()) pq.pop();
		cout << result << '\n';
	}

	return 0;
}