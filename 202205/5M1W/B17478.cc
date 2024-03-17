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
#define MOD 14579
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
#define MAXN 1000001
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;


void printUnder(int x) { for (int i = 0; i < x; i++) cout << '_'; }

void solve(int cnt) {
	
	printUnder(4 * (N - cnt));
	cout << "\"재귀함수가 뭔가요?\"\n";


	if (cnt == 0) {
		printUnder(4 * (N - cnt));
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	}
	else {
		printUnder(4 * (N - cnt));
		cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		printUnder(4 * (N - cnt));
		cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
		printUnder(4 * (N - cnt));
		cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
		solve(cnt - 1);
	}
	printUnder(4 * (N - cnt));
	cout << "라고 답변하였지.\n";
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	solve(N);
	
	return 0;
}
