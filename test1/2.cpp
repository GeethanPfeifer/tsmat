include <bits/stdc++.h>
using namespace std;
int main(){
int a[256] = {};
stack<int> s;
cout << "0 " << 200 << '\n' << flush;
cin >> a[20];
cout << "1 " << a[20] << ' ' << 200 << '\n' << flush;
a[20]+=100;
a[20]%=256;
if(a[20])goto ABC;
if(s.empty())goto ABC;
s.push(a[20]);
a[20]=s.top();
s.pop();
ABC:
cout << "2\n";
return 0;
}
