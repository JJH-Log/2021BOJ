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
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v; //for count
map<int, int> m; //for computer
priority_queue<int, vector<int>, greater<int>> fq; //for free computer
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result, i, N, x, y;
	result = 0;
	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> x >> y;
		pq.push({ x, i });
		pq.push({ y, -i });
	}
	while (!pq.empty()) {
		pair<int,int> now = pq.top();
		pq.pop();
		if (now.second > 0) {
			if (fq.empty()) {
				v.push_back(0);
				fq.push(result);
				result++;
			}
			m[now.second] = fq.top();
			v[fq.top()]++;
			fq.pop();
		}
		else fq.push(m[-now.second]);
	}
	cout << result << '\n';
	for (i = 0; i < v.size(); i++) cout << v[i] << ' ';

	return 0;
}