#include <iostream>
using namespace std;

int proc()
{
    int n;
    long long t = 0;

    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        int x;
        cin >> x;
        t += (long long)x;
    }

    if (t == n) return 0;
    else if (t < n) return 1;
    else return t - n;
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