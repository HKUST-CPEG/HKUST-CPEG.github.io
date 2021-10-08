#include <iostream>
#include <cstring>
using namespace std;

// __________________0__1___2___3___4___5___6___7___8___9___10__11__12__13__14__15__16__17__18__19__20__21
const int score[] = {0, 10, 10, 10, 10, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

enum ABC
{
    N,
    A,
    B,
    C,
};

struct MAP
{
    int size = 0;
    int score = 0;
    ABC *map;
    int match;
    int **matches;
}

void get_matches(MAP *map){
    
}

void
process(MAP *map, const int head, const int tail)
{
    int num = tail - head + 1;
    map.score += score[num];
    int size = map->size;
    for (int i = head; i <= tail; i++) // mark
    {
        map->map[i] = N;
        map->size--;
    }

    ABC *temp = new ABC[map.size];
    for (int i = 0, j = 0; i < size; i++) // shrink
    {
        if (map[i] != N)
        {
            temp[j] = map[i];
            j++;
        }
    }

    delete[] map->map; // refresh map
    map->map = temp;
}

int solve(MAP *map)
{
    if map.size
}

int main()
{
}
