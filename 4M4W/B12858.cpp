#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <string>
#include <stack>
#include <map>
using namespace std;

vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, C;
	string s;
	cin >> N;
	v.resize(N + 1, ".");
	v[1] = "0";
	for (i = 1; i <= N; i++) {
		if (i * 3 <= N) { if ((v[i * 3] == ".") || (v[i].length() + 1 <= v[i * 3].length())) v[i * 3] = v[i] + "A"; }
		if (i * 2 <= N) { if ((v[i * 2] == ".") || (v[i].length() + 1 <= v[i * 2].length())) v[i * 2] = v[i] + "B"; }
		if (i != N) { if ((v[i + 1] == ".") || (v[i].length() + 1 <= v[i + 1].length())) v[i + 1] = v[i] + "C"; }
	}
	reverse(v[N].begin(), v[N].end());
	cout << v[N].length() - 1 << "\n";
	i = 0;
	C = N;
	while (true) {
		cout << C << " ";
		if (v[N][i] == '0') break;
		if (v[N][i] == 'A') C /= 3;
		if (v[N][i] == 'B') C /= 2;
		if (v[N][i] == 'C') C -= 1;
		i++;
	}
}

