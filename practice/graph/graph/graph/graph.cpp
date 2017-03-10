
#include <iostream>
using namespace std;

#define n 6  //图的顶点数
#define e 8  //图的边（弧）数


typedef char  vextype;  //顶点的数据类型
typedef float adjtype;  //权值类型

typedef struct
{
	vextype vexs[n];
	adjtype arcs[n][n];
}graph;

//建立无向图的邻接矩阵
void creatadj(graph &g)
{
	int i, j, k;
	
	//输入顶点信息
	for (k = 0; k < n; k++)
		g.vexs[k] = getchar();     
	
	//初始化邻接矩阵
	for (i = 0; i < n;i++)
	for (j = 0; j < n; j++)
		g.arcs[i][j] = 0;

	for (k = 1; k <= e; k++)
	{
		cin >> i>>j;       //输入一条边（i，j）
		g.arcs[i][j] = 1;
		g.arcs[j][i] = 1;		
	}
}


int main()
{
	graph *a;
	creatadj(*a);
}
