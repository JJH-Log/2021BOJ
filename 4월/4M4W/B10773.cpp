#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
using namespace std;


stack<int> k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, R, K, temp;
	cin >> K;
	for(i = 0; i < K; i++) {
		cin >> temp;
		if (!temp) k.pop();
		else k.push(temp);
	}
	R = 0;
	while (!k.empty()) {
		R += k.top();
		k.pop();
	}
	cout << R;
}

