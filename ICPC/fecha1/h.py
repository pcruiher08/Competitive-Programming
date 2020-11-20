maxes = []

def getMax(values, index):
	if index >= len(values):
		return 0
	maxVal = -1
	for i in range(index, len(values)):
		if maxes[i] == 0:
			maxVal = max(maxVal, values[i] + getMax(values, i + 2))
		else:
			maxVal = max(maxVal, maxes[i])
	maxes[index] = maxVal
	return maxVal

cases = int(input())
for i in range(cases):
	houses = int(input())
	values = [*map(int, input().split())]
	maxes = []
	for j in range(houses):
		maxes.append(0)
	print(getMax(values, 0))