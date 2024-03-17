
v = [-1 for _ in range(36)]
v[0] = 1

def t(x):
	if v[x] != -1:
		return v[x]
	else:
		ans = 0
		for i in range(x):
			ans += t(i) * t(x - 1 - i)
		v[x] = ans
		return v[x]

N = int(input())
print(t(N))