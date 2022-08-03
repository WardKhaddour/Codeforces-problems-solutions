#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define ln "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define dbg cout << "HERE!!!" << endl
#define sort1(v) sort(v.begin(), v.end())
#define sort2(v) sort(v.rbegin(), v.rend())
#define reverse1(v) reverse(v.begin(), v.end())
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, s, n) for (int i = s; i <= n; ++i)
#define sz(x) ((int)(x).size())
#define clr(arr, n) memset(arr, n, sizeof(arr));
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)

#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

const int N = 1e5 + 5;
const int P = 1e9 + 7;
const int OO = INT_MAX;

int dx[] = {0, 1, 1, 1};
int dy[] = {1, 0, -1, 1};

int gr[N][3];
int dp[N][3];
int n;

bool isValidPos(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < 3)
        return true;
    return false;
}
int findShortestPath(int i, int j)
{
    // shortest path from 0, 1 to n - 1, 1
    if (i == n - 1 && j == 1)
    {
        return gr[i][j];
    }
    if (dp[i][j] != (int)1e9)
    {
        return dp[i][j];
    }
    int ans = OO;
    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (isValidPos(nx, ny))
        {

            int res = findShortestPath(nx, ny);
            if (res != OO)
                ans = min(ans, gr[i][j] + res);
        }
    }
    return dp[i][j] = ans;
}

void solve()
{
    for (int i = 0; i < n; ++i)
    {
        cin >> gr[i][0] >> gr[i][1] >> gr[i][2];
    }

    cout << findShortestPath(0, 1) << ln;
}

int main()
{
    fastIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> n;
    while (n != 0)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                dp[i][j] = 1e9;
            }
        }
        cout << t++ << ". ";
        solve();
        cin >> n;
    }
    return 0;
}