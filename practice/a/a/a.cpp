

#include <iostream>

using namespace std;
int main()
{
	int he;
	int re = 0;   // 保存转换为10进制的结果搜索
	int k = 16;   // 16进制
	int n = 1;    // 位权
	
	cin >>"please input hexnumber">>he;   // 接收用户输入的16进制数，不含0x前缀
	
	while (he != 0)
	{
		re += (he % 10)*n;  // 取出各位位码值，并乘以对应的位权值
		he /= 10;   // 去掉16进制数的最低位，次低位变为最低位
		n *= k;     // 位权乘以16
	}
	cout<< re; // 输出转换后的结果
}