#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

multiset<int> ms;
priority_queue<pair<int,int>> pq;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, N, K, temp, cur;
	int mi, vi;
	long long result;

	pair<int, int> X;
	multiset<int>::iterator it;

	cin >> N >> K;
	for (i = 0; i < N; i++) { cin >> mi >> vi; pq.push({ vi, mi }); }
	for (i = 0; i < K; i++) { cin >> temp; ms.insert(temp); }
	result = 0;
	while (!pq.empty()) {
		if (!ms.size()) break;
		X = pq.top();
		it = ms.lower_bound(X.second);
		if (it != ms.end()) {
			ms.erase(it);
			result += X.first;	
		}
		pq.pop();
	}
	cout << result;
	return 0;
}
