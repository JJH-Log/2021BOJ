#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int N, M;
vector<int> idx;
vector<int> result;

int asc(char c) {
	if (c == ' ') return -1;
	if (c >= 'a' && c <= 'z') return c - 'a';
	if (c >= 'A' && c <= 'Z') return c - 'A';
	return c - '0' + 26;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string word, text;
	int i, j, T;
	cin >> T;
	cin.ignore();
	while (T--) {
		getline(cin, word);
		getline(cin, text);
		N = text.size();
		M = word.size();
		idx.resize(M + 1, 0);
		idx[0] = 1e9;
		for (i = 0; i < N; i++) {
			for (j = 1; j <= M; j++) {
				if (asc(text[i]) == asc(word[j - 1])) {
					if (idx[j - 1] > idx[j]) {
						idx[j]++;
						if (j == M) result.push_back(i + 1);
					}
				}
			}
		}
		cout << result.size() << ' ';
		for (i = 0; i < min(3, (int)result.size()); i++) cout << result[i] << ' ';
		cout << '\n';

		idx.clear();
		result.clear();
	}

	return 0;
}