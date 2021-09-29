# my_solution_0.py

[<<](./README.md)

```py
def transpose(mat):
    y = len(mat)
    x = len(mat[0])
    mat_t=[]
    for j in range(x):
        mat_t.append([])
        for i in range(y):
            print(i,j)
            mat_t[j].append(mat[i][j])
    return mat_t


mat = [
    [1, 2, 3],
    [4, 5, 6],
]

print(transpose(mat))
```
