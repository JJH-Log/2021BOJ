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


typedef struct Node {
	int key;
	Node* L;
	Node* R;
	Node(int x, Node* a, Node* b) : key(x), L(a), R(b) {}
}Node;

void insertNode(Node* A, Node* B) {
	Node* temp;
	temp = A;
	int FLAG = 1;
	while (FLAG) {
		if (temp->key < B->key) {
			if (temp->R == NULL) FLAG = 0, temp->R = B;
			else temp = temp->R;
		}
		else {
			if (temp->L == NULL) FLAG = 0, temp->L = B;
			else temp = temp->L;
		}
	}
	return;
}

void ans(Node* X) {
	if (X->L != NULL) ans(X->L);
	if (X->R != NULL) ans(X->R);
	cout << X->key << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	Node* Root = NULL;
	while (cin >> N) {
		if (Root == NULL) Root = new Node(N, NULL, NULL);
		else insertNode(Root, new Node(N, NULL, NULL));
	}
	ans(Root);
	return 0;
}