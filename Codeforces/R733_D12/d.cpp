#include <iostream>
#include <set>
#include <vector>
using namespace std;

void proc()
{
    int n;
    cin >> n;
    vector <set <int>> people(n + 1);
    for (int i = 0; i < n; i++) 
    {
        int x;
        cin >> x;
        people[x].insert(i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) proc();

    return 0;
}