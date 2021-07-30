#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    vector <long long> as(s.size() + 1, 0);
    for (int i = 1; i <= s.size(); i++)
    {
        as[i] = as[i - 1] + ((int)s[i - 1] - 96);
    }

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << as[y] - as[x - 1] << endl;
    }

    return 0;
}