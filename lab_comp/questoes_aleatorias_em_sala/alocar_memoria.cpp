#include <iostream>
#include <new>
#include <vector>

using namespace std;

class cum{
    int xdd;
    public:
    cum(): xdd(0){}

    int get_xdd(){
        return(xdd);
    }

    void set_xdd(int k){
        xdd=k;
    }

};





int main(){
    cum* xdd=new cum[5];

    int x=xdd[4].get_xdd();
    
    
    cout << x;

    delete[] xdd;



}