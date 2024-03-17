import sys
sys.setrecursionlimit(1050000)

dp = [0 for _ in range(101)]
dp[1] = 1
for i in range(2, 101):
	dp[i] = dp[i - 1] * 2 + 1


def move(t, a, b):
	if t == 1:
		print(a, end = ' ')
		print(b)
	else:
		left = 6 - a - b
		move(t - 1, a, left)
		move(1, a, b)
		move(t - 1, left, b)


N = int(input())
if N > 20:
	print(dp[N])
else:
	print(dp[N])
	move(N, 1, 3)
