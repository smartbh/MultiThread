#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int global = 0;
mutex m;

void PlusOne()
{
	for (int i = 0; i < 10000; i++)
	{
		m.lock();

		global = global + 1;

		m.unlock();
	}
	
}

int main()
{
	thread* t[10];

	//cout << global << endl;

	for (int i = 0; i < 10; i++)
	{
		t[i] = new thread(PlusOne);		
	}

	for (int i = 0; i < 10; i++)
	{
		t[i]->join();
		cout << global << endl;
	}

	//PlusOne();
	//PlusOne();

	//cout << global << endl;
	//cout << global << endl;

	return 0;
}
