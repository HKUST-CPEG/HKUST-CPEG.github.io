# rotate_array.cpp

```cpp

#include <iostream>
using namespace std;

void print_arr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start += 1;
        end -= 1;
    }
}

void rotate_array(int arr[], int k, int length)
{
    reverse(arr, 0, k - 1);
    reverse(arr, k, length - 1);
    reverse(arr, 0, length - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    rotate_array(arr, 2, length);
    print_arr(arr, length);
    return 0;
}
```