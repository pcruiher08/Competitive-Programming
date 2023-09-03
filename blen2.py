import itertools

def count_turbulent_strings(length):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    combinations = itertools.product(alphabet, repeat=length)
    
    count = 0
    for combination in combinations:
        string = ''.join(combination)
        
        flowing = all(string[i] <= string[i+1] for i in range(length-1))
        receding = all(string[i] >= string[i+1] for i in range(length-1))
        if not flowing and not receding:

            count += 1
    
    return count

total = 0

for i in range(1, 6):
    turbulent_count = count_turbulent_strings(i)
    total += turbulent_count
    print("Number of turbulent strings of length", i, ":", turbulent_count)


print(total)