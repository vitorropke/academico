ab=float(input("Digite uma distância AB: "))
bd=float(input("Digite uma distância BD: "))
be=float(input("Digite uma distância BE: "))
ac=float(input("Digite uma distância AC: "))
cf=float(input("Digite uma distância CF: "))
cg=float(input("Digite uma distância CG: "))

abd = ab+bd
abe = ab+be
acf = ac+cf
acg = ac+cg

if ((abd < abe) and (abd < acf) and (abd < acg)):
	print("Caminho percorrido: A -> B -> D")
	print("Distância percorrida: {}".format(abd))

elif ((abe < abd) and (abe < acf) and (abe < acg)):
	print("Caminho percorrido: A -> B -> E")
	print("Distância percorrida: {}".format(abe))
	
elif ((acf < abd) and (acf < abe) and (acf < acg)):
	print("Caminho percorrido: A -> C -> F")
	print("Distância percorrida: {}".format(acf))
	
elif ((acg < abd) and (acg < acf) and (acg < abe)):
	print("Caminho percorrido: A -> C -> G")
	print("Distância percorrida: {}".format(acg))

else:
	print("Todos os caminhos têm a mesma distância.")