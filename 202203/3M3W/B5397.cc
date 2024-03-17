#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#define MOD 1000000007
#define BOUND 1000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 2002
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct node {
	char c;
	node* l, * r;
	node(char x):c(x) {
		l = 0;
		r = 0;
	}
};

node* head;
node* curr;

void _remove() {
	if (curr == head) return;
	if(curr->r != 0) curr->r->l = curr->l;
	curr->l->r = curr->r;
	curr = curr->l;
}

void _insert(char x) {
	node* tmp = new node(x);
	if (curr->r != 0) curr->r->l = tmp;
	tmp->l = curr;
	tmp->r = curr->r;
	curr->r = tmp;
	curr = curr->r;
}

void _move(int op) {
	if (op == 0 && curr->l != 0) curr = curr->l;
	if (op == 1 && curr->r != 0) curr = curr->r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {

		string s;
		cin >> s;

		head = new node(' ');
		curr = head;

		for (auto x : s) {
			if (x == '-') _remove();
			else if (x == '<') _move(0);
			else if (x == '>') _move(1);
			else _insert(x);
		}

		curr = head->r;

		while (curr != 0) {
			cout << curr->c;
			curr = curr->r;
		}
		cout << '\n';
	}
	return 0;
}