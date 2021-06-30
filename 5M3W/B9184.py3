dp=[[[0]*21 for _ in range(21)]for _ in range(21)]

for i in range(0,21):
    for j in range(0,21):
        for k in range(0,21):
            if i == 0 or j == 0 or k == 0:
                dp[i][j][k] = 1
            elif((i < j) and (j < k)):
                dp[i][j][k]=dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k]
            else:
                dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k]+dp[i-1][j][k-1]-dp[i-1][j-1][k-1]
         
while True:
    A=list(map(int,input().split()))
    a,b,c=A[0],A[1],A[2]
    if a==-1 and b==-1 and c==-1: break
    if a<=0 or b<=0 or c<=0: a,b,c=0,0,0
    elif a>20 or b>20 or c>20: a,b,c=20,20,20
    print("w(%d, %d, %d) = %d" %(A[0],A[1],A[2],dp[a][b][c]))