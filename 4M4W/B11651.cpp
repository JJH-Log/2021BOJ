#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int>b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, x, y;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), compare);
	for (i = 0; i < N; i++) cout << v[i].first << " " << v[i].second << "\n";
}

