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

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, t1, t2, N, result;
	cin >> N;
	for (i = 0; i < N; i++) cin >> t1, pq.push(t1);
	result = 0;
	while (pq.size() != 1) {
		t1 = pq.top();
		pq.pop();
		t2 = pq.top();
		pq.pop();
		result += t1 + t2;
		pq.push(t1 + t2);
	}
	cout << result;



	return 0;
}