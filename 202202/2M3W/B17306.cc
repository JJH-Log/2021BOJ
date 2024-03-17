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

struct node {
	node* next[2];
	int chk;
	node() {
		chk = 0;
		next[0] = next[1] = 0;
	};
};

vector<string> v;
string encode(lld X) {
	string ans = "";
	while (X) {
		if (X % 2) ans += '1';
		else ans += '0';
		X /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int N, result;
node* root;

void dfs(node* now) {
	for (int i = 0; i < 2; i++) {
		if (now->next[i] && now->next[i]->chk == N) {
			result--;
			dfs(now->next[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		lld x;
		cin >> x;
		v.push_back(encode(x));
	}
	sort(v.begin(), v.end());
	root = new node();
	for (auto now : v) {
		node* cur = root;
		for (int i = 0; i < now.size(); i++) {
			if (!cur->next[now[i] - '0']) {
				cur->next[now[i] - '0'] = new node();
				result++;
			}
			cur = cur->next[now[i] - '0'];
			cur->chk++;
		}
	}
	dfs(root);

	cout << result + 1;
	

	return 0;
}
