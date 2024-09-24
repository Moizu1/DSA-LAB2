#include<iostream>
using namespace std;
#define maxitem 100

template<class items>
class Stack
{
private:
	int top;
	items max;
		items* ptr;

public:
	Stack();
	Stack(items max);
	~Stack();
	bool isempty();
	bool isfull();
	void push(items new_item);
	void pop(items& item );
};
template<class items>
Stack<items>::Stack()
{
	top = -1;
	items max[100];
	ptr = new items[100];

}
template<class items>
Stack<items>::Stack(items max1)
{
	top = -1;
	max = max1;
	ptr = new items[max1];
}

template<class items>
Stack<items>::~Stack()
{
	delete[]ptr;
}

template<class items>
bool Stack<items> :: isempty()
{
	return (top == -1);
}

template<class items>
bool Stack<items> ::isfull()
{
	return(top == maxitem - 1);
}

template<class items>
void Stack<items>::push(items item)
{
	if (isfull())
	{
		cout << "STACK OVERFLOW";
		exit(1);
	}
	top++;
	 ptr[top] = item;
}

template<class items>
void Stack<items>::pop(items& item)
{
	if (isempty())
	{
		cout << "STACK UNDERFLOW";
		exit(1);
	}
	item = ptr[top];
	top--;
 }



int main()
{
	char ch;
	Stack<char> str;
	string str1,temp;
	cout << "Enter Word: ";
	cin >> str1;
	for (int i = 0; i < str1.length(); i++)
	{
		str.push(str1[i]);
	}
	for (int i = 0; i < str1.length(); i++)
	{
		str.pop(ch);
		temp += ch;
	}
	if (str1 == temp)
	{
		cout << "its a palidnrom";
	}
	else
		cout << "not a palidrom";



	return 0;
}