# Enunciado
A CIA interceptou um vídeo suspeito que circulava pela dark web, contendo 1000 números aparentemente aleatórios: ()[https://we.tl/t-2m5q9S3WGd]

Após uma análise, seus analistas descobriram que esses números escondiam o código para desarmar uma bomba plantada por um grupo terrorista. A bomba, prestes a ser detonada, exibe dois números em seu display – os índices que apontam a localização exata dos números no vídeo.

Uma análise preliminar constatou algumas características do vídeo:

A soma de todos os números no vídeo é 5504940
A cor de fundo do vídeo alterna entre preto e branco sempre que um novo número aparece
O tempo que cada número aparece no vídeo é constante
O número no canto inferior direito é só um contador e não deve ser considerado na soma
Sua missão é criar um código que mostre a soma dos números entre um índice e outro para que a equipe anti-terrorismo possa desarmar a bomba com sucesso.

Contamos com você!

## Input Format
A entrada possui apenas uma linha contendo 2 números inteiros A e B separados por espaço.

## Constraints
0 <= A <= B < 1000

## Output Format
A saída deve ser apenas a soma de todos os números entre os dois índices

## Sample 0
Input
```
134 154
```

Output
```
96941
```

## Dica
```
Soma entre os indices 0 e 100: 541181
Soma entre os indices 100 e 200: 545856
Soma entre os indices 200 e 300: 607496
Soma entre os indices 300 e 400: 568686
Soma entre os indices 400 e 500: 556993
Soma entre os indices 500 e 600: 534643
Soma entre os indices 600 e 700: 549969
Soma entre os indices 700 e 800: 583186
Soma entre os indices 800 e 900: 544919
Soma entre os indices 900 e 999: 526748
```

# Softwares
 - `FFMPEG` => Get PNG frames in MP4 file
 - `OCRAD` or `GOCR` => Get Text in PNG frames
