#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// A mini project on friend class involving bank manager and customer class

class bmanager; // forward declaration of bmanager class
class customer{
      int  amount=100000;
     friend class bmanager; // making the bmanager class as friend class of customer class
     public:
     void display2(bmanager &obj); 
};
class bmanager{
    public:  
   void display (customer &obj){
        cout<<"amount : "<<obj.amount<<endl;
      }
   string ipadress="somebody checkecd your account from new device, ip address is = xxyyzz\n";
}; 
void customer::display2(bmanager &obj){

    cout<<"alert : "<<obj.ipadress<<endl;
}
int main(){
    customer c1;
    bmanager b;
   b.display(c1);
    c1.display2(b); 
        return 0;
}