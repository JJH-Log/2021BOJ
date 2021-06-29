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

set<int> S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int M, i, temp;
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> s;
		if (s == "all") S = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		else if (s == "empty") S.clear();
		else {
			cin >> temp;
			if (s[0] == 'a') S.insert(temp);
			if (s[0] == 'r') S.erase(temp);
			if (s[0] == 'c') cout << S.count(temp) << "\n";
			if (s[0] == 't') {
				if (S.count(temp)) S.erase(temp);
				else S.insert(temp);
			}
		}
	}
	
	return 0;
}