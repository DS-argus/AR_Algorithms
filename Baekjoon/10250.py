T = int(input())

for i in range(T):
    H, W, N = map(int, input().split())


    if N % H == 0:
        front = str(H)
    else:
        front = str(N % H)    
    

    if N % H == 0:
        back = str(N // H)
    else:
        back = str(N // H + 1) 

    if len(back) == 1:
        back = "0"+back
    
    print(front+back)