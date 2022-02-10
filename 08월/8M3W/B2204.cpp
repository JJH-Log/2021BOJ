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

string lower(string s) {
    string result = "";
    for (int i = 0; i < s.size(); i++) {
        result += tolower(s[i]);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        string s1, s2;
        int i, N;
        cin >> N;
        if (!N) break;
        cin >> s1;
        for (i = 1; i < N; i++) {
            cin >> s2;
            if (lower(s1) > lower(s2)) swap(s1, s2);
        }
        cout << s1 << '\n';
    }

}