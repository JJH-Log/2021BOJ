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
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;


vector<int> w1; //cnt, word
vector<int> w2; //cnt, word
vector<string> words;

void combine(string s, int idx, int l, int r, int flag) {
    int i;
    for (i = l + idx; i < r; i++) combine(s + words[i], i + 1 - l, l, r, flag);
    vector<bool> al;
    int total = 0;
    al.resize(26, false);
    for (i = 0; i < s.size(); i++) al[s[i] - 'a'] = true;
    for (i = 0; i < 26; i++) {
        if (al[i])  total += (1 << i);
    }
    if (!flag) w1.push_back(total);
    else w2.push_back(total);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, N;
    int cnt, result;
    cin >> N;
    words.resize(N);
    for (i = 0; i < N; i++) cin >> words[i];
    combine("", 0, 0, N / 2, 0);
    combine("", 0, N / 2, N, 1);
    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());

    result = 0;
    for (i = 0; i < w1.size(); i++) {
        for (j = 0; j < w2.size(); j++) {
            if ((w1[i] | w2[j]) == 0x3FFFFFF) result++;
        }
    }
    cout << result;
    return 0;
}