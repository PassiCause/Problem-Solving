p,m,c=map(int,input().split())
x=int(input())
ans = 1000000000

for i in range(1,p+1):
    for j in range(1,m+1):
        for k in range(1,c+1):
            ans = min(ans, abs(x-(i+j)*(j+k)))

print(ans)