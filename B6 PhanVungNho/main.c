#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int tong(int a, int b){
    int c;
    c = a +b;
    return c;
}

void test1(){
    int array[4];
    printf("Dia chi test1: %p\n", array);
}

void test2(){
    int 
}

//int array[] ={11, 24, 37, 4};

int main(int argc, char const *agrv[])
{
    int x = 10;
    int y = 20;

    swap(&x,&y);

    printf("x = %d, y = %d\n", x, y);



    int* array = (int *)malloc(sizeof(int)*4);

    for (int i = 0; i < 4; i++)
    {
        array[i] = 3*i
    }
    
    for (int i = 0; i < 4; i++)
    {
        printf("i = ")
    }
    
    return 0;


}