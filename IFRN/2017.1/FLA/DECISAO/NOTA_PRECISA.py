n1=float(input("Digite a nota do 1º bimestre: "))
n2=float(input("Digite a nota do 2º bimestre: "))

media=(n1*2+n2*3)/5
pf=120-media

if (media>=60):
	print("Você foi aprovado com média {}".format(media))
elif (30<=media<60):
	print("Você ficou em recuperação e tirou {}. Precisa de {} na prova final para passar.".format(media,pf))
elif (media<30):
	print("Você foi reprovado com média {}. Não adianta chorar.".format(media))
