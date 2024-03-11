#include <iostream>
#include <vector>
using namespace std;

int main(){
    int x,y,a,b;
    cin >> x >> y >> a >> b;

    vector<pair<int,int>> xdd;

    for(int i=a;i<=x;i++){
        for(int j=b;j<=y;j++){
            if(i>j){
                xdd.push_back({i,j});
            }   
        }
    }
    cout << xdd.size() << "\n";
    for(const auto &pair :xdd){
        cout << pair.first << " " << pair.second << "\n";
    }

}