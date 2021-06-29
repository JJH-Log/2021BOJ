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

struct compare {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, S, T;

	cin >> N;
	
	for (i = 0; i < N; i++) {
		cin >> S >> T;
		pq.push(make_pair(S, 1));
		pq.push(make_pair(T, -1));
	}
	int result = 0;
	int temp = 0;
	while (!pq.empty()) {
		if (pq.top().second == 1) temp++;
		else if (temp != 0) temp--;
		result = max(result, temp);
		pq.pop();
	}

	cout << result;
	return 0;
}
