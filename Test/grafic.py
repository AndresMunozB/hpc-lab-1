import matplotlib.pyplot as plt

def openFile():
	result = []
	count = 0
	prom = 0.0
	promList = []
	auxList = []
	file = open("result.txt", 'r')
	for aux in file:
		if (count < 20):
			aux = aux.replace("\n","").split(" ")
			for element in aux:
				auxList.append(element)
				prom = prom + float(element)
				count = count + 1
			promList.append(auxList)
			promList.append(float(prom/20.0))
			result.append(promList)
			auxList = []
			promList = []
			prom = 0
			count = 0
	return result

def grafic():
	result = openFile()
	print(result)
	colors = ['black','red','gray','orange','gold','yellow']
	count = 0
	x = list(range(1,len(result)+1))
	print(result)
	print(x)

	#####
	plt.scatter(x,result,s=15)
	plt.title("Totalidad de ejecuciones")
	plt.ylabel("Cantidad de trabajadores normalizado")
	plt.xlabel("Iteraciones")
	plt.legend(loc='best')
	plt.show()

grafic()