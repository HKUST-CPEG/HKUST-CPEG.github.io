#include <iostream>
using namespace std;

void solve(const int m, const int n)
{
    if (m <= 0 || n <= 0)
    {
        return;
    }

    int map[m][n] = {}; // initialize

    for (int i = 0; i < m; i++)
    {
        map[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        map[0][i] = 1;
    }

    for (int i = 1; i < m; i++) // refer to map[m-1][n-1]
    {
        for (int j = 1; j < n; j++)
        {
            map[i][j] = map[i - 1][j] + map[i][j - 1];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl
         << "number of ways: " << map[m - 1][n - 1] << endl;
}

int main()
{
    int m, n;
    cout << "Please input m n: " << endl;
    cin >> m >> n;
    solve(m, n);
}