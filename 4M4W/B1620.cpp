#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

map<string, int> m;
map<int, string> m2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, M;
	string temp;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> temp;
		m[temp] = i + 1;
		m2[i + 1] = temp;
	}
	for (i = 0; i < M; i++) {
		cin >> temp;
		if (temp[0] >= '0' && temp[0] <= '9') {
			cout << m2[stoi(temp)] << "\n";
		}
		else cout << m[temp] << "\n";
	}
	return 0;
}

