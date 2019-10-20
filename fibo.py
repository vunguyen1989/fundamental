# recursion
def fib(n):
    if n <= 1:
        return n
    return fib(n -1) + fib(n - 2)

# 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

# dynamic programing
def fib(n):
    dp = [0] * (n + 1)
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]

x = fib(5)
print(x)