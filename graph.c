/*时间有限，写个最简单的图*/
#include<stdio.h>
#define N 10
char Vertex[10] = { 'a','b','c','d','e','f','g','h','g','k' };
bool AdjMatrix[N][N] = { false };
bool Visited[10] = { false };
void CreateGraph(bool AgiMatrix[][10])
{
	bool no = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &no);
			AgiMatrix[i][j] = no;
		}
	}

}
void PrintGraph(bool AdjMatrix[][10], char Vertex[10])
{
	for (int i = 0; i < N; i++)
	{
		printf("%c", Vertex[i]);
		printf("	");
		for (int j = 0; j < N; j++)
		{
			printf("%d\t", AdjMatrix[i][j]);
		}
	}
}
void TraverseGraph(bool AdjMatrix[][10], char Vertex[10], int bgn)
{
	printf("%c", Vertex[bgn]);
	for (int i = 0; i < N; i++)
	{
		if (AdjMatrix[bgn][i] != 0 && Visited[i] == false)
		{
			
			bgn = i;
			TraverseGraph(AdjMatrix, Vertex, bgn);
		}
			
	}
	return;
}
int main(int argc, char* argv[])
{
	CreateGraph(AdjMatrix);
	TraverseGraph(AdjMatrix, Vertex, 0);
	
}

	
