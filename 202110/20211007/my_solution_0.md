# my_solution_0.cpp

[<<](./README.md)

>写的很不好，大哥见谅，看的人多的话我就再出个完整思路和优化算法  
>[可执行文件(exe)](./my_solution_0.exe)

```cpp
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// // __________________0__1___2___3___4___5___6___7___8___9___10__11__12__13__14__15__16__17__18__19__20__21
// const int score[] = {0, 10, 10, 10, 10, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

class Char
{
public:
    enum class ABC
    {
        A,
        B,
        C,
    };

private:
    int num;  // number of this char
    ABC type; // what char it is

public:
    Char(const Char *chr)
    {
        num = chr->getNum();
        type = chr->getType();
    }
    Char(const char &inchar)
    {
        if (inchar == 'A' || inchar == 'a')
        {
            type = ABC::A;
        }
        else if (inchar == 'B' || inchar == 'b')
        {
            type = ABC::B;
        }
        else if (inchar == 'C' || inchar == 'c')
        {
            type = ABC::C;
        }
        num = -1; // num is not set
    }
    void setNum(int innum) { num = innum; }

    int getNum() const { return num; }
    ABC getType() const { return type; }

    char getChar() const
    {
        if (type == ABC::A)
            return 'A';
        else if (type == ABC::B)
            return 'B';
        return 'C';
    }

    int getScore()
    {
        if (num < 5)
        {
            return num * 10;
        }
        return num * (10 + num);
    }
};

class String
{
private:
    Char **list;            // the string
    int score;              // current score
    int len;                // current len
    const int depth;        // depth (current step)
    const String *ancestor; // ancestor

    void delChar(const int &del) // delete a group of character
    {
        score += list[del]->getScore(); // update score
        delete list[del];               // delete char
        list[del] = nullptr;
        updateList(); // update list
    }

    void updateList()
    {
        int dif = 0;
        for (int i = 0; i < len; i++)
        {
            if (list[i] == nullptr)
            {
                dif++;
            }
        }
        if (dif)
        {
            Char **new_list = new Char *[len - dif]; // update list
            for (int i = 0, j = 0; i < len; i++)
            {
                if (list[i] != nullptr)
                {
                    new_list[j++] = list[i];
                }
            }
            delete[] list;
            list = new_list;
            len -= dif;
        }
        mergeChar(); // merge same char if exist
    }

    void mergeChar()
    {
        bool merged = false;
        for (int i = 0; i < len - 1; i++) // merge same char
        {
            if (list[i]->getChar() == list[i + 1]->getChar())
            {
                list[i]->setNum(list[i]->getNum() + list[i + 1]->getNum());
                delete list[i + 1];
                list[i + 1] = nullptr;
                merged = true;
                break;
            }
        }
        if (merged)
        {
            updateList();
        }
    }

public:
    String(const String *str, const int &del) : score(str->getScore()), len(str->getLen()), depth(str->getDepth() + 1), ancestor(str)
    {
        /*deep copy the list*/
        Char **givenList = str->getList();
        list = new Char *[len];
        for (int i = 0; i < len; i++)
        {
            list[i] = new Char(givenList[i]);
        }

        delChar(del);
    }
    String(char *m) : score(0), depth(0), ancestor(nullptr)
    {
        /*get len of our list*/
        int iptlen = strlen(m); // the length of the input string
        m = strupr(m);
        char *val_m = new char[iptlen + 1]{};
        int vallen = 0;
        for (int i = 0; i < iptlen; i++)
        {
            if (m[i] == 'A' || m[i] == 'B' || m[i] == 'C')
            {
                val_m[vallen++] = m[i];
            }
        }

        len = 0;
        for (int i = 0; i < vallen - 1; i++)
        {
            if (val_m[i] != val_m[i + 1])
            {
                len++;
            }
        }
        len++;
        /*put chars into our list*/
        list = new Char *[len];
        list[0] = new Char(val_m[0]); // the first char
        int n = 0;
        for (int i = 0, j = 0; i < vallen; i++)
        {
            if (list[j]->getChar() == val_m[i])
            {
                n++;
            }
            else
            {
                list[j++]->setNum(n);
                list[j] = new Char(val_m[i]);

                n = 1;
            }
        }
        list[len - 1]->setNum(n); // the last one
        delete[] val_m;
    }
    ~String()
    {
        for (int i = 0; i < len; i++)
        {
            delete list[i];
        }
        delete[] list;
    }

    int getScore() const { return score; }
    int getDepth() const { return depth; }
    int getLen() const { return len; }
    Char **getList() const { return list; }
    const String *getAncestor() const { return ancestor; }

    void print() const
    {
        cout << "* current step: " << depth;
        cout << "  len: " << len;
        cout << "  score: " << score / 10 << "." << score % 10 << endl;
        for (int i = 0; i < len; i++)
        {
            int num = list[i]->getNum(); // how many char
            cerr << num;
            char chr = list[i]->getChar(); // what is this char
            for (int j = 0; j < num; j++)  // print this char
            {
                cout << chr;
            }
            cout << ' ';
        }
    }
};

void printResult(const String *s)
{
    if (s == nullptr)
    {
        return;
    }

    printResult(s->getAncestor());
    s->print();
    cout << endl;
}

int main()
{
    while (true)
    {
        char *input = new char[512];
        cout << "please input your string (A/B/C):" << endl;
        cin >> input;
        int res = 0;
        String *origin = new String(input);
        if (origin->getLen() > 11)
        {
            cout << "can not solve such a complicated problem :(" << endl
                 << endl
                 << endl;
            continue;
        }
        String **arr = new String *[int(pow(origin->getLen(), 7))];
        String **result = new String *[int(pow(origin->getLen(), 7))];
        String **highest = new String *[int(pow(origin->getLen(), 7))];
        arr[0] = origin;
        delete[] input;
        cout << endl
             << "input: " << endl;
        arr[0]->print();
        cout << endl;

        int arrLen = 1;
        for (int i = 0; i < arrLen; i++)
        {
            if (arr[i]->getLen() == 0)
            {
                result[res++] = arr[i];
            }
            else
            {
                for (int m = 0; m < arr[i]->getLen(); m++)
                {
                    arr[arrLen++] = new String(arr[i], m);
                }
            }
        }

        int highestNum = 0;
        int highest_score = -1;
        for (int i = 0; i < res; i++)
        {
            if (result[i]->getScore() > highest_score)
            {
                highest_score = result[i]->getScore();
                highestNum = 0;
                highest[highestNum++] = result[i];
            }
            else if (result[i]->getScore() == highest_score)
            {
                highest[highestNum++] = result[i];
            }
        }

        cout << endl
             << "There are " << highestNum << " solutions to get highest score" << endl;
        if (highestNum <= 50)
        {
            for (int i = 0; i < highestNum; i++)
            {
                printResult(highest[i]);
            }
        }
        else
        {
            for (int i = 0; i < 20; i++)
            {
                printResult(highest[i]);
            }
            cout << "......too many solutions!!!  only the first 20 are showed" << endl;
        }

        delete[] result;
        delete[] highest;
        for (int i = 0; i < arrLen; i++)
        {
            delete arr[i];
        }
        delete[] arr;

        cout << endl
             << "Totally " << highestNum << " solutions" << endl
             << endl;

        cout << "The program did not crash" << endl
             << endl
             << endl;
    }
}
```
