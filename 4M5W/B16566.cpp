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
vector<int> u;
int M;

int find(int X) {
	if (u[X] != X) {
		u[X] = find(u[X]);
		return u[X];
	}
	else return X;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp, ans, i, N, K;
	cin >> N >> M >> K;
	v.resize(M, 0);
	u.resize(M, 0);
	for (i = 0; i < M; i++) {
		cin >> v[i];
		u[i] = i;
	}
	sort(v.begin(), v.end());
	for (i = 0; i < K; i++) {
		cin >> temp;
		temp = upper_bound(v.begin(), v.end(), temp) - v.begin();
		temp = find(temp);
		cout << v[temp] << "\n";
		if (temp != M - 1) u[temp] = find(u[temp + 1]);
	}
	return 0;
}

