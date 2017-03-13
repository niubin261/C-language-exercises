//输出标准格式的杨辉三角，真是垃圾
#include<stdio.h>
#define N 5
int main(){
	int a[5][5] = { 0 };
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (j != 0 && j != i){
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
			else if (j == 0 || i == j){
				a[i][j] = 1;
			}
			else
				a[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j <= i; j++){
		
			printf("%d", a[i][j]);
			
		}
		printf("\n");
	}
}

/**************/
//1
11
121
1331
14646//没有标准输出
