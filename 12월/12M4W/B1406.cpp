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
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;
using pii = pair<int, int>;

struct ch {
	char c;
	ch* l, * r;
	ch(char c) :c(c) {
		l = r = 0;
	}
	void add(char x) {
		ch* tmp = new ch(x);
		if (l == 0) {
			tmp->r = this;
			l = tmp;
		}
		else {
			l->r = tmp;
			tmp->l = l;
			tmp->r = this;
			l = tmp;
		}
	}
};

string s;
ch* cur;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cur = new ch('-');
	cin >> s;
	for (int i = 0; i < s.size(); i++) cur->add(s[i]);

	int N;
	char cm, cx;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cm;
		if (cm == 'L' && cur->l != 0) cur = cur->l;
		if (cm == 'D' && cur->r != 0) cur = cur->r;
		if (cm == 'B' && cur->l != 0) {
			cur->l = cur->l->l;
			if (cur->l != 0) cur->l->r = cur;
		}
		if (cm == 'P') {
			cin >> cx;
			cur->add(cx);
		}
	}
	while (cur->l != 0) cur = cur->l;
	while (cur->r != 0) {
		cout << cur->c;
		cur = cur->r;
	}

	return 0;
}
