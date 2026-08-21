# Teclado telefônico
 Nos teclados de telefone, cada tecla de 0 a 9 permite digitar números, mas também apresenta letras associadas a alguns desses dígitos. Essas letras são frequentemente usadas para ajudar a memorizar certos números. Por exemplo, o número (74) 7622 3623 pode ser lembrado como a palavra pipocadoce, facilitando a memorização.

 Um mesmo número pode ser representado por diferentes combinações de letras. Por exemplo, o número 3482 pode ser traduzido como fita, diva, dita, égua, entre várias outras palavras possíveis.

 Dado um número telefônico e uma lista de palavras, sua tarefa é descobrir quantas dessas palavras poderiam ser associadas ao número, seguindo o mapeamento tradicional de letras no teclado de telefone.

## Input Format
 A primeira linha contém uma cadeia de caracteres N, representando o número telefônico (composto apenas por dígitos de 2 a 9). A segunda linha contém um inteiro M, indicando o número de palavras fornecidas. Cada uma das próximas M linhas contém uma palavra Ci, composta apenas por letras minúsculas.

## Constraints
 * 1 ≤ comprimento de N ≤ 1.000
 * N contém apenas dígitos de 2 a 9
 * 1 ≤ M ≤ 1.000
 * Cada Ci contém apenas letras minúsculas sem acento
 * 1 ≤ comprimento de Ci ≤ 1.000
 * Todas as Ci são distintas

## Output Format
 Seu programa deve imprimir uma única linha com um número inteiro: a quantidade de palavras da lista que podem representar o número dado.

## Sample Input 0
```
35696647984329688888
27
elozmngqzvhdbzmutvvv
flnynmgrzuhfbzntvvtt
adkozmngpytgfaxovatvu
ejmymohsxvgebyouuutv
ekoxnogpxthdbznuuvvu
ejoxnohrztifcymtvutv
fknymoisyvidcxmvunuv
flnzongrztgfczotuvuu
dknxmngqztgfazuvttut
elmznnhqyvgdaymutvut
dlozongqztheazouvvvt
fkmxnmgryviecxnvuutv
flnyonhpxvidbyntvtuu
fjmymngqztgeayotuuuv
dkmxmngqxuiebxmtvttt
ejmznnhsztjebymtxutu
ejoynngqzviebzovuvvu
flozomgpztifaxmtvuut
dkmzoohszuheaknuuvtv
ifjozdnirzugdbznutttt
elnxmoipxvidazmvuuut
fkoxnnisztgecymvtvtu
tdkmzmngratifayjvvvuu
wdjoznngruthwbynttvtt
floznmhpxvieqymutvva
fjmzmoipzvgdcznvvuvt
djnxmohrytidaymttvtv
```

## Sample Output 0
```
18
```

## Sample Input 1
```
5
5
j
a
l
k
g
```

## Sample Output 1
```
3
```
