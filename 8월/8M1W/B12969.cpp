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

vector<int> v; //ABC 문자열 중 가능한 S의 최대 개수
int N, K;


string getMax(int len) {
    string result = "";
    int cnt = len / 3;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j < cnt; j++) result += 'A' + i;
        if (i == 2 && len % 3 >= 1) result += "C";
        else if (i == 1 && len % 3 == 2) result += "B";
    }
    return result;
}

string parseByIndex(string s, int idx) {
    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == idx) result += "C";
        result += s[i];
    }
    return result;
}

string fillAnswer(string s, int fSize) {
    string result = "";
    fSize -= s.size();
    for (int i = 0; i < fSize; i++) result += 'C';
    return result + s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //전처리 Setting vector v
    v.push_back(0);
    int i, cnt;
    cnt = 0;
    for (i = 1; i <= 30; i++) {
        v.push_back(v[i - 1] + cnt);
        if(i % 3) cnt++;
    }
    
    string result;
    cin >> N >> K;
    if (v[N] < K) {
        cout << -1;
        return 0;
    }
    int tar = lower_bound(v.begin(), v.end(), K) - v.begin();
    if (v[tar] == K) result = getMax(tar);
    else result = parseByIndex(getMax(tar - 1), K - v[tar - 1]);
    cout << fillAnswer(result, N);

    return 0;
}