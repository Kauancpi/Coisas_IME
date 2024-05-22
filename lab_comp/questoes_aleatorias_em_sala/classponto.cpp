#include <iostream>
#include <cmath>

using namespace std;

class Ponto3D{
    private:
    float x;
    float y;
    float z;

    public:
    Ponto3D():x(0),y(0),z(0){}
    Ponto3D(float a,float b,float c):x(a),y(b),z(c){}

    void oposto(){
        x=(-1)*x;
        y=(-1)*y;
        z=(-1)*z;
    }

    void visualizar(){
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
        cout << "z=" << z << endl;
    }

    float distancia(Ponto3D p2 = Ponto3D()){
        float d;
        d=sqrt((x-p2.x)*(x-p2.x)+(y-p2.y)*(y-p2.y)+(z-p2.z)*(z-p2.z));
        return(d);
    }

};

int main(){
    Ponto3D ponto1(3,4,0);
    Ponto3D ponto2;
    ponto1.visualizar();
    ponto1.oposto();
    ponto1.visualizar();
    ponto2.visualizar();
    float d;
    d=ponto1.distancia();
    cout << d;

}