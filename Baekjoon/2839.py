"""
N = 3 : 1 + 0
N = 4 : -1
N = 5 : -1
N = 6 : 2 + 0
N = 7 : -1
N = 8 : 1 + 1

N = a*3 + b*5
a, b >= 0
"""
N = int(input())

num_3 = N // 3 
result = []
while num_3 >= 0:
    if (N - num_3 * 3) % 5 == 0:
        result.append([num_3, (N - num_3 * 3) // 5])
    num_3 = num_3 - 1
    
if len(result) == 0:
    print(-1)

else:
    min = result[0][0] + result[0][1]

    for i in result:
        if i[0] + i[1] < min:
            min = i[0] + i[1]
    
    print(min)
 



    






