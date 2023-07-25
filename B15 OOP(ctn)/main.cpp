#include <string>
#include <iostream>
#include "test.cpp"


using namespace std;

namespace ConOngA{
    int Teo = 10;
}

namespace ConOngB {
    int Teo = 20;
}


int main(int argc, char const *argv[])
{
    cout<< "Teo con Ong A: "<<ConOngA::Teo<<endl;

    cout<< "Teo Con Ong B "<<ConOngB::Teo<<endl;

    ConOngB::Test;
    return 0;
}
