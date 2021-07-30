#include <iostream>
#include <vector>
using namespace std;

typedef pair <int, int> duo;

void proc()
{
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    long long t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        t1 += a[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cin >> b[i];
        t2 += b[i];
    }
    
    if (t1 != t2) 
    {
        cout << "-1\n";
        return;
    }

    vector <duo> step;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i]) continue;

        int j = i;
        REDO:
        j++;
        while (j < n && a[j] == b[j] && a[j] != 0) j++;
        if (j == n) continue;

        bool sw = 0;
        if (b[i] > a[i]) sw = 1; 
        do
        {
            if (!sw && b[j] > 0)
            {
                b[i]++;
                b[j]--;
                step.push_back(duo(i + 1, j + 1));
            } else if (sw && b[i] > 0)
            {
                b[j]++;
                b[i]--;
                step.push_back(duo(j + 1, i + 1));
            }
            
        } while (a[i] != b[i] && b[i] > 0 && b[j] > 0);

        if (a[i] != b[i]) goto REDO;
    }

    cout << step.size() << "\n";
    for (auto i: step) cout << i.first << " " << i.second << "\n";
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