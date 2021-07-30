#include <iostream>
#include <vector>
using namespace std;

long long proc()
{
    int n;
    cin >> n;
    long long r = 0;
    vector <long long> a(n);
    for (auto &i: a) cin >> i;
    for (int i = 0; i < n - 1; i++)
    {
        long long vl0 = max(a[i], a[i + 1]), vl1 = min(a[i], a[i + 1]);
        r = max(r, vl0 * vl1);
    }

    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) cout << proc() << "\n";

    return 0;
}