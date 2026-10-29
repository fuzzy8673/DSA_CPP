#include <iostream>
using namespace std;

void towerOfHanoi(int n,char s,char h,char d){
    if (n==1)
    {
        cout<<"disk "<< n << " moved from " << s << " to " << d<<endl;
        return;
    }
    towerOfHanoi(n-1,s,d,h);
    cout<<"disk"<< n << " moved from " << s << " to " << d<<endl;
    towerOfHanoi(n-1,h,s,d);
}

int main(){
    towerOfHanoi(3,'S','H','D');
    return 0;
}