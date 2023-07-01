#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

uint16_t random_number(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

uint16_t *createArray(uint16_t length){
    uint16_t *ptr = (uint16_t*)malloc(sizeof(uint16_t)*length);
    srand((int)time(0));
    for (uint16_t i = 0; i < length; i++)
    {
        ptr[i] = random_number(1, 10000);
    }
    return ptr; 
}

void sort(uint16_t arr[], uint64_t length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                uint16_t temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool binarySearch(uint16_t arr[], uint16_t length, uint16_t target) {
    uint16_t left = 0;
    uint16_t right = length - 1;

    while (left <= right) {
        uint16_t mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return true; // ID được tìm thấy trong mảng
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false; // ID không tồn tại trong mảng
}

int main(int argc, char const *argv[])
{
   uint16_t *array = createArray(10000);

   sort(array,10000);

   /*for (uint16_t i = 0; i < 10000; i++)
   {
    printf("%d, ", array[i]);
   }*/
   
    uint16_t id;
    printf("Nhap ID: ");
    scanf("%hu", &id);

    bool found = binarySearch(array, 10000, id);

    if (found) {
        printf("ID %d co trong mang.\n", id);
    } else {
        printf("ID %d khong co trong mang.\n", id);
    }
        return 0;
}