
def consecNums(s):
    for i in range(0,len(s)-1):
        if (s[i].isnumeric() and s[i+1].isnumeric()):
            if abs(int(s[i])-int(s[i+1]))==1:
                #print(s[i],s[i+1])
                return False
    return True


def process(s, asser):
    rule1 = False
    rule2 = False
    rule3 = False
    rule4 = False
    rule5 = False
    mayus = 0
    minus = 0
    nums  = 0
    specials = 0
    largo = len(s)

    for i in range(largo):
        if(s[i].isupper()):
            mayus+=1
        if(s[i].islower()):
            minus+=1
        if(s[i].isnumeric()):
            nums+=1
        if(s[i]=='.' or s[i]=='#' or s[i]=='$' or s[i]=='%' or s[i]=='/' or s[i]=='(' or s[i] =='&' or s[i] ==')'):
            specials+=1
        
    rule1 = minus >= 1
    rule2 = mayus >= 1
    rule3 = consecNums(s) and nums >= 1
    rule4 = specials >= 1
    rule5 = largo >= 10

    suma = rule1 + rule2 + rule3 + rule4 + rule5
    print("Assertion number #",end='')
    print(asser,end='')
    print(": ",end='')
    if(suma == 5):
        #strong
        print("Strong")
    elif(suma == 4):
        #good
        print("Good")
    elif(suma == 3):
        #weak
        print("Weak")
    else:
        #rejected
        print("Rejected")

n = int(input())

for k in range(n):
    process(input(),k+1)