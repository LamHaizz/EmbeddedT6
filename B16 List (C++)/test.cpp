#include <iostream>
#include <string>
#include <vector>


int main(int argc, char const *argv[])
{
    vector<int> array;

    array.push_back(7);        // thêm phần tử 7

    array.push_back(3);        // thêm phần tử 3

    array.push_back(5);         // thêm phần tử 5
    
    array.push_back(1);         // thêm phần tử 1

    array.insert(array.begin()+1, 35);  //Chèn 1 phần tử 35 vào ví trị thứ 1

    array.pop_back();           // xóa phần tử ở cuối 

    array.erase(array.begin()+1);       // xóa phần tử ở vị trí thứ 1

    array.clear();                  // xóa tất cả

   for (int item : array)
   {
        cout<<item<<endl;
   }
    

    return 0;
}
