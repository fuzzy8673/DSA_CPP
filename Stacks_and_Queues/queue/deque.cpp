#include<iostream>
#include<deque>
using namespace std;

int main() {
	deque<int>dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_front(99);
	
	dq.push_front(40);
	cout << dq.front() <<" " << dq.back() << endl;
	
	dq.pop_back();
	dq.pop_front();
	cout << dq.front() <<" " << dq.back() << endl;
	return 0;
}
