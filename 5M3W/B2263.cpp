#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
using namespace std;


vector<vector<int>> v;
vector<vector<int>> Node; //P|L|R
stack<int> s;

/*
Test Case
17
4 2 5 8 1 13 9 6 14 10 15 3 16 11 17 7 12
4 8 5 2 13 9 14 15 10 6 16 17 11 12 7 3 1
*/

void preorder(int target) {
	cout << target << " ";
	if (Node[target][0]) preorder(Node[target][0]);
	if (Node[target][1]) preorder(Node[target][1]);
	return;
}

void inorder(int target) {
	if (Node[target][0]) inorder(Node[target][0]);
	cout << target << " ";
	if (Node[target][1]) inorder(Node[target][1]);
	return;
}

void postorder(int target) {
	if (Node[target][0]) postorder(Node[target][0]);
	if (Node[target][1]) postorder(Node[target][1]);
	cout << target << " ";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, before;
	cin >> N;
	v.resize(2, vector<int>(N + 1, 0));
	Node.resize(N + 1, vector<int>(2, 0));
	for (i = 0; i < N; i++) cin >> v[0][i];
	for (i = 0; i < N; i++) cin >> v[1][i];
	i = j = 0;
	before = 0;
	while (true) {
		if (i == N && j == N) break;

		if (v[0][i] == v[1][j]) {
			if (before) {
				//cout << "Node " << v[0][i] << "'s Left : " << before << "\n";
				Node[v[0][i]][0] = before;
				before = 0;
			}
			before = v[0][i];
			j++;
			if (s.empty() || v[1][j] != s.top()) i++;	 
		}
		else {
			if (!s.empty() && v[1][j] == s.top()) {
				if (before) {
					//cout << "Node " << v[1][j] << "'s Right : " << before << "\n";
					Node[v[1][j]][1] = before;
					before = 0;
				}
				before = s.top();
				s.pop();
				j++;
				if (s.empty() || v[1][j] != s.top()) i++;
			}
			else {
				if (before) {
					//cout << "Node " << v[0][i] << "'s Left : " << before << "\n";
					Node[v[0][i]][0] = before;
					before = 0;
				}
				//cout << "Node " << v[0][i] << " Pushed" << "\n";
				s.push(v[0][i]);
				i++;
			}
		}
	}

	preorder(v[1][N - 1]);
	return 0;
}