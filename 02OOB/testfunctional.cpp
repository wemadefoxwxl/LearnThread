#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::placeholders::_1;
using std::placeholders::_2;

class Foo
{
public:
	void MemberFun(double d,int i,int j)
	{
		cout << d << endl;
		cout << i << endl;
		cout << j << endl;
	}
};

int main()
{
	Foo foo;
	std::function<void (int)> fp = std::bind(&Foo::MemberFun,&foo,0.5,_1,10);
	fp(100);

	std::function<void (int,int)> fp2 = std::bind(&Foo::MemberFun,std::ref(foo),10,_1,_2);
	fp2(100,200);


	return 0;
}