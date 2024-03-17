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
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<vector<int>> v; //i, j : i~j 까지의 유전자 최대 길이
int N; 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    N = s.size();
    v.resize(N, vector<int>(N, 0));
    int i, j, k;
   
    for (i = 1; i < N; i++) {
        for (j = 0; j + i< N; j++) {
            if (s[j] == 'a' && s[j + i] == 't') v[j][j + i] = v[j + 1][j + i - 1] + 2;
            if (s[j] == 'g' && s[j + i] == 'c') v[j][j + i] = v[j + 1][j + i - 1] + 2;
            for (k = 1; k < j + i ; k++) v[j][j + i] = max(v[j][j + i], v[j][k] + v[k][j + i]);
        }
    }
    cout << v[0][N - 1];

    return 0;
}