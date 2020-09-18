#Variables y Constantes:
num = 56
print(num)

#'Parseo' se traduce como el cambio de un string a un integer.
#También existe la 'Concatenación' que convierte de integer a string.
#Ejemplo de suma sin 'parsear':
a = input('Ingresa un numero: ')
b = input('Ingresa otro numero: ')
print(a+b)
#Ejemplo de suma con 'parseo': 
c = int(input('Ingresa un numero para el parseo: '))
d = int(input('Ingresa otro numero para el parseo: '))
print(c+d)
#Ejemplo de suma por 'concatenar': (Se puede poner así o dejar sin el float)
e = float(input('Ingresa un numero: '))
f = float(input('Ingresa otro numero: '))
print(e+f)

#Operadores con Multiplicación y División:
num1 = 8*8
num2 = 12/2
num3 = 13/3
print(num1)
print(num2) #También se puede colocar "print(int(num2))" si se desea sin punto decimal.
print(num3)

#Operación Residuo: 
residuo = 13%3
print(residuo) #Sale de resultado 1 porque 3x4=12. 

#Operación de comparación:
print('¿Es 8 menor que 10?: ', 8<10) #Menor que 
print('¿Y viceversa?: ', 8>10) #Mayor que
print('¿Es 8 igual a 10?: ', 8==10) #Igualar
print('¿Es 8 diferente a 10?: ', 8!=10) #Diferenciar

#Operaciones lógicas:
variable = not True
print(variable)
#Operación OR:
print(True or True)
print(True or False)
print(False or False)
#Operación AND:
print(True and True)
print(True and False)
print(False and False)

#Ejercicio 1: Programa que lea dos numeros e imprima la suma de estos.
g = int(input('Ingresa un numero: '))
h = int(input('Ingresa otro numero: '))
print(g+h)

#Ejercicio 2: Programa que lea tres numeros e imprima la multiplicación del primero por el segundo y se le sume el tercero.
i = int(input('Ingresa el primer numero: '))
j = int(input('Ingresa el segundo numero: '))
k = int(input('Ingresa el tercer numero: '))
print((i*j)+k)

#Ejercicio 3: Programa que lea un numero e imprima la mitad de ese numero.
l = int(input('Ingresa un numero: ')) 
print(l/2)

#Ejercicio 4: Programa que lea dos numeros e imprima True si el primero es mayor que el segundo.
m = int(input('Ingresa el primer numero: '))
n = int(input('Ingresa el segundo numero: '))
print(m>n)

#Ejercicio 5: Programa que lea 3 numeros y que imprima True si el primer numero es menor que el segundo y que el segundo y el tercero sean diferentes. 
o = int(input('Ingresa el primer numero: '))
p = int(input('Ingresa el segundo numero: '))
q = int(input('Ingresa el tercer numero: '))
print(o<p and p!=q)

#Ejercicio 6 (Challenge): Programa que lea tres numeros e imprima True si el primero y el segundo sean iguales o si el primero es al menos tres unidades más grande que el segundo.
r = int(input('Ingresa el primer numero: '))
s = int(input('Ingresa el segundo numero: '))
t = int(input('Ingresa el tercer numero: '))
print(r == s or r-3>=s)