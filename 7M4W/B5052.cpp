#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct Node {
	int ep;
	Node* next[10];
};

 Node* newNode() {
	Node* result = (Node*)malloc(sizeof(Node));
	result->ep = 0;
	for (int i = 0; i < 10; i++) result->next[i] = NULL;
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, t, T, FLAG, isInit;
	int n, N;
	string s;
	//Node* head[10];
	cin >> T;
	for (t = 0; t < T; t++) {
		Node* head;
		Node* curr;
		head = newNode();
		cin >> N;
		FLAG = true; 
		for (n = 0; n < N; n++) {
			cin >> s;
			curr = head;
			for (i = 0; i < s.size(); i++) {
				isInit = false;
				if (curr->ep) FLAG = false;
				if (FLAG) {
					if (curr->next[s[i] - '0'] == NULL) {
						isInit = true;
						curr->next[s[i] - '0'] = newNode();
					}
					curr = curr->next[s[i] - '0'];
				}
			}
			if (!isInit) FLAG = false;
			curr->ep = 1;	
		}
		if (FLAG) cout << "YES\n";
		else cout << "NO\n";
	}

	


	return 0;
}