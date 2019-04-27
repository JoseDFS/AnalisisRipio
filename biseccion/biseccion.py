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

#Teorema del valor intermedio Sea f: [a,b]→R función continua y K cualquier número real que satisface o bien f(a)<K<f(b)of(b)<K<f(a).
# Entonces existe un c ∈ (a,b) tal que f(c) = K.En particular, si f(a) y f(b) tienen signos opuestos, se diceque debe existir un ce ntre a y b tal que f(c) =0.




#//Ventajas del Método de Bisección.
 
#// Es siempre convergente.
#//Es óptimo para resolver una ecuación f(x)=0 cuando no se sabe nada de f, excepto calcular su signo.
#//Requiere que f sea continua en el intervalo especificado.
#//Se basa en el Teorema de Bolzano.
#//Se puede establecer el límite de error.
#//Es fácil de implementar.

#//Desventajas del Método de Bisección.
 
#//Converge muy lentamente.
#//Permite encontrar solo una raíz, aunque existan más en el intervalo.
#//Algunas veces la determinación del intervalo inicial no es muy fácil.
#//A veces, no es obvio el criterio de finalización del proceso iteractivo.
#//No puede determinar raíces complejas.
#//Es difícil generalizarlo para dimensiones superiores.




