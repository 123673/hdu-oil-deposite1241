#include<iostream>
#include<algorithm>
#include<cstring>
int r, c;
char oil[105][105];
using namespace std;
void dfs(int x, int y){
	oil[x][y] = '*';
	for (int i = -1; i <= 1; ++i){
		for (int j = -1; j <= 1; ++j){
			int xn = x + i;
			int yn = y + j;
			if (xn >= 0 && yn >= 0 && xn < r&&yn < c&&oil[xn][yn] == '@') dfs(xn, yn);
		}
	}
	return;
}
int main(){
	while (cin>>r>>c){
		if (r==0&&c==0) break;
		int sum = 0;
		for (int i = 0; i < r; ++i){
				scanf("%s", &oil[i]);
		}
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				if (oil[i][j] == '@'){
					dfs(i, j);
					sum++;
				}
			}
		}
		printf("%d\n", sum);
	}
	system("pause");
	return 0;
}