
dp = [0 for _ in range(255)]
dp[0] = 1

for i in range(0, 251):
	dp[i + 2] += dp[i] * 2
	dp[i + 1] += dp[i]


while True:
	try:
		N = int(input())
		print(dp[N])
	except EOFError:
		break