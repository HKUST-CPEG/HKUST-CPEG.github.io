#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s;
int ltr[255], rtl[255], ans[255];
int main()
{
    cin >> s;
    int len = s.length(), val = 0;
    //cout<<len;
    for (int i = 0; i < len; i++)
    {
        val = val - 1;
        if (s[i] == '.')
            ltr[i] = max(0, val);
        if (s[i] == 'R')
        {
            val = len;
            ltr[i] = val;
        }
        if (s[i] == 'L')
        {
            val = 0;
            ltr[i] = val;
        }
    }
    val = 0;
    for (int i = len; i > 0; i--)
    {
        val = val + 1;
        if (s[i] == '.')
            rtl[i] = min(0, val);
        if (s[i] == 'L')
        {
            val = -len;
            rtl[i] = val;
        }
        if (s[i] == 'R')
        {
            val = 0;
            rtl[i] = val;
        }
    }

    for (int i = 0; i < len; i++)
        ans[i] = ltr[i] + rtl[i];
    for (int i = 0; i < len; i++)
    {
        if (ans[i] == 0)
            cout << '.';
        if (ans[i] > 0)
            cout << 'R';
        if (ans[i] < 0)
            cout << 'L';
    }
    return 0;
}