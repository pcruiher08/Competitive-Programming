def convert_letter_to_num(letter):
    return ord(letter.upper()) - ord('A') + 10

def calculate_check_digit(container_code):
    value_mapping = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] + [convert_letter_to_num(chr(x)) for x in range(ord('A'), ord('Z') + 1)]
    weights = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512]
    code_values = [value_mapping[ord(x) - ord('0')] if x.isdigit() else value_mapping[ord(x) - ord('A') + 10] for x in container_code]
    sum = 0
    for i in range(len(code_values)):
        sum += code_values[i] * weights[i % len(weights)]
    return (10 - sum % 10) % 10

container_code = 'CSQU305438'  
print(calculate_check_digit(container_code))

