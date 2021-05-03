#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector <vector <long long>> mat, mat2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m;
    mat.resize(n);
    for (int i = 0; i < n; i++)
    {
        mat[i].resize(m);
        for (int j = 0; j < m; j++) cin >> mat[i][j];
    }

    mat2.resize(n);
    for (int i = 0; i < n; i++)
    {
        mat2[i].resize(m - 2);
        mat2[i][0] = mat[i][0] + mat[i][1] + mat[i][2];
        for (int j = 1; j < m - 2; j++) mat2[i][j] = mat2[i][j - 1] - mat[i][j - 1] + mat[i][j + 2];
    }

    long long mn = LLONG_MAX;
    for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < m - 2; j++) mn = min(mat2[i][j] + mat2[i + 1][j] + mat2[i + 2][j], mn);

    cout << mn;

    return 0;
}