
/*
#include <boost/lexical_cast.hpp>       
#include <iostream>       
using namespace std;
int main()
{
	using boost::lexical_cast;
	int a = lexical_cast<int>("123");
	double b = lexical_cast<double>("123.0123456789");
	string s0 = lexical_cast<string>(a);
	string s1 = lexical_cast<string>(b);
	cout << "number: " << a << "  " << b << endl;
	cout << "string: " << s0 << "  " << s1 << endl;
	int c = 0;
	try{
		c = lexical_cast<int>("abcd");
	}
	catch (boost::bad_lexical_cast& e){
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}
*/

//time 库
//(1)time
/*
#include <boost/timer.hpp>
#include <iostream>
using namespace std;    //名字空间
using namespace boost;

int main(){
	timer t;
	cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << endl;
	cout << "max timespan:" << t.elapsed_min() << "s" << endl;

	//输出已经流逝的时间
	cout << "now time elapsed:" << t.elapsed() << "s" << endl;

	system("pause");
}
*/


//(2)progress_timer
/*
#include <boost/progress.hpp>
#include <iostream>
using namespace std;
using namespace boost;

int main(){
	progress_timer t;

	cout << t.elapsed() << endl;
	system("pause");
}
*/


//(3)扩展计时精度
//这个程序是按照书上来的，但是最后没有输出（就是什么都没有）
//按我理解的意思是 在程序退出的时候，执行析构函数，然后执行Try块
//输出cout的内容，但结果却和我理解的不一样
/*
#include <boost/progress.hpp>
#include <boost/static_assert.hpp>
#include <iostream>

using namespace std;
using namespace boost;

//使用模板类实现progress_timer
template<int N > class new_progress_timer :public boost::timer{
public:
	new_progress_timer(ostream &os = cout) : m_os(os)
	{
		BOOST_STATIC_ASSERT(N>=0&&N<=10);   //静态断言
	}
	
	~new_progress_timer(void)    //析构函数不能抛出异常
	{
		try
		{
			//保存流的状态
			istream::fmtflags old_flags
				= m_os.setf(istream::fixed, istream::floatfield);
			streamsize old_prec = m_os.precision(N);
		
			//输出时间
			m_os << elapsed() << "s \n" << endl;

			//恢复流状态
			m_os.flags(old_flags);
			m_os.precision(old_prec);
		}
		catch (double){ }
	}

private:
	ostream & m_os;
};

//template<> class new_progress_timer<2>:public boost::progress_timer
//{};

int main(){
	new_progress_timer<10> t;

	//cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << endl;
	//cout << "max timespan:" << t.elapsed_min() << "s" << endl;

	//输出已经流逝的时间
	//cout << "now time elapsed:" << t.elapsed() << "s" << endl;
	system("pause");
}
*/

//(4)progress_display 显示程序执行的进度
//我改v的大小，pos,pded自加自减，输出都不变（第一版）
//（第二版），报告字符串的行号,显示结果还是和想象的不一样，这应该是自带的BUG
#include <iostream>
#include <filesystem>    //不加这个头文件的时候，ofstream fs这句有错误
#include <boost/progress.hpp>
#include <vector>

using namespace std;
using namespace boost;
/*
int main()
{
	vector<string> v(10);   //声明一个字符串向量的对象
	ofstream fs("c:\\test.txt");         //文件输出流

	//声明一个progress_display对象，基数是v的大小
	progress_display pd(v.size());

	//开始迭代遍历向量，处理字符串，写入文件
	vector<string>::iterator pos;
	for (pos = v.begin(); pos != v.end(); pos++)
	{
		fs << *pos << endl;
		pd++;   //更新进度显示
	}

	system("pause");
}
*/

int main()
{
	vector<string> v(100,"aaa");      

	v[10] = "";
	v[23] = "";

	ofstream fs("c:\\test.txt");
	progress_display pd(v.size());

	vector<string>::iterator pos;
	for (pos = v.begin(); pos != v.end(); ++pos)
	{
		fs << *pos << endl;
		++pd;   //更新进度显示
		
		if (pos->empty())
		{
			cout << "null string #" << (pos - v.begin()) << endl;
		}
	}

	system("pause");
}








