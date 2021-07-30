#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool analyze(bool slate, vector <string> mcore)
{
    for (int i = 0; i < mcore.size(); i++)
    {
        slate = !slate;
        for (int j = 0; j < mcore[i].size(); j++)
            if (slate) //R First
            {
                if (j % 2 == 0 && mcore[i][j] == 'W') return 0;
                else if (j % 2 != 0 && mcore[i][j] == 'R') return 0;
            } 
            else //W First
            {
                if (j % 2 == 0 && mcore[i][j] == 'R') return 0;
                else if (j % 2 != 0 && mcore[i][j] == 'W') return 0;
            } 
    }

    return 1;
}

void process()
{
    int n, m;
    cin >> n >> m;
    vector <string> mat(n);
    for (int i = 0; i < n; i++) cin >> mat[i];

    if (analyze(0, mat))
    {
        cout << "YES" << endl;
        bool slate2 = 1;
        for (int i = 0; i < n; i++)
        {
            bool slate = !slate2;
            for (int j = 0; j < mat[i].size(); j++) 
            {
                slate = !slate;
                if (slate) cout << "R";
                else cout << "W";
            }
            cout << endl;
            slate2 = !slate2;
        }
    } else if (analyze(1, mat))
    {
        cout << "YES" << endl;
        bool slate2 = 0;
        for (int i = 0; i < n; i++)
        {
            bool slate = !slate2;
            for (int j = 0; j < mat[i].size(); j++) 
            {
                slate = !slate;
                if (slate) cout << "R";
                else cout << "W";
            }
            cout << endl;
            slate2 = !slate2;
        }
    } else cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) process();

    return 0;
}