t = int(input())
while(t):
    c=0
    n=int(input())
    a = input()
    if n<=2:
        print(a)
    else:
        for i in a:
            if i == '0':
                c+=1
        l = [0]*c
        m = [1]*(n-c)
        print(*l,*m , sep = "")
    t-=1
