
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

//time ��
//(1)time
/*
#include <boost/timer.hpp>
#include <iostream>
using namespace std;    //���ֿռ�
using namespace boost;

int main(){
	timer t;
	cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << endl;
	cout << "max timespan:" << t.elapsed_min() << "s" << endl;

	//����Ѿ����ŵ�ʱ��
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


//(3)��չ��ʱ����
//��������ǰ����������ģ��������û�����������ʲô��û�У�
//����������˼�� �ڳ����˳���ʱ��ִ������������Ȼ��ִ��Try��
//���cout�����ݣ������ȴ�������Ĳ�һ��
#include <boost/progress.hpp>
#include <boost/static_assert.hpp>
#include <iostream>

using namespace std;
using namespace boost;

//ʹ��ģ����ʵ��progress_timer
template<int N > class new_progress_timer :public boost::timer{
public:
	new_progress_timer(ostream &os = cout) : m_os(os)
	{
		BOOST_STATIC_ASSERT(N>=0&&N<=10);   //��̬����
	}
	
	~new_progress_timer(void)    //�������������׳��쳣
	{
		try
		{
			//��������״̬
			istream::fmtflags old_flags
				= m_os.setf(istream::fixed, istream::floatfield);
			streamsize old_prec = m_os.precision(N);
		
			//���ʱ��
			m_os << elapsed() << "s \n" << endl;

			//�ָ���״̬
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

	//����Ѿ����ŵ�ʱ��
	//cout << "now time elapsed:" << t.elapsed() << "s" << endl;
	system("pause");
}
