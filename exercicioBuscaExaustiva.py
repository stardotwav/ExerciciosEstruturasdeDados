# Gerar o Pseudocódigo da Permutação do Problema de 
# Alocação de Tarefas

def permutacao(lista):
    if(len(lista) == 0):
        return

    if(len(lista) == 1):
        return [lista]

    listaPermutacao = []
    for i in range(len(lista)):
        m = lista[i]
        # salvamos cada posição no começo, e as demais
        # são permutadas nas demais posições de forma
        # recursiva
        listaTemporaria = lista[:i] + lista[i+1:]

        for j in permutacao(listaTemporaria):
            listaPermutacao.append([m] + j)

    return listaPermutacao

# verificar se a lista tem tamanho 0 ou 1
# se 0 apenas retornar 0, e se 1 retornar
# sua única posição

# após isso, para cada nova permutacao a 
# posição em questão será mantida como 
# primeira posição, por exemplo a tarefa 1
# será mantida para o trabalhador 1 durante
# a permutação das demais posições
# as demais posições serão invertidas
# aleatoriamente e verificado se aquela
# permutação já foi inserida anteriormente

def menorCusto(matrizCusto, lista):
    menorValor = 1000000
    pos = 0
    cont = 0
    listaMenor = []

    for i in permutacao(lista):
        valor = 0

        for j in range(len(i)):
            valor += matrizCusto[j-1][i[j]-1]

        if(valor < menorValor):
            menorValor = valor
            pos = cont
            listaMenor = i

        cont += 1

    print(menorValor)
    print(listaMenor)

lista = [1, 2, 3, 4]
matriz = [[1, 2, 3, 4],
        [2, 1, 3, 4],
        [3, 2, 1, 4],
        [4, 3, 2, 1]]

menorCusto(matriz, lista)