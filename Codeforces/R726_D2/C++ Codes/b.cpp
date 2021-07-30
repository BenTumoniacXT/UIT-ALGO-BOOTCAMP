#include <iostream>
using namespace std;

typedef pair <int, int> duo;

long long direct_range(duo px, duo p)
{
    return (long long)abs(px.first - p.first) + (long long)abs(px.second - p.second);
}

void proc()
{
    duo sz, pp;
    cin >> sz.first >> sz.second >> pp.first >> pp.second;

    duo b1 = duo(1, 1), b2 = duo(1, 1);
    if (direct_range(b1, pp) < direct_range(duo(sz.first, 1), pp)) b1 = duo(sz.first, 1);
    if (direct_range(b1, pp) < direct_range(duo(sz.first, sz.second), pp)) b1 = duo(sz.first, sz.second);
    if (direct_range(b1, pp) < direct_range(duo(1, sz.second), pp)) b1 = duo(1, sz.second);
    
    if (direct_range(b1, b2) + direct_range(b2, pp) < direct_range(b1, duo(sz.first, 1)) + direct_range(duo(sz.first, 1), pp)) b2 = duo(sz.first, 1);
    if (direct_range(b1, b2) + direct_range(b2, pp) < direct_range(b1, duo(sz.first, sz.second)) + direct_range(duo(sz.first, sz.second), pp)) b2 = duo(sz.first, sz.second);
    if (direct_range(b1, b2) + direct_range(b2, pp) < direct_range(b1, duo(1, sz.second)) + direct_range(duo(1, sz.second), pp)) b2 = duo(1, sz.second);

    cout << b1.first << " " << b1.second << " " << b2.first << " " << b2.second << endl;
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