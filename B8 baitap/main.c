#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
//so sanh 2 chuoi
// char arr1[] = "Hello"; char arr2[] = "This is test";

typedef enum{
    SMALLER,
    BIGGER,
    EQUAL
}Compare;

Compare compareString(const char arr1[], const char arr2[] ){
  for (int i = 0; arr1[i] != '\0' || arr2[i]; i++ ){
    if ((arr1[i] - arr2[i]) > 0){
        return BIGGER;
    } else if ((arr1[i] - arr2[i]) < 0){
      return SMALLER;
    } else {
      return EQUAL;
    }
    
  }

}

int main(int argc, char const *argv[])
{
    char arr1[] = "Hello";
    char arr2[] = "test";
    Compare result = compareString(arr1, arr2);

    switch (result)
    {
    case SMALLER:
      printf("array 1 is less than array 2.\n");
      break;
    case BIGGER:
      printf("array 1 is greater than array 2.\n");
      break;
    default:
      printf("Two array are equal.\n");
      break;
    }
    return 0;
}
