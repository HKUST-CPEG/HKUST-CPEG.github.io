#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[256];
void rev(int *x, int i, int j)
{
    while (i < j)
    {
        swap(x[i], x[j]);
        i++;
        j--;
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    k = k % n;
    rev(a, 0, n - 1);
    rev(a, 0, k);
    rev(a, k + 1, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}