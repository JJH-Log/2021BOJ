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
#include <cassert>
#define MOD 1000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> v; //남은 거스름 돈의 개수
vector<int> w;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    int i, j, M;

    while (true) {
        cin >> s;
        if (cin.eof()) break;
        M = s.size() / 2 + 1;
        v.resize(M, 0);

        v[0] = 1;
        for (i = 0; i < s.size(); i++) {
            w.resize(M, 0);
            for (j = 0; j < M; j++) {
                if (s[i] != ')' && j + 1 < M) w[j + 1] = (w[j + 1] + v[j]) % MOD;
                if (s[i] != '(' && j - 1 >= 0) w[j - 1] = (w[j - 1] + v[j]) % MOD;
            }
            v = w;
            w.clear();
        }
        cout << v[0] << '\n';
        v.clear();
    }


    return 0;
}