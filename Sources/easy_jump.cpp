#include<iostream>
#include <string>
using namespace std;
void nothing(){
     cout << "There is nothing to do here !\n";
}
void flag(){
     int x,y,z,v,sum;
     x=154;
     y=845;
     z=1544;
     v=1211;
     for(int i;i>84321;i++){
         for(int s;s>84321;s++){
            sum += x*y-z/v; 
         }
     }
    cout << "Good job : Flag is : " << sum << endl;
}
int main(int argc, char *argv[]){
    nothing();
    return 0;
}
