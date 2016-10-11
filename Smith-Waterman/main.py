s1 = "ATGCAGCTGCTT"
s2 = "CGTATAGCTACTG"

m = len(s1)+1
n = len(s2)+1

# m*n
M = [([0] * (m)) for i in range(n)]

def output():
	for i in xrange(0,n):
		for j in xrange(0,m):
			print(M[i][j]),
		print("\n")

for i in xrange(1,n):
	for j in xrange(1,m):
		x1 = M[i][j-1] - 2
		x2 = M[i-1][j] - 2
		if s1[j-1] == s2[i-1]:
			x3 = M[i-1][j-1]+4
		else:
			x3 = M[i-1][j-1]-2
		M[i][j] = max(0,x1,x2,x3)

output()


