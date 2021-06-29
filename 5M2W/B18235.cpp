#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
#include <cmath>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

vector<vector<int>> v;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, A, B, d;
	pair<int, int> b = { 0,0 }; //before
	pair<int, int> n; //now
	cin >> N >> A >> B;
	if ((B - A) % 2) cout << "-1";
	else {
		pq.push({ 0, A });
		pq.push({ 0, B });
		int FLAG = 1;
		while (!pq.empty() && FLAG) {
			n = pq.top();
			pq.pop();
			if (b.first == n.first && b.second == n.second) FLAG = 0;
			else {
				d = pow(2, n.first);
				if (n.second - d > 0) pq.push({ n.first + 1, n.second - d });
				if (n.second + d <= N) pq.push({ n.first + 1, n.second + d });
			}
			b = n;
		}
		if (!FLAG) cout << b.first;
		else cout << "-1";
	}
	
	return 0;
}