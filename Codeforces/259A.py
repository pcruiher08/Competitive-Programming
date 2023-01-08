flag = True
for _ in range(8):
    check = input()
    if(check != "WBWBWBWB" and check != "BWBWBWBW"):
        flag = False

print("YES" if flag else "NO")