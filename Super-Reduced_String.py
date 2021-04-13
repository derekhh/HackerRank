def super_reduced_string(s):
    m=list(s)
    c=0
    while c<len(m)-1 :
        if m[c]==m[c+1]:
            del m[c]
            del m[c]
            if c!=0:
                c=c-1
        else: 
            c=c+1
    if len(m)==0:
        return 'Empty String'
    else:
        return ''.join(map(str,m))    

s = raw_input().strip()
result = super_reduced_string(s)
print(result)
