#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long proc()
{
    int n;
    cin >> n;
    vector <long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (n < 3) return 0;

    sort(a.begin(), a.end());
    long long temp = 0, t2 = 0, t = 0;
    for (int i = 2; i < n; i++)
    {
        temp += a[i - 1];
        t2 += temp;
        t += (a[i] * i - 1) - t2; 
    }

    return (-1)*t;
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