#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;


vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, N, temp, idx;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> temp;	
		idx = lower_bound(v.begin(), v.end(), temp) - v.begin();
		if (idx == v.size()) v.push_back(temp);
		else v[idx] = temp;
	}
	cout << v.size();
}

