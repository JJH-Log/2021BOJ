#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

map<int, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, temp;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> temp;
		if (!m.count(temp)) m[temp] = 1;
		else m[temp]++;
	}
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> temp;
		if (!m.count(temp)) cout << "0 ";
		else cout << m[temp] << " ";
	}
	return 0;
}

