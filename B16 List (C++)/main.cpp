#include <iostream>
#include <list>

using namespace std;



int main(int argc, char const *argv[])
{
    list<int> array;

    array.push_back(5);

    array.push_back(3);

    array.push_back(2);

    list<int>::iterator it;

    int i = 0;
    for (it = array.begin();it != array.end(); it++)
    {
        if(i == 1){
            array.insert(it, 27);
        }
        i++;
    }
    

    for (it = array.begin();it != array.end(); it++)
    {
        cout<<*it<<endl;
    }
    
    return 0;
}
