
def ff(left, right):
	while True:
		mid = (left + right) // 2
		if (mid ** 2) == N:
			return mid
		elif mid ** 2 > N:
			right = mid - 1
		else:
			left = mid + 1

N = int(input())
print(ff(1, N))
