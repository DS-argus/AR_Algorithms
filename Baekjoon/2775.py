"""
recursion 쓰면 시간초과
이게 DP인가?
"""
T = int(input())

for _ in range(T):
    a = int(input())
    b = int(input())

    apt = []

    for j in range(a+1):
        if j == 0:
            floor = [[i+1 for i in range(b)]]
        else:
            floor = [[sum(apt[0][:i+1]) for i in range(b)]]

        apt = floor + apt

    print(apt[0][-1])

