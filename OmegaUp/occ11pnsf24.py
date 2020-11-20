numbers = list(map(int, input().split()))
calc = numbers[0] - numbers[1]
for i in range(len(numbers)-1):
  calc = max(calc, numbers[i] - numbers[i+1])
print(calc)