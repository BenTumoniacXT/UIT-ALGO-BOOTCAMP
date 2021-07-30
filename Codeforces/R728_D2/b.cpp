#include <iostream>
#include <vector>
using namespace std;

long long proc()
{
    int n;
    cin >> n;
    vector <long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long c = 0;
    for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
        if (i + j + 2 == a[i] * a[j]) c++;

    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;
    while (t--) cout << proc() << endl;

    return 0;
}