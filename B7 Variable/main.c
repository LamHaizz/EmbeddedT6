#include<stdio.h>

extern void display();

/*void count (){
    static int temp = 0; //0xc1

    printf("temp: %d\n", temp);

    temp++;
}*/

int main (int argc,char const *argv[])
{

    display();
    
    count();

    count();

    count();

    return 0;
}