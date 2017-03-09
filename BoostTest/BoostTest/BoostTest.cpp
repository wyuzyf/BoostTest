
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
