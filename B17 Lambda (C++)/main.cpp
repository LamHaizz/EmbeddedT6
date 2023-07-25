#include <iostream>
using namespcate std;

int main(){

int a = 10;
int f = 30;
int k = 40;

auto func = [=]( int a , int b) -> int{
  return a +b +c +k;
};

cout << func( 18 ,2 )<<endl; // kq la 90
return 0;
}

