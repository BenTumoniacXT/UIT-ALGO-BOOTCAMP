#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair <int, int> duo;
const long long mod = (long long)1e9 + 7;

long long process()
{
    int n;
    cin >> n;
    vector <duo> a(n);
    unordered_map <int, int> mp;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i].first;
        mp[a[i].first] = i;
    }
    for (int i = 0; i < n; i++) cin >> a[i].second;

    unordered_map <int, bool> mpm;
    long long count = 0;
    for (int i = 0; i < n; i++) mpm[a[i].first] = 0;
    for (int i = 0; i < n; i++)
        if (!mpm[a[i].first])
        {
            if (a[i].first == a[i].second)
            {
                mpm[a[i].first] = 1;
                continue;
            }

            int z = a[i].second;
            do
            {
                mpm[z] = 1;
                z = a[mp[z]].second;
            } while (z != a[i].first);
            count++;
        }

    
    return ((long long)1 << count) % mod;
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