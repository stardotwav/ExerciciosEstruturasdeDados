# Pseudocódigo do Problema do Fecho Convexo
# e Complexidade

# O Problema
# O Fecho Convexo é o Menor Poligono Convexo que contém
# todos os pontos do conjunto
# Dessa forma, para determinar o menor poligono devemos
# percorrer todos os pontos possíveis e calcular suas
# retas para os demais pontos, de forma que ao final é
# verificado os sinais positivos e negativos, para
# determinar o poligono

# A complexidade
# Para percorrer todos os pontos, com todos os outros essa
# operação será dada como O(n^2), visto que além disso devemos
# verificar se tais pontos são negativos ou positivos para
# determinar o poligono, essa operação é dada como O(n), sendo
# assim uma complexidade de O(n^3)