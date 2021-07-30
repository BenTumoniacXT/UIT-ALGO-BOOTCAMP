#include <iostream>
using namespace std;

void proc()
{
    int x;
    cin >> x;

    if (x % 2 == 0)
    {
        for (int i = 0; i < x; i += 2) cout << i + 2 << " " << i + 1 << " ";
        cout << endl;
    } else
    {
        for (int i = 0; i < x - 3; i += 2) cout << i + 2 << " " << i + 1 << " ";
        cout << x << " " << x - 2 << " " << x - 1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;
    while (t--) proc();

    return 0;
}