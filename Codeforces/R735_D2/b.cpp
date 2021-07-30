#include <iostream>
#include <vector>
using namespace std;

long long proc()
{
    int nt, k;
    cin >> nt >> k;
    long long r = LLONG_MIN;
    vector <long long> a(nt + 1);
    for (int i = 1; i <= nt; i++) cin >> a[i];

    for (int i = max(1, nt - (2 * k)); i < nt; i++)
    for (int j = i + 1; j <= nt; j++)
        r = max(r, 1LL * i * j - k * (a[i] | a[j]));

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