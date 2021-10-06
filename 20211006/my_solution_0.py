def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n*factorial(n-1)  # n!


def c(a, b):
    if a >= b:
        return factorial(a)/(factorial(b)*factorial(a-b))  # a choose b
    else:
        return -1


def num_ways(n, m):
    return c(m+n, n)


print("please input m and n: ")
m = int(input("m = "))
n = int(input("n = "))

print("number of ways: ",int(num_ways(m, n)))
