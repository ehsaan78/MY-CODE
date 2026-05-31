#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*class Student{  
    private: 
            string  name;
            float sgpa;
    public:     
            string adress;
        long long int contact;
        // setter
        void setname(string n){
                name = n;
        }
        // getter 
        string getname(){
                return name;
        }
        void setsgpa(float n){
                sgpa =n;
        }
        float getsgpa(){
                return sgpa;
        }
        };
 int main(){
         Student s1;
        s1.adress= "srinagar";
       cout<<s1.adress<<endl;
        s1.contact=6005472978;
       cout<<s1.contact<<endl;
      s1.setname ("Aehsan ul haq"); // calling setter
      cout<<s1.getname()<<endl;
       s1.setsgpa(9.0);
       cout<<s1.getsgpa()<<endl;
 }
 class student {
private :
      string name;
      int age;
public :
      student(){ // non parameterised constructor
        cout<<"non parameterixed constructor"<<endl;
      }
      student(string nameval,int ageval){// parameterised constructor
        name=nameval;
        age=ageval;
         cout<<name<<endl;
         cout<<age<<endl;
      }

 };
 int main(){
        student s0;
        student s1("aehsan",21);
       
 }
 // practise question

 class User{
    private :
         string id;
         string password;
    public :     
         string username;
     User (string idval){
        id =idval;
        cout<<"id = "<<id<<endl;
     }
     // setter for password
     void setpassword(string passval){
        password=passval;
     }
     // getter for pass
     string getpassword(){
        return password;
     }
};
 
int main(){
        User u1("Aehsan@2581");
       u1.setpassword("Aehsanisgoat");
      cout<<"password = "<< u1.getpassword()<<endl;
      u1.username="EhsAn";
      cout<<"username = "<<u1.username<<endl;


}
// copy constructor deep and shallow copy
class car {
        public : 
         string color;
         string name ;
         int *mileage;
         
       car (string namval , string colval){// parameterised constructor
            name = namval;
            color=colval;
            mileage =new int;
            *mileage=10;
            
       }
     
             car (const car &c1) {
               color = c1.color;
               name = c1.name;
               mileage =new int; // allocates new memory block inside heap
              *mileage=*c1.mileage;// copies the actual value of pointer 

}
};
int main(){
        
        car c1("bmw", "white");
       
        car c2(c1); // copy constructor called
         cout<<*c1.mileage<<endl;
        cout<<c2.color<<endl;
        cout<<c2.name<<endl;
       *c1.mileage=20; // changing the value of mileage of c1
        cout<<*c1.mileage<<endl;
        cout<<*c2.mileage<<endl;
}*/
// inheritance
/*class animal{
        protected:
        string name;
        void eat(){
                cout<<"eat function inherited"<<endl;
        }
};
class cow:public animal{
            public:
          int legs;
          void walks(){
                cout<<"this animal walks"<<endl;
          }
          void display(){
                eat(); // calling the eat function of animal class
          }
          
};
 
int main(){
        cow c1;
        c1.display();
        c1.legs=4;
        cout<< c1.legs<<endl;
        c1.walks();
        return 0;
}
        operator overloading
class complex{
        public:
        int real;
        int imag;
        complex(int r,int c){
                real=r;
                imag=c;
        }
        void shownum(){
                cout<<real<<" + "<<imag<<"i"<<endl;
        }
        complex operator + (complex &c2){
               int result =this->real + c2.real;
               int  imagresult=this-> imag + c2.imag;
               complex c3(result,imagresult);
               return c3;
        }
};
int main(){
     complex c1(1,2);
     complex c2(3,4);
     c1.shownum();
     c2.shownum();
     complex c3=c1+c2;
     c3.shownum();
}
// practice question on operator overloading
class complex{
        public:
        int real ;
        float imag;
      complex (int r, float i){
           real = r;
           imag =i;
}
      void shownum(){
        cout<<real<<" + "<<imag<<"i"<<endl;
      }
  complex operator + (complex &c2){
           int realresult= this->real + c2.real;
           float imagresult=this->imag + c2.imag;
           complex c3(realresult,imagresult);
           return c3;
  }

};
int main(){
        complex c1(2,3.2);
        complex c2(4,5.3);
        c1.shownum();
        c2.shownum();
        complex c3 =c1+c2;
        c3.shownum();
        return 0;
}
//ractice question on operator overloading
class vectars {
        public:
        int real;
        int reel;
        vectars (int i,int j){
                real =i;
                reel =j;
        }
        void shownum(){
                cout<<real<<"i"<<"+"<<"("<<reel<<"j"<<")"<<endl;
        }
        vectars operator - (vectars & v2){
                       int result = this->real - v2.real;
                       int reelresult = this->reel - v2.reel;
                       vectars v3(result,reelresult);
                       return v3;
        }


};
int main (){
        vectars v1(1,1);
        vectars v2(2,3);
        v1.shownum();
        v2.shownum();
        vectars v3 =v1-v2;
        v3.shownum();
}
*/

/*class animal {
        public:
           virtual void speak(){
                cout<<"animal speaks\n";
        }
};
class dog :public animal {//child class
        public:
         void speak(){
                cout<<"dog barks\n";
           }
};
class cat : public animal {
        public:
        void speak (){
                cout<<"cats mmeoww\n";
        }
};
int main (){
        animal * ptr;
        dog d1;
        ptr=&d1;
        ptr->speak();
        animal * ptr2;
        cat c1 ;
        ptr=&c1;
        ptr->speak();
}
//  abstract class 
class shape{
        public:
        virtual  void draw ()=0;// pure virtual function
};
 
class circle : public shape{
        public:
        void draw(){
                cout<<"draw circle\n";
        }
};
class square : public shape{
        public:
        void draw(){
                cout<<"draw square\n";
        }
};
int main(){
        circle c1;
        c1.draw();
        return 0;
}
             // Mini payment gate way project 

class netbanking {           // using netbanking as an abstract class
          public :
          virtual void payment()=0;    // payment as pure virtual func
};
        class upi : public netbanking{
         public :
         void payment (){
                cout<<"payment done through upi\n";
         }
        };
      class creditcard : public netbanking{
         public :
         void payment (){
                cout<<"payment donethrough creditcard\n";
       }
          } ;
     class debitcard : public netbanking{
         public :
         void payment (){
                cout<<"payment done through debitcard\n";
         };

};
int main(){
      netbanking*ptr;
      upi u;
      creditcard c;
      debitcard d;
      ptr=&u;
      ptr->payment();
      ptr=&c;
      ptr=&d;
      ptr->payment();
      ptr=&d;
      ptr->payment();
        return 0;
}
 // static variables in class
 class student {
         public:
       static int count ;
 };
       int student :: count=0; // initialised outside the function
 int main(){
        student s1;
        student s2;
        cout<< s1.count++<<endl;
        cout<< s2.count++<<endl;
        return 0;
 }*/
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