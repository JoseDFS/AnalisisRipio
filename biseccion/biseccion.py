import math

a = 0
b = 2.1


# Definimos la función anterior
def f(x):
    a = 0.5
    b = a*(math.e**(-x/(2*math.pi)))
    c = math.sin(x)
    d=0.75
    return a+b*c-d



def bisection(f, a, b, T):
    n = math.ceil( math.log( (b - a)/T  , 2) ) #En esta línea estoy calculando el número de iteraciones necesarias
    for i in range(0, n):
        p = (a + b)/2
	#aqui falta imprimir el valor absoluto y agregar mas tab para mas bonis
        print(str(i) + " \t "+ " \t " + str(a) + " \t " + " \t "+ str(b) + " \t "+ " \t " + str(p) + " \t " + " \t "+ str(f(p)) )
        if f(a)*f(p) < 0:
            b = p
        else:
            a = p


bisection(f, a, b, 0.2)
#print ( f(1)) 



