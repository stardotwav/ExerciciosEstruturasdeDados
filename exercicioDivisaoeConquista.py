# Ordenar o Conjunto [5, 3, 1, 9, 8, 2, 4, 7] usando os Algoritmos QuickSort 
# e MergeSort.

# -- QuickSort --
# 5 (pivô), 3, 1, 9, 8, 2, 4, 7 (j)
# 5 (pivô), 3, 1, 9, 8, 2, 4 (j, troca), 7
# 4, 3 (i), 1, 9, 8, 2, 5 (pivô), 7
# 4, 3, 1 (i), 9, 8, 2, 5 (pivô), 7
# 4, 3, 1, 9 (i, troca), 8, 2, 5 (pivô), 7
# 4, 3, 1, 5 (pivô), 8, 2 (j, troca), 9, 7
# 4, 3, 1, 2, 8 (i, troca), 5 (pivô), 9, 7  

# 4, 3, 1, 2, 5 (pivô), 8, 9, 7             
# |-- nessa etapa dividimos o vetor em dois, e 5 fica fixo

# 4 (pivô), 3, 1, 2 (j, troca)     8 (pivô), 9, 7 (j, troca)
# 2, 3 (i), 1, 4 (pivô)     7 (i), 9, 8 (pivô)
# 2, 3, 1 (i), 4 (pivô)     7, 9 (i, troca), 8 (pivô)

# 2, 3, 1, 4 (pivô)    7, 8 (pivô), 9
# |-- nessa etapa dividimos o vetor em dois, e 4 e 7, 8, 9 ficam fixos

# 2 (pivô), 3, 1 (j, troca)
# 1, 3 (i, troca), 2 (pivô)    
# 1, 2 (pivô),  3
# |-- ordenado!


# -- MergeSort --
# 5, 3, 1, 9, 8, 2, 4, 7
# |-- divide em dois

# 5, 3, 1, 9     8, 2, 4, 7
# |-- divide em dois, cada subproblema

# 5, 3       1, 9     8, 2       4, 7
# ordena as duplas

# 3, 5      1, 9      2, 8       4, 7
# ordena duas duplas entre si

# 1, 3, 5, 9    2, 4, 7, 8
# ordena os dois subproblemas

# 1, 2, 3, 4, 5, 7, 8, 9
# ordenado!