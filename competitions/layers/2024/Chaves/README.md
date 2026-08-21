# Enunciado
Seu amigo Lucas está tendo dificuldades com programação em C, especialmente com o uso de chaves { }, que são essenciais para delimitar blocos de código. Ele frequentemente esquece de colocá-las ou as insere de maneira incorreta, e, como não compreende bem as mensagens de erro, tem dificuldade em identificar o que está errado.

Lucas te pediu ajuda para desenvolver um programa que verifique se as chaves no código dele estão corretamente balanceadas, ou seja, se o código é válido. Para que o código esteja balanceado, ele deve seguir estas regras:

Se não houver chaves, ele está correto (como em textos simples, por exemplo, "Bom" ou "Correto");
O código pode ser uma sequência de blocos válidos (como por exemplo, "Bom Correto", "{}{}", ou "{}Correto");
O código também pode ser um bloco válido dentro de chaves (como por exemplo, "{{}}" ou "{Bom}").
O código de Lucas é composto por N linhas, cada uma com até 100 caracteres. Pode haver linhas vazias e espaços consecutivos.

## Input Format
A primeira linha contém um inteiro N, representando o número de linhas no código. As N linhas seguintes contém até 100 caracteres.

## Constraints
1 ≤ N ≤ 1000

## Output Format
Seu programa deve produzir uma única linha, contendo uma única letra, "S" se o código está com as chaves balanceadas e "N", caso contrário.

## Sample 0
Input
```
1
{}{{{}}}{}{}{{}{}{}{}{}{{}{}}}{{}{}{{}{}{}}{{}{{}{}}}}{{}{{}{}{{{}}{}}{{}{{{}}}}{}}{{}{{}}}{{{{}}}}}
```

Output
```
S
```

## Sample 1
Input
```
1
{}{{}}{}{}{{}{}}{{{{}{}}{}}{}{}{{}{}{{}}}}{}{{}}{{}}{}{}{{{{{{}}}{}{{}{{}}{{}{}}}}{{}}}{{{}}{}{}}}}
```

Output
```
N
```

## Dica
1. A quantidade de `{` e de `}` devem ser iguais
2. A quantidade de `{` deve ser sempre maior do que a de `}`.
