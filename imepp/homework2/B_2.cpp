#include <iostream>
#include <set>

using namespace std;


int main(){
    int n,a,b,c;
    int z=0;
    int x=0;
    cin >> n >> a >> b >> c;
    set<int> xdd;

    xdd.insert(a);
    xdd.insert(b);
    xdd.insert(c);

    x=int (xdd.size());

    if(x==1){
        cout << n/(*xdd.begin());
        return(0);
    }
    else if(x==2){
        for(int i=n/(*xdd.begin());i>=0;i--){
            for(int j=n/(*(next(xdd.begin(),1)));j>=0;j--){
                x=(*xdd.begin())*i+*(next(xdd.begin(),1))*j;
                if(x==n&&(i+j)>z){
                    z=i+j;
                }
            }
        }
    }
    else if(x==3){
        for(int i=n/(*xdd.begin());i>=0;i--){
            for(int j=n/(*(next(xdd.begin(),1)));j>=0;j--){
                for(int k=n/(*(next(xdd.begin(),2)));k>=0;k--){
                    x=(*xdd.begin())*i+*(next(xdd.begin(),1))*j+*(next(xdd.begin(),2))*k;
                    if(x==n&&(i+j+k)>z){
                        z=i+j+k;
                    }
                }
            }
        }
    }
    cout << z;
}