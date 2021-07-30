#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    long long n, k, x;
    cin >> n >> k >> x;

    vector <long long> a(n);
    int c = 0, d = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int j = 0;
        vector <long long> spc;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i + 1] - a[i] <= x) continue;
            else 
            {
                long long sx = (a[i + 1] - a[i]) / x;
                if ((a[i + 1] - a[i]) % x == 0) sx--;
                spc.push_back(sx);
            }
        }

        if (spc.empty()) {}
        else
        {
            sort(spc.begin(), spc.end());
            while (k >= spc[j] && j < spc.size())
            {
                k -= spc[j];
                j++;
            }

            j = spc.size() - j;
        }

    cout << j + 1;
    return 0;
}