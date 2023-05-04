r = 256
m = 15

def charAt(a,d):
    if d < len(a):
        return ord(a[d])
    else:
        return -1

def MSD_start(a):
    n = len(a)
    aux = [0 for i in range(n)]
    MSD_sort(a,aux,0,n-1,0)
    return a

def MSD_sort(a,aux,lo,hi,d):
    if hi <= lo:
        return
    count = [0 for i in range(r+2)]

    for i in range(lo,hi+1):
        count[charAt(a[i],d)+2] += 1
    for j in range(0,r+1):
        count[j+1] += count[j]
    for i in range(lo,hi+1):
        aux[count[charAt(a[i],d)+1]] = a[i]
        count[charAt(a[i],d)+1] +=1
    for i in range(lo,hi+1):
        a[i] = aux[i-lo]
    for j in range(0,r):
        MSD_sort(a,aux,lo + count[j], lo + count[j+1] - 1,d+1)

def operation(nome_ent, nome_sai):
    arq_ent = open(nome_ent,'r')
    a = arq_ent.read().split()
    arq_ent.close()
    i = 0
    while i < len(a):
        if len(a[i]) < 4:
            del a[i]
            i -= 1
        i = i + 1
    k = MSD_start(a)
    count = 1
    arq_sai = open(nome_sai,'w')
    for j in range (len(k)-1):
        if k[j] == k[j+1]:
            count += 1
        else:
            arq_sai.write('{}\t{}\n'.format(k[j],count))
            count = 1
    arq_sai.close()

