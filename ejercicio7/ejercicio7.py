
# 7. En Python realiza el cálculo de Pi, mediante sumas sucesivas.
# Rta.
# usando la fórmula de Leibniz
# La fórmula es
# X = 4 - 4/3 + 4/5 - 4/7 + 4/9 - ....
# Esta serie es interminable, cuanto más términos contiene esta serie, más cerca convergen el valor de X al valor de Pi.

# denominador
k = 1

# Inicio suma
s = 0

for i in range(1000000):

	
	if i % 2 == 0:
		s += 4/k
	else:

		
		s -= 4/k

	# denominator 
	k += 2
	
print(s)