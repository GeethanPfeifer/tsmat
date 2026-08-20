#include <iostream>
#include <stack>
using namespace std;
int main(){
int a[256] = {};
stack<int> s;
a[255]+=1;
a[255]%=256;
loop:
cout << "0 " << 0 << '\n' << flush;
cin >> a[0];
a[0]+=255;
a[0]%=256;
if(a[0])goto not_push;
cout << "0 " << 0 << '\n' << flush;
cin >> a[1];
s.push(a[1]);
if(a[255])goto loop;
not_push:
a[0]+=255;
a[0]%=256;
if(a[0])goto not_pop;
a[1]=s.top();
s.pop();
cout << "1 " << a[1] << ' ' << 0 << '\n' << flush;
if(a[255])goto loop;
not_pop:
if(s.empty())goto is_empty;
cout << "1 " << a[254] << ' ' << 0 << '\n' << flush;
if(a[255])goto loop;
is_empty:
cout << "1 " << a[255] << ' ' << 0 << '\n' << flush;
if(a[255])goto loop;
}
