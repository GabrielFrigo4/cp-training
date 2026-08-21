# Rede de Influência (Componentes Fortemente Conectados)
 Você recebeu uma lista de conexões direcionadas entre usuários de uma rede social. Cada conexão A B indica que o usuário A segue o usuário B. Sua missão é calcular quantos componentes fortemente conectados (SCCs) existem.

 __Definição de SCC (Strongly Connected Component):__ Um componente fortemente conectado é um grupo de nós onde todos os nós podem alcançar todos os outros por meio de caminhos direcionados. Ou seja:

 * Se A → B e B → A, então eles fazem parte de um mesmo SCC.
 * Mas se A → B e B não alcança A, eles estão em SCCs diferentes.

## Input Format
 * Dois inteiros N e M: número de usuários e número de conexões
 * Em seguida, M linhas com dois inteiros A e B
 
# Constraints
```
.
```

# Output Format
 * O número total de componentes fortemente conectados

# Sample Input 0
```
5 5
1 2
2 3
3 1
4 5
5 4
```

# Sample Output 0
```
2
```
