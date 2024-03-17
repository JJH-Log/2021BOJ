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

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, K, cnt;
	cin >> N >> K;
	for (i = 1; i <= N; i++) q.push(i);
	cout << "<";
	cnt = 0;
	while (q.size() != 1) {
		if (cnt == K - 1) {
			cnt = 0;
			cout << q.front() << ", ";
		}
		else {
			cnt++;
			q.push(q.front());
		}
		q.pop();
	}
	cout << q.front() << ">";
	return 0;
}