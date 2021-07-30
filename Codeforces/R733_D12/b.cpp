#include <iostream>
#include <vector>
using namespace std;

void proc(int n, int m)
{
    vector <vector <int>> mp(n + 2);
    for (int i = 0; i <= n + 1; i++) mp[i].resize(m + 2, 0);

    for (int j = 1; j <= m; j++)
    {
        if (mp[1][j - 1] == 0 && mp[1][j + 1] == 0 && mp[2][j - 1] == 0 && mp[2][j] == 0 && mp[2][j + 1] == 0 && mp[1][j] == 0) 
        {
            mp[1][j] = 1;

            /*
            mp[1][j - 1] = 2;
            mp[1][j + 1] = 2; 
            mp[0][j - 1] = 2; 
            mp[0][j] = 2; 
            mp[0][j + 1] = 2; 
            mp[2][j - 1] = 2; 
            mp[2][j] = 2; 
            mp[2][j + 1] = 2;
            */
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (mp[i][1] == 0 && mp[i - 1][1] == 0 && mp[i + 1][1] == 0 && mp[i][2] == 0 && mp[i - 1][2] == 0 && mp[i + 1][2] == 0) mp[i][1] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (mp[i][m] == 0 && mp[i - 1][m] == 0 && mp[i + 1][m] == 0 && mp[i][m - 1] == 0 && mp[i - 1][m - 1] == 0 && mp[i + 1][m - 1] == 0) mp[i][m] = 1;
    }

    for (int j = 1; j <= m; j++)
    {
        if (mp[n][j - 1] == 0 && mp[n][j + 1] == 0 && mp[n - 1][j - 1] == 0 && mp[n - 1][j] == 0 && mp[n - 1][j + 1] == 0 && mp[n][j] == 0) 
        {
            mp[n][j] = 1;

            /*
            mp[1][j - 1] = 2;
            mp[1][j + 1] = 2; 
            mp[0][j - 1] = 2; 
            mp[0][j] = 2; 
            mp[0][j + 1] = 2; 
            mp[2][j - 1] = 2; 
            mp[2][j] = 2; 
            mp[2][j + 1] = 2;
            */
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout << mp[i][j];
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        proc(x, y);
    }

    return 0;
}