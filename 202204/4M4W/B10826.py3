n = int(input())
a1, a2 = 0, 1
for _ in range(n):
	t = a1 + a2
	a1 = a2
	a2 = t
print(a1)
