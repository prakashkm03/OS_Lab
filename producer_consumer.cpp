#include<iostream>
using namespace std;

int mutex=1,empty=5,full=0,i=0;

int wait(int s)
{
	return --s;
}

int signal(int s)
{
	return ++s;
}

void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	i++;
	cout<<"Item produced is :"<<i<<endl;
	mutex=signal(mutex);
}

void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	cout<<"Item consumed is :"<<i<<endl;
	i--;
	mutex=signal(mutex);	

}


int main()
{
	int flag=1, n;

	cout<<"Choices: "<<"1.Produce  "<<"2.Consume  "<<"3.Exit."<<endl;
	while(flag)
	{
		cout<<"Choice: ";
		cin>>n;
		switch(n)
		{
			case 1:
				if((mutex==1)&&(full!=5))
					producer();
				else
					cout<<"Buffer Full."<<endl;
				break;
			case 2:
				if((mutex==1)&&(empty!=5))
					consumer();
				else
					cout<<"Buffer Empty."<<endl;
				break;
			case 3:
				cout<<"\nThanks. Bye.";
				flag=0;
				break;
		}
	}

	return 0;
	
}