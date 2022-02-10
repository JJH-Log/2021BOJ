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
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int i, N, L, idx;
	pair<int, int> now;
	cin >> N >> L;
	v.resize(N, 0);
	for (i = 0; i < N; i++) cin >> v[i];
	
	idx = 0;
	while (idx != N) {
		pq.push({ v[idx], idx });
		now = pq.top();
		if (now.second >= (idx + 1) - L) cout << now.first << ' ';
		if (now.second == (idx + 1) - L) pq.pop();
		else if (now.second <= (idx + 1) - L) pq.pop(), idx--;
		idx++;
	}

	return 0;
}