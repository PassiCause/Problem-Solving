n = int(input())

cnt = 0
for i in range(n):
    a,b,c,d=map(int,input().split())
    if a>=1000 or b>=1600 or c>=1500 or 1<=d<=30:
        cnt += 1

print(cnt)