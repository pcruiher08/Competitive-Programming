def booleanDeque(n, operations):
    if n == 0:
        return ""
    ans = 0
    for op in operations:
   
        if (op=="L"):
          
            k = n
            while (k > 0):
                curr = (ans >> (k - 1) & 1)
                if (curr == 1) :
                    k-=1
                else:
                    ans = ans | ((k - 1) << 1)
                break
            
        else:
            digit = int(op[1::])
            ans = ans & (~(n - digit - 1))
            
    return bin(ans)[2::]

print(booleanDeque(10,["L", "L", "C0", "L", "C3"])[2::])
