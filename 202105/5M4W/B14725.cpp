#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

struct Node {
	string name;
	map<string, Node*> m;
};

Node* init(string s){
	Node* temp = new Node;
	(*temp).name = s;
	return temp;
}

void dfs(Node* X, int depth) {
	if (!(X->m.size())) return;
	map<string, Node*>::iterator it;
	for (it = X->m.begin(); it != X->m.end(); it++) {
		for (int i = 0; i < depth; i++) cout << "--";
		cout << it->first << '\n';
		dfs(it->second, depth + 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M;
	string s;
	Node* temp;
	Node* Root = init("*");
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> M;
		temp = Root;
		for (j = 0; j < M; j++) {
			cin >> s;
			if (!(*temp).m.count(s)) temp->m[s] = init(s); 
			temp = temp->m[s];
		}
	}
	dfs(Root, 0);
	
	return 0;
}
