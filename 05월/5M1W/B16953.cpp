#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

queue<pair<int, int>> q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, FLAG;
	pair<int, int> temp;
	cin >> A >> B;
	q.push(make_pair(B, 1));
	FLAG = 0;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp.first == A) {
			while (!q.empty()) q.pop();
			FLAG = 1;
		}
		else if (temp.first > A) {
			if (temp.first % 2 == 0) q.push(make_pair(temp.first / 2, temp.second + 1));
			if (temp.first % 10 == 1) q.push(make_pair(temp.first / 10, temp.second + 1));
		}
	}
	if (FLAG) cout << temp.second;
	else cout << "-1";
	return 0;
}