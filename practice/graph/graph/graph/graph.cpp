
#include <iostream>
using namespace std;

#define n 6  //ͼ�Ķ�����
#define e 8  //ͼ�ıߣ�������


typedef char  vextype;  //�������������
typedef float adjtype;  //Ȩֵ����

typedef struct
{
	vextype vexs[n];
	adjtype arcs[n][n];
}graph;

//��������ͼ���ڽӾ���
void creatadj(graph &g)
{
	int i, j, k;
	
	//���붥����Ϣ
	for (k = 0; k < n; k++)
		g.vexs[k] = getchar();     
	
	//��ʼ���ڽӾ���
	for (i = 0; i < n;i++)
	for (j = 0; j < n; j++)
		g.arcs[i][j] = 0;

	for (k = 1; k <= e; k++)
	{
		cin >> i>>j;       //����һ���ߣ�i��j��
		g.arcs[i][j] = 1;
		g.arcs[j][i] = 1;		
	}
}


int main()
{
	graph *a;
	creatadj(*a);
}
