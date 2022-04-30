def solve(n):
    sum = 0
    while n != 0:
        sum += n % 10
        n //= 10
    if sum < 10:
        return sum
    return solve(sum)


if __name__ == '__main__':
    n, k = input().split()
    n = int(n)
    k = int(k)
    sum = 0
    while n != 0:
        sum += (n % 10) * k
        n //= 10
    print(solve(sum))
