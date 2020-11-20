values = [*map(int, input().split())]
strs = ["hole in one", "condor", "albatross", "eagle", "birdie", "par", "bogey", "double bogey", "triple bogey"]
score = 0
for i in range(len(values)):
	stat = input()
	index = strs.index(stat)
	if index == 0:
		score += 1
	else:
		score += values[i] - 5 + index
print(score)
