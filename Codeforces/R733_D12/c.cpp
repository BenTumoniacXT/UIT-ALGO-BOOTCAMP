#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int proc()
{
    int n, at = 0, bt = 0;
    cin >> n;
    priority_queue <int, vector <int>, greater <int>> apq, bpq;
    //vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) 
    {
        int x;
        cin >> x;
        at += x;
        apq.push(x);
    }
    for (int i = 0; i < n; i++) 
    {
        int x;
        cin >> x;
        bt += x;
        bpq.push(x);
    }

    int k = n - (n / 4);
    priority_queue <int, vector <int>, less <int>> bpq2;
    for (int i = 0; i < n - k; i++)
    {
        at -= apq.top();
        bt -= bpq.top();
        bpq2.push(bpq.top());
        apq.pop();
        bpq.pop();
    }

    /*while (!bpq2.empty())
    {
        bpq.push(bpq2.top());
        bpq2.pop();
    }*/

    if (at >= bt) return 0;
    else 
    {
        int c = 0;
        while (at < bt)
        {
            n++;
            c++;
            apq.push(100);
            at += 100;

            while (apq.size() > n - (n / 4)) 
            {
                at -= apq.top();
                apq.pop();
            }

            while (bpq.size() < n - (n / 4) && !bpq2.empty()) 
            {
                bpq.push(bpq2.top());
                bt += bpq2.top();
                bpq2.pop();
                
            }
        }

        return c;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cout << proc() << "\n";

    return 0;
}