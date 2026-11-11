from itertools import combinations


def resolver(N, M, K, matriz):
    ruas_por_esquina = [[] for _ in range(N)]
    for j in range(M):
        for i in range(N):
            if matriz[i][j] == 1:
                ruas_por_esquina[i].append(j)

    def todas_as_ruas_cobertas(cameras):
        vigiada = [0] * M
        for camera in cameras:
            for rua in ruas_por_esquina[camera]:
                vigiada[rua] += 1
        return all(v > 0 for v in vigiada)

    for cameras in combinations(range(N), K):
        if todas_as_ruas_cobertas(cameras):
            return list(cameras)

    return -1


def main():
    N, M, K = map(int, input().split())
    matriz = [list(map(int, input().split())) for _ in range(N)]

    resultado = resolver(N, M, K, matriz)

    if resultado == -1:
        print(-1)
    else:
        print(" ".join(map(str, sorted(resultado))))


if __name__ == "__main__":
    main()
