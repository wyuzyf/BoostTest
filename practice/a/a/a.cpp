

#include <iostream>

using namespace std;
int main()
{
	int he;
	int re = 0;   // ����ת��Ϊ10���ƵĽ������
	int k = 16;   // 16����
	int n = 1;    // λȨ
	
	cin >>"please input hexnumber">>he;   // �����û������16������������0xǰ׺
	
	while (he != 0)
	{
		re += (he % 10)*n;  // ȡ����λλ��ֵ�������Զ�Ӧ��λȨֵ
		he /= 10;   // ȥ��16�����������λ���ε�λ��Ϊ���λ
		n *= k;     // λȨ����16
	}
	cout<< re; // ���ת����Ľ��
}