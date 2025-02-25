#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;
const int MAXN = 1e6 + 11;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int range(int l, int r) {
    return ((rng() % (r - l + 1)) + l);
}

int a[MAXN];

void gen(int x) {
    ofstream os;
    ofstream inp(("Input_Data" + (string)"\\" + "input_" + (string)(x < 10 ? "0" : "") + to_string(x) + ".txt").c_str());

    int n = 1000000;

    for(int i = 1; i <= n; i ++)
        a[i] = range(-INF, INF);

    if(x == 1 || x == 10)
        sort(a + 1, a + n + 1);

    if(x == 10)
        reverse(a + 1, a + n + 1);

    inp << n << '\n';
    for(int i = 1; i <= n; i ++)
        inp << a[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int NumTest = 10;
    int TestL = 1, TestR = TestL + NumTest - 1;
    for(int i = TestL; i <= TestR; i ++)
        gen(i);

    return 0;
}
