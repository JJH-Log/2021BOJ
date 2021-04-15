#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N;
	int f1 = 1, f2 = 1;
	long long total = 0, M = 0, X, P;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> X >> P;
		if (f1 && (i == N - 1)) f2 = 1;
		else {
			if (total > X) {
				if (!f1) f2 = 0;
				else {
					f1 = 0;
					if (P < M) {
						total -= M;
						if (total > X) total += M;
						else total += P;
					}
				}
			}
			else {
				total += P;
				M = max(M, P);
			}
		}
	}
	if (f2) cout << "Kkeo-eok";
	else cout << "Zzz";
	
	
	return 0;
}
