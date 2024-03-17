#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <math.h>
#include <set>
#include <cassert>
#include <bitset>
#include <sstream>
#include <cmath>
#include <random>
#include <numeric>
#include <regex>
#define MOD 1000000000
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct node {
	node* next[26];
	node(){
		for (int i = 0; i < 26; i++) next[i] = 0;
	}
};

int N, M, res;
string tar;
node* head;

bool isSuffix(string x) {
	node* curr = head;
	for (auto c : x) {
		if (!curr->next[c - 'a']) return false;
		curr = curr->next[c - 'a'];
	}
	return true;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	head = new node();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tar;
		node* curr = head;
		for (auto c : tar) {
			if (!curr->next[c - 'a']) curr->next[c - 'a'] = new node();
			curr = curr->next[c - 'a'];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> tar;
		res += isSuffix(tar);
	}
	cout << res;

	return 0;
}