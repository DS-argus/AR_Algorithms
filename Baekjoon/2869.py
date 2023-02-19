a, b, v = map(int, input().split())

count = 1 + (v-a)/(a-b)

if count == int(count):
    day = count
else:
    day = int(count) + 1

print(int(day))


# round는 짝수 홀수일 때 0.5 결과가 달라짐
# 내림은 int로 