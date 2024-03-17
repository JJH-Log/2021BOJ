
X = int(input())
lo = 0
hi = int((2**63)**0.5)+1
res = 0
while lo <= hi:
	mid = (lo + hi) // 2
	if mid**2 >= X:
		res = mid
		hi = mid - 1
	else :
		lo = mid + 1
print(res)