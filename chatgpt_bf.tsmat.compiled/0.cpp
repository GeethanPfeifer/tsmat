#include <iostream>
#include <stack>
using namespace std;
int main(){
int a[256] = {};
stack<int> s;
a[240]+=1;
a[240]%=256;
a[241]+=2;
a[241]%=256;
a[242]+=3;
a[242]%=256;
source_read:
cout << "0\n"<< flush;
cin >> a[0];
if(a[0])goto source_nonzero;
if(a[240])goto source_done;
source_nonzero:
s.push(a[0]);
a[1]=s.top();
s.pop();
a[1]+=213;
a[1]%=256;
if(a[1])goto source_test_1;
if(a[240])goto source_keep;
source_test_1:
s.push(a[0]);
a[1]=s.top();
s.pop();
a[1]+=212;
a[1]%=256;
if(a[1])goto source_test_2;
if(a[240])goto source_keep;
source_test_2:
s.push(a[0]);
a[1]=s.top();
s.pop();
a[1]+=211;
a[1]%=256;
if(a[1])goto source_test_3;
if(a[240])goto source_keep;
source_test_3:
s.push(a[0]);
a[1]=s.top();
s.pop();
a[1]+=210;
a[1]%=256;
if(a[1])goto source_test_4;
if(a[240])goto source_keep;
source_test_4:
s.push(a[0]);
a[1]=s.top();
s.pop();
a[1]+=196;
a[1]%=256;
if(a[1])goto source_test_5;
if(a[240])goto source_keep;
source_test_5:
s.push(a[0]);
a[1]=s.top();
s.pop();
a[1]+=194;
a[1]%=256;
if(a[1])goto source_test_6;
if(a[240])goto source_keep;
source_test_6:
s.push(a[0]);
a[1]=s.top();
s.pop();
a[1]+=165;
a[1]%=256;
if(a[1])goto source_test_7;
if(a[240])goto source_keep;
source_test_7:
s.push(a[0]);
a[1]=s.top();
s.pop();
a[1]+=163;
a[1]%=256;
if(a[1])goto source_invalid;
if(a[240])goto source_keep;
source_invalid:
if(a[240])goto source_read;
source_keep:
cout << "1 " << a[240] << ' ' << 2 << '\n' << flush;
cout << "1 " << a[0] << ' ' << 2 << '\n' << flush;
if(a[240])goto source_read;
source_done:
reverse_loop:
cout << "1 " << a[242] << ' ' << 2 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[2];
if(a[2])goto reverse_done;
cout << "1 " << a[241] << ' ' << 2 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[3];
cout << "1 " << a[240] << ' ' << 1 << '\n' << flush;
cout << "1 " << a[3] << ' ' << 1 << '\n' << flush;
if(a[240])goto reverse_loop;
reverse_done:
exec_loop:
cout << "1 " << a[242] << ' ' << 1 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[2];
if(a[2])goto program_done;
cout << "1 " << a[241] << ' ' << 1 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[10];
s.push(a[10]);
a[11]=s.top();
s.pop();
a[11]+=213;
a[11]%=256;
if(a[11])goto op_test_1;
if(a[240])goto op_plus;
op_test_1:
s.push(a[10]);
a[11]=s.top();
s.pop();
a[11]+=212;
a[11]%=256;
if(a[11])goto op_test_2;
if(a[240])goto op_comma;
op_test_2:
s.push(a[10]);
a[11]=s.top();
s.pop();
a[11]+=211;
a[11]%=256;
if(a[11])goto op_test_3;
if(a[240])goto op_minus;
op_test_3:
s.push(a[10]);
a[11]=s.top();
s.pop();
a[11]+=210;
a[11]%=256;
if(a[11])goto op_test_4;
if(a[240])goto op_dot;
op_test_4:
s.push(a[10]);
a[11]=s.top();
s.pop();
a[11]+=196;
a[11]%=256;
if(a[11])goto op_test_5;
if(a[240])goto op_left;
op_test_5:
s.push(a[10]);
a[11]=s.top();
s.pop();
a[11]+=194;
a[11]%=256;
if(a[11])goto op_test_6;
if(a[240])goto op_right;
op_test_6:
s.push(a[10]);
a[11]=s.top();
s.pop();
a[11]+=165;
a[11]%=256;
if(a[11])goto op_test_7;
if(a[240])goto op_open;
op_test_7:
s.push(a[10]);
a[11]=s.top();
s.pop();
a[11]+=163;
a[11]%=256;
if(a[11])goto malformed;
if(a[240])goto op_close;
op_plus:
a[20]+=1;
a[20]%=256;
if(a[240])goto advance;
op_minus:
a[20]+=255;
a[20]%=256;
if(a[240])goto advance;
op_comma:
cout << "0\n"<< flush;
cin >> a[20];
if(a[240])goto advance;
op_dot:
cout << "1 " << a[20] << ' ' << -1 << '\n' << flush;
if(a[240])goto advance;
op_left:
cout << "1 " << a[240] << ' ' << 4 << '\n' << flush;
cout << "1 " << a[20] << ' ' << 4 << '\n' << flush;
cout << "1 " << a[242] << ' ' << 3 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[2];
if(a[2])goto left_zero;
cout << "1 " << a[241] << ' ' << 3 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[20];
if(a[240])goto advance;
left_zero:
s.push(a[250]);
a[20]=s.top();
s.pop();
if(a[240])goto advance;
op_right:
cout << "1 " << a[240] << ' ' << 3 << '\n' << flush;
cout << "1 " << a[20] << ' ' << 3 << '\n' << flush;
cout << "1 " << a[242] << ' ' << 4 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[2];
if(a[2])goto right_zero;
cout << "1 " << a[241] << ' ' << 4 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[20];
if(a[240])goto advance;
right_zero:
s.push(a[250]);
a[20]=s.top();
s.pop();
if(a[240])goto advance;
op_open:
if(a[20])goto advance;
cout << "1 " << a[240] << ' ' << 2 << '\n' << flush;
cout << "1 " << a[10] << ' ' << 2 << '\n' << flush;
if(a[240])goto forward_scan;
op_close:
if(a[20])goto close_nonzero;
if(a[240])goto advance;
close_nonzero:
cout << "1 " << a[240] << ' ' << 1 << '\n' << flush;
cout << "1 " << a[10] << ' ' << 1 << '\n' << flush;
if(a[240])goto backward_scan;
advance:
cout << "1 " << a[240] << ' ' << 2 << '\n' << flush;
cout << "1 " << a[10] << ' ' << 2 << '\n' << flush;
if(a[240])goto exec_loop;
forward_scan:
cout << "1 " << a[242] << ' ' << 1 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[2];
if(a[2])goto malformed;
cout << "1 " << a[241] << ' ' << 1 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[12];
cout << "1 " << a[240] << ' ' << 2 << '\n' << flush;
cout << "1 " << a[12] << ' ' << 2 << '\n' << flush;
s.push(a[12]);
a[13]=s.top();
s.pop();
a[13]+=165;
a[13]%=256;
if(a[13])goto forward_test_close;
s.push(a[240]);
if(a[240])goto forward_scan;
forward_test_close:
s.push(a[12]);
a[13]=s.top();
s.pop();
a[13]+=163;
a[13]%=256;
if(a[13])goto forward_scan;
if(s.empty())goto forward_match;
a[14]=s.top();
s.pop();
if(a[240])goto forward_scan;
forward_match:
if(a[240])goto exec_loop;
backward_scan:
cout << "1 " << a[242] << ' ' << 2 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[2];
if(a[2])goto malformed;
cout << "1 " << a[241] << ' ' << 2 << '\n' << flush;
cout << "0\n"<< flush;
cin >> a[12];
cout << "1 " << a[240] << ' ' << 1 << '\n' << flush;
cout << "1 " << a[12] << ' ' << 1 << '\n' << flush;
s.push(a[12]);
a[13]=s.top();
s.pop();
a[13]+=163;
a[13]%=256;
if(a[13])goto backward_test_open;
s.push(a[240]);
if(a[240])goto backward_scan;
backward_test_open:
s.push(a[12]);
a[13]=s.top();
s.pop();
a[13]+=165;
a[13]%=256;
if(a[13])goto backward_scan;
if(s.empty())goto backward_match;
a[14]=s.top();
s.pop();
if(a[240])goto backward_scan;
backward_match:
if(a[240])goto exec_loop;
malformed:
cout << "2\n";
return 0;
program_done:
cout << "2\n";
return 0;
}
