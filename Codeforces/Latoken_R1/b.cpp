#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long no_neg(long long x)
{
    if (x < 0) return 0;
    else return x;
}

long long process()
{
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    a.push_back(0);

    vector <int> az(n + 1);
    az[0] = a[1];
    long long t = a[1];
    for (int i = 1; i <= n; i++)
    {
        az[i] = abs(a[i] - a[i + 1]);
        t += (long long)az[i];
    }
    az.push_back(0);

    for (int i = 1; i <= n; i++)
    {
        if (no_neg(a[i] - max(a[i - 1], a[i + 1])) > 0)
            t -= (long long)(a[i] - max(a[i - 1], a[i + 1]));
    }

    return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) cout << process() << endl;

    return 0;
}