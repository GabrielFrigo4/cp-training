from itertools import combinations

def resolver(N, M, K, matriz):
    # Criar uma lista de quais ruas são cobertas por cada esquina
    ruas_por_esquina = [[] for _ in range(N)]
    for j in range(M):
        for i in range(N):
            if matriz[i][j] == 1:
                ruas_por_esquina[i].append(j)

    # Função para verificar se um conjunto de câmeras cobre todas as ruas
    def todas_as_ruas_cobertas(cameras):
        vigiada = [0] * M
        for camera in cameras:
            for rua in ruas_por_esquina[camera]:
                vigiada[rua] += 1
        return all(v > 0 for v in vigiada)

    # Tentar todas as combinações de K esquinas e verificar se elas cobrem todas as ruas
    for cameras in combinations(range(N), K):
        if todas_as_ruas_cobertas(cameras):
            return list(cameras)  # Retorna a solução em ordem crescente

    return -1  # Se não encontrar uma solução válida, retorna -1

# Função para leitura e execução
def main():
    # Leitura da entrada
    N, M, K = map(int, input().split())
    matriz = [list(map(int, input().split())) for _ in range(N)]

    resultado = resolver(N, M, K, matriz)

    if resultado == -1:
        print(-1)
    else:
        print(" ".join(map(str, sorted(resultado))))

# Chama a função principal
if __name__ == "__main__":
    main()
