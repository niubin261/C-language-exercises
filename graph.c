/*时间有限，写个最简单的图*/
#include<stdio.h>

#define N 3
char Vertex[N] = { 'a','b','c'};
bool AdjMatrix[N][N] = { false };
bool Visited[N] = { false };
void CreateGraph(bool AgiMatrix[][N]) {
    bool no = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &no);
            AgiMatrix[i][j] = no;
        }
    }

}
void PrintGraph(bool AdjMatrix[][N], char Vertex[N]) {
    for (int i = 0; i < N; i++) {
        printf("%c", Vertex[i]);
        printf("	");
        for (int j = 0; j < N; j++) {
            printf("%d\t", AdjMatrix[i][j]);
        }
    }
}
void TraverseGraph(bool AdjMatrix[][N], char Vertex[N], int bgn) {
    printf("%c", Vertex[bgn]);
    Visited[bgn]=true;
    for (int i = 0; i < N; i++) {
        if (AdjMatrix[bgn][i] != 0 && Visited[i] == false) {
            bgn = i;
            TraverseGraph(AdjMatrix, Vertex, bgn);
        }

    }
    return;
}
int main(void) {
    CreateGraph(AdjMatrix);
    PrintGraph(AdjMatrix, Vertex);

}
