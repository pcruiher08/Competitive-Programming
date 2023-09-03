def is_turbulent(string):
    length = len(string)
    
    flowing = all(string[i] <= string[i+1] for i in range(length-1))
    
    receding = all(string[i] >= string[i+1] for i in range(length-1))
    
    turbulent = not flowing and not receding
    
    return turbulent


import itertools

def generate_strings(length):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    combinations = itertools.product(alphabet, repeat=length)
    strings = [''.join(combination) for combination in combinations]
    return strings

n = 3
strings = generate_strings(n)


cuenta = 0

for s in strings:
    cuenta += is_turbulent(s)

print(cuenta)
