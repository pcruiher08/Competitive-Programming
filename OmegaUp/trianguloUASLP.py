tri = []
a = int(input())
tri.append(a)

a = int(input())
tri.append(a)

a = int(input())
tri.append(a)

tri.sort(reverse = True)

print("SI" if (tri[0] < (tri[1] + tri[2])) else "NO")