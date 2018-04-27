#include<iostream>
#include <string>
using namespace std;
void flag(){
     int x = 123;
     int y = 147;
     int z = 214;
     int sum;
     for(int i; i<1000; i++){
        sum += x*y/z;
     }
     cout << sum << endl;
}
int main(int argc, char *argv[]){
    if( argc != 2 ){
       cout << "Usage: " << argv[0] <<" Flag\n";
    }else{
   char myword[] = {'F','L','A','G','{','H','3','E','1','1','0','_','F','r','1', '8', 'N','d','}', '\0'}; // FLAG{H3E110_Fr18Nd}
        if( string(argv[1]) == myword){
           cout << "Good job, Flag is : ";
           flag();
        }else{
           cout << "Try Harder :)\n";
        }
    }
    return 0;
}


