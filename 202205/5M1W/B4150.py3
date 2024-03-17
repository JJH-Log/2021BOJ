
a = 1
b = 1
N = int(input())
for i in range(N - 1):
	t = b
	b = a + b
	a = t
print(a)