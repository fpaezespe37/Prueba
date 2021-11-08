#include <iostream>

#define size 100
using namespace std;

class HASH {
public:
    Persona tabla[size];
    int elementos;
    double factorcarga;

    HASH(){
        Persona p;
        p.setSexo(2);
        int j;
        for(j=0;j<size;j++) tabla[j] = p;

        elementos = 0;
        factorcarga = 0.0;
    }
};
