#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#define MOD 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y, N;
	int result, cnt;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		pq.push({ x, 1 });
		pq.push({ y,-1 });
	}
	cnt = 0; result = 0;
	while (!pq.empty()) {
		cnt += pq.top().second;
		result = max(result, cnt);
		pq.pop();
	}
	cout << result;
	return 0;
}