# my_solution_debug.cpp

```cpp

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int LEFT = -1, RIGHT = 1, STAND = 0, MAX = 20000;
char dominos[MAX] = {};

void generate(const int, const int, char[]);
void process(char[], const int, const int, const int);
void user_interaction(int &, int &);
void user_interaction(char dominos[MAX], const int);

void solve(char dominos[MAX], const int len)
{
    int head = 0, tail = 0;
    cout << "        ";
    while (tail < len)
    {
        if (dominos[head] == 'R' && dominos[tail] == 'R') // ··· R...R ··· => ··· RRRRR ···
        {
            cout << "1";
            process(dominos, head, tail, RIGHT);
        }
        else if (dominos[head] == 'L' && dominos[tail] == 'L') // ··· L...L ··· => ··· LLLL ···
        {
            cout << "2";
            process(dominos, head, tail, LEFT);
        }
        else if (dominos[head] == 'L' && dominos[tail] == 'R') // ··· L...R ··· => ··· L...R ···
        {
            cout << "3";
            process(dominos, head, tail, STAND);
        }
        else if (dominos[head] == 'R' && dominos[tail] == 'L') // ··· R...L ··· => ··· RR?LL ···
        {

            int distance = tail - head;
            if (distance % 2) // ··· R....L ··· => ··· RRRLLL ···
            {
                cout << "4";
                process(dominos, head, head + (distance - 1) / 2, RIGHT);
                process(dominos, head + (distance - 1) / 2 + 1, tail, LEFT);
            }
            else // ··· R...L ··· => ··· RR.LL ···
            {
                cout << "5";
                process(dominos, head, head + distance / 2 - 1, RIGHT);
                process(dominos, head + distance / 2 + 1, tail, LEFT);
            }
        }
        else if (head == 0 && dominos[tail] == 'L') // ...L ··· => LLLL ···
        {
            cout << "6";
            process(dominos, head, tail, LEFT);
        }
        else if (head == 0 && dominos[tail] == 'R') // ...R ··· => ...R ···
        {
            cout << "7";
            process(dominos, head, tail, STAND);
        }
        else if (dominos[head] == 'L' && tail == len - 1) // ··· L... => ··· L...
        {
            cout << "8";
            process(dominos, head, tail, STAND);
            return;
        }
        else if (dominos[head] == 'R' && tail == len - 1) // ··· R... => ··· RRRR
        {
            cout << "9";
            process(dominos, head, tail, RIGHT);
            return;
        }
        else
        {
            cout << "0";
            tail++;
            continue;
        }
        head = tail;
        tail++;
    }
}

int main()
{
    int len, density;
    while (true)
    {
        user_interaction(len, density);
        generate(len, density, dominos);
        user_interaction(dominos, len);
        solve(dominos, len);
        cout << endl
             << "OUTPUT: ";
        user_interaction(dominos, len);
    }
}

void process(char dominos[MAX], const int head, const int tail, const int direction) // process the dominos
{
    if (direction == LEFT)
    {
        for (int i = head; i <= tail; i++)
        {
            dominos[i] = 'L';
        }
    }
    else if (direction == RIGHT)
    {
        for (int i = head; i <= tail; i++)
        {
            dominos[i] = 'R';
        }
    }
    else if (direction == STAND)
    {
        for (int i = head; i <= tail; i++)
        {
            // Do nothing
        }
    }
}

void user_interaction(int &len, int &density)
{
    do
    {
        cout << endl
             << "Enter the length of the domino list, and the density of \'L\' and \'R'\' (int 0 ~ 10)." << endl;
        cin >> len >> density;
    } while (len <= 0 || density < 0 || density > 10);
}

void user_interaction(char dominos[MAX], const int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << dominos[i];
    }
    cout << endl;
}

void generate(const int len, const int density, char dominos[MAX]) // generate a random domino list
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < len; i++)
    {
        if ((rand() % 10) < density)
        {
            if (rand() % 2)
            {
                dominos[i] = 'L';
            }
            else
            {
                dominos[i] = 'R';
            }
        }
        else
        {
            dominos[i] = '.';
        }
    }
    cout << endl
         << "INPUT:  ";
}
```