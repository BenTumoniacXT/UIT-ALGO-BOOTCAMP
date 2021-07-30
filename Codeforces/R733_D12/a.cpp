#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        string s;
        cin >> s;
        int mx = 0;
        for (auto i: s)
            mx = max(mx, i - '0');

        cout << mx << "\n";
    }

    return 0;
}