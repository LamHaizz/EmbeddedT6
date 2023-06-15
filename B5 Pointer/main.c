#include<stdio.h>

void tong(int a, int b){
    printf("Tong %d va %d = %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("Hieu %d va %d = %d\n", a, b, a-b);
}

void tich(int a, int b){
    printf("Tich %d va %d = %d\n", a, b, a*b);
}

double thuong(int a , int b){
    return (double) a/b;
}

void toanhoc(void(*ptr)(int,int), int a ,int b){
    printf("Chuong trinh tinh toan\n");
    ptr(a,b);
}

int main ( int argc, char const argv[])
{
    double d = 10.3;

    char string[] = "Hello";

    void *array[] = {&toanhoc, &d, string}; // void **array = void* array[]

     // Ép kiểu con trỏ hàm từ mảng array

     void (*ptr)(int, int) = (void (*)(int, int))array[0];

     ptr = &tong;

     ptr(7,8);

     ptr = &hieu;

     ptr(24,7);

     ptr = &tich;

     ptr(15,2);
     

    return 0;
}