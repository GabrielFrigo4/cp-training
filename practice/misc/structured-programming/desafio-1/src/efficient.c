#include <stdio.h>
#include <stdbool.h>

void distribuiCameras(const int N, const int M, const int K, const int matriz[N][M], int cameras[K], int vigiadas[M]);

void inputTest(int input[3]);
void inputMatriz(const int N, const int M, int matriz[N][M]);

bool memoryCombination(const int N, const int K, const int index, int comb[K]);
void memorySet(const int n, int buffer[n], const int val);
void memoryCopy(const int n, const int in_buffer[n], int out_buffer[n]);
int memoryAccumulate(const int n, const int buffer[n]);
bool memoryOk(const int n, const int buffer[n]);

int main(void) {
	int input[3];
	inputTest(input);
	const int N = input[0], M = input[1], K = input[2];

	int matriz[N][M];
	inputMatriz(N, M, matriz);

	int vigiadas[M];
	memorySet(M, vigiadas, 0);

	int cameras[K];
	for (int i = 0; i < K; i++)
		cameras[i] = i;

	distribuiCameras(N, M, K, matriz, cameras, vigiadas);
	if (cameras[0] <= -1 )
		printf("-1");
	else
		for (int i = 0; i < K; i++)
			printf("%i ", cameras[i]);
	return 0;
}

void distribuiCameras(const int N, const int M, const int K, const int matriz[N][M], int cameras[K], int vigiadas[M]) {
	int i, j;
	bool flag;

	memorySet(M, vigiadas, 0);
	for (i = 0; i < K; i++)
		for (j = 0; j < M; j++)
			vigiadas[j] += matriz[cameras[i]][j];

	if (!memoryOk(M, vigiadas)) {
		flag = memoryCombination(N, K, 0, cameras);
		if (!flag) {
			memorySet(K, cameras, -1);
			return;
		}
	}
	else
		return;

	distribuiCameras(N, M, K, matriz, cameras, vigiadas);
}

void inputTest(int input[3]) {
	scanf("%i %i %i", &input[0], &input[1], &input[2]);
}

void inputMatriz(const int N, const int M, int matriz[N][M]) {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%i", &matriz[i][j]);
}

bool memoryCombination(const int N, const int K, const int index, int comb[K]) {
    int i;
    bool flag;
    if (index == K)
        return false;
	if (comb[index] < N + index - K) {
		flag = memoryCombination(N, K, index + 1, comb);
		if (!flag) {
		    comb[index]++;
		    for (i = index + 1; i < K; i++)
		        comb[i] = comb[i - 1] + 1;
		}
		return true;
	}
	return false;
}

void memorySet(const int n, int buffer[n], const int val) {
	int i;
	for (i = 0; i < n; i++)
		buffer[i] = val;
}

void memoryCopy(const int n, const int in_buffer[n], int out_buffer[n]) {
	int i;
	for (i = 0; i < n; i++)
		out_buffer[i] = in_buffer[i];
}

int memoryAccumulate(const int n, const int buffer[n]) {
	int i, ac = 0;
	for (i = 0; i < n; i++)
		ac += buffer[i];
	return ac;
}

bool memoryOk(const int n, const int buffer[n]) {
	int i;
	for (i = 0; i < n; i++)
		if (buffer[i] <= 0)
			return false;
	return true;
}
