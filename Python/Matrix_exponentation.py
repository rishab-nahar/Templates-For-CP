N=10**9 + 7
def fun(a,b,c):
    return (a + b*c)%N


class M:
    def __init__(self,mat,mul,ide):
        self.mat=mat
        self.mul=mul
        self.ide=ide


    def power(self,n):
        ans=self.ide
        k=n
        x=self.mat
        while(k):
            if k%2:
                ans=self.mul(x,ans)
            x=(self.mul(x,x))
            k//=2
        return ans

def matmult(ar1,ar2):
    m=len(ar1)
    b=[[0 for i in range(m)] for j in range(m)]
    for i in range(m):
        for j in range(m):
            for k in range(m):
                b[i][j] = fun(b[i][j],ar1[i][k] , ar2[k][j])
    return b

def make_identity(n):
    identity=[[0]*n for _ in range(n)]
    for i in range(n):
        identity[i][i]=1
    return identity

n=int(input())
ide=make_identity(2)
mat=[[0,1],[1,1]]
matrix=M(mat,matmult,ide)
k=matrix.power(n)
print(k[1][0])