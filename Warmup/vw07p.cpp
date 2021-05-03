#include <iostream>
#include <vector>
using namespace std;

const int high = 1e7;

int n, m;
vector <int> tm, vtm;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    cin >> n >> m;
    tm.resize(n);
    vtm.resize(m + 1, high);

    cin >> tm[0];
    for (int i = 1; i < n; i++) 
    {
        cin >> tm[i];
        tm[i] += tm[i - 1];
    }

    vtm[m] = 0;
    for(int i = n; i >= 1; i--)
    {
		for(int j = m; j >= 0; j--)
        {
			if (vtm[j] == 1e9 || j - tm[i - 1] < 0) continue;
			vtm[j - tm[i - 1]] = min(vtm[j - tm[i - 1]], vtm[j] + i + 1);
		}
	}

    int overtime = tm[n - 1] - tm[n - 2];

    for(int j = m; j >= 0; j--)
    {
		if(vtm[j] == 1e9) continue; 
		if(j - tm[n - 1] >= 0 && (j - tm[n - 1]) % overtime == 0)
			vtm[0] = min(vtm[0], vtm[j] + n + 1 + (j - tm[n - 1]) / overtime);
	}

    if (vtm[0] == high) cout << "-1"; else cout << vtm[0] - 1;

    return 0;
}