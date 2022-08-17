
def solve(a,b):
    if len(a) != len(b):
        return False
    
    if(a.count("0") == len(a) or b.count("0") == len(b)):
        if a.count("0") == len(a) and b.count("0") == len(b):
            return True
        else:
            return False
    return True


a = input()
b = input()


print("YES") if solve(a, b) else print("NO")