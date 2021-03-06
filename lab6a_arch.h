#include <iostream>
#include <functional>

float Div(float a,float b)
{ 
	if (b==0)
		throw std::invalid_argument ("second arg is 0");
	return a/b;
}




void CatchException(std::function<void()> func)
{
	try
	{
		func();
	}
	catch(std::out_of_range t)
	
	{ 
		std::cout<<t.what()<<std::endl;

	}
	catch(...)
	{ 
		std::cout<<"all exceptions"<<std::endl;
	}


}


void CatchThrowException(std::function<void()> func)

{
	try
	{
		func();
	}
	catch(std::out_of_range t)
	
	{ std::cout<<t.what()<<std::endl;

	}
	catch(...)
	{ 
		throw std::logic_error("bad_function_call");
	}



}

class TTestRAII
{

	MyResource * _ptr;

public:
	TTestRAII(MyResource * ptr)
		   :_ptr(ptr)
	{
		_ptr->lock();
	}
		 
	~TTestRAII()

	{
		_ptr->unlock();
		delete _ptr;
	}




};
