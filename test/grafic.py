
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
from numpy import median

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

def read_file(name_file):
	data_frame = pd.read_csv(name_file)
	return data_frame

def save_barplot(data,x,y,xlabel,ylabel,title,file_name):
    plt.close()
    ax = sns.barplot(x=x, y=y, data=data,palette = "BuGn_r",estimator=median)
    ax.set_title(title)
    ax.set(xlabel= xlabel)
    ax.set(ylabel= ylabel)
    ax.figure.savefig(file_name,format='jpeg')
    plt.close()

bubblesort_data = read_file("bubblesort.csv")
simdsort_data = read_file("simdsort.csv")	
bubblesort_separate_data = read_file("bubblesort_separate.csv")
simdsort_separate_data = read_file("simdsort_separate.csv")	
print(bubblesort_separate_data.mean())
print(simdsort_separate_data.mean())
save_barplot(simdsort_data,"instance", "value", "Instancia", "Tiempo promedio [S]", "Tiempos de ejecución para algoritmo SIMD", "simd_sort.jpeg")
save_barplot(bubblesort_data,"instance", "value", "Instancia", "Tiempo promedio [S]", "Tiempos de ejecución para algoritmo BUBBLE", "bubble_sort.jpeg")
