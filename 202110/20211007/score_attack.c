#include <stdio.h>
#include <stdlib.h>
/*
 * Name: Neville LIN, Qiaoguan
 * ITSC: qlinak@connect.ust.hk
*/

const int MAX_TYPES = 26;
const double bonus[31] = {1.0, 1.0, 1.0, 1.0, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0,
                          2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0,
                          3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0};

//eliminate the substing stating by index "start" and "end" inclusive
//and return the score of current elimination
double eliminate(char str[], int length, int start, int end)
{
    if (start == end)
    {
        for (int i = start; i < length; i++)
        {
            str[i] = str[i + 1];
        }
        return 1;
    }
    double score = end - start + 1;
    score = score * ((score > 30) ? 4.0 : bonus[(int)score - 1]);
    int boundary = (start == 0) ? -1 : start - 1;
    while (end > boundary)
    {
        for (int i = start; i < length; i++)
        {
            str[i] = str[i + 1];
        }
        length -= 1;
        end -= 1;
    }
    return score;
}

//find the last appearance of the current character
//if found, return the index
//otherwise return the current index
int find(char str[], int length, int index)
{
    int output = index;
    char sample = str[index];
    for (int i = index; i < length; i++)
    {
        if (str[i] == sample)
        {
            output = i;
        }
    }
    return output;
}

//return the maximum length of linking of the current character
int longest_linking_from_cur_index(char str[], int length, int index)
{
    int max_lgth = 1;
    for (int i = index + 1; i < length; i++)
    {
        if (str[i] == str[index])
        {
            max_lgth++;
        }
        else if (str[i] != str[index])
            break;
    }
    return max_lgth;
}

int main()
{
    //---------------input your test case here-----------------
    char str[] = "AABCCABAAACCCCAAABBA";
    //---------------main flow of the program------------------
    printf("test case: \"%s\"\n", str);
    int length = sizeof(str) / sizeof(char) - 1;
    double score = 0;

    while (str[0] != '\0')
    {
        //for each character, if it has linking length greater than two, skip the whole linking
        //otherwise find if it appears again in later index of the string
        //if not, eliminate it
        //and every time after elimination set i = 0 to repeat the above process
        for (int i = 0; i < length; i++)
        {
            int max_length = longest_linking_from_cur_index(str, length, i);
            if (max_length > 2)
            {
                i += max_length - 1;
                continue;
            }
            int last_appearance_index = find(str, length, i);
            int diff_index = last_appearance_index - i;
            if (diff_index <= 1 && max_length <= 2 && str[i] != '\0' && str[last_appearance_index] != '\0')
            {
                score += eliminate(str, length, i, last_appearance_index);
                printf("After elimination: \"%s\"\nTotal scores: %.2f\n", str, score);
                i = 0;
            }
        }

        //for the whole string, find and eliminate the longest linking substring
        //repeat all processes above until the string is empty
        int max_substr_lgth = 1;
        int max_substr_start = 0, max_substr_end = 0;
        for (int i = 0; i < length; i++)
        {
            int cur_substr_lgth = 1, cur_substr_start = i, cur_substr_end = 0;
            for (int j = i + 1; j < length; j++)
            {
                if (str[j] != str[i] || str[j] == '\0')
                    break;
                cur_substr_lgth += 1;
                cur_substr_end = j;
            }
            if (cur_substr_lgth > max_substr_lgth)
            {
                max_substr_lgth = cur_substr_lgth;
                max_substr_start = cur_substr_start;
                max_substr_end = cur_substr_end;
            }
        }
        score += eliminate(str, length, max_substr_start, max_substr_end);
        printf("After elimination: \"%s\"\nTotal scores: %.2f\n", str, score);
    }
    return 0;
}