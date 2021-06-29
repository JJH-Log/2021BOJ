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


string pp(string A, string B) {
	vector<int> a;
	vector<int> b;
	int i;
	string result = "";
	for (i = A.size() - 1; i >= 0; i--) a.push_back(A[i] - '0');
	for (i = B.size() - 1; i >= 0; i--) b.push_back(B[i] - '0');
	if (a.size() < b.size()) swap(a, b);
	for (i = 0; i < b.size(); i++) a[i] += b[i];
	for (i = 0; i < a.size(); i++) {
		if (a[i] >= 10) {
			if (i == (a.size() - 1)) a.push_back(1);
			else a[i + 1]++;
			a[i] %= 10;
		}
	}
	for (i = a.size() - 1; i >= 0; i--) result += a[i] + '0';
	return result;
}

vector<vector<string>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N, M;
	cin >> N >> M;
	int i, j, nN, nM;
	nN = stoi(N);
	nM = stoi(M);
	v.resize(nN, vector<string>(nN, "1"));
	if (nN == nM) cout << "1";
	else if (nN == 1 || nN - nM == 1) cout << N;
	else {
		for (i = 1; i < nN; i++) {
			for (j = 1; j <= i; j++) {
				v[i][j] = pp(v[i - 1][j - 1], v[i - 1][j]);
			}
		}
		cout << v[nN - 1][nM];
	}
	return 0;
}