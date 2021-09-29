# my_solution_1.py

```py
def rotate_list(nums, k):
    for i in range(k):
        for i in range(0, len(nums)-1):
            nums[i] = nums[(i+1) % len(nums)] ^ nums[i]
            nums[(i+1) % len(nums)] = nums[(i+1) % len(nums)] ^ nums[i]
            nums[i] = nums[(i+1) % len(nums)] ^ nums[i]
        # print(a)

a = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
print(a)
rotate_list(a, 3)
print(a)

```