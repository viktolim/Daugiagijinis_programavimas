#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
void DoWork1();
void DoWork2();
void DoWork(int a, int b, string msg);

int main()
{
	cout << "START MAIN" << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << this_thread::get_id() << endl;
	thread th(DoWork1);
	thread th1(DoWork2);
	for (int i = 0; i < 10; i++)
	{
		cout << "Thread ID" << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	thread th2(DoWork,2,3,"Hello");
	for (size_t i = 0; true; i++)
	{
		cout << "Thread ID= " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	
}

void DoWork1()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "Thread ID" << this_thread::get_id() << "\tDoWork\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}
void DoWork2()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "Thread ID" << this_thread::get_id() << "\tDoWorkiii\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}
void DoWork(int a, int b, string msg)
{
	cout << msg << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "==========\t" << "DoWork STARTED\t=========" << endl;
	cout << "a+b= " << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "==========\t" << "DoWork STOPPED\t=========" << endl;
}