#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
                                                        
  
// LINKED LIST IMPLEMENTATION
class node { // creates a single node with given data type and next points to null
    public:
         int data;
         node* next;
         node(int val){ // a constructor for initialisation of node
          data =val;
          next=NULL;
         }
};
class list{  // it links the nodes with each other thus forming the linked list.
    public:
          node* head; // we gotta know the head of the nodes from where we will start
          node* tail;
          list(){ // firstly the ll is empty so head and tail will point to null
            head = NULL;
            tail = NULL;
          }
          void push_front(int val){
            node* newnode=new node(val); // creating new node which returns the adress that is stored inside newnode itself.
            if (head== NULL){
              head = newnode;
            }else{
              newnode->next=head;
              head = newnode;
            }
          
          }
          void insert(int val,int pos){
            node* newnode=new node(val);
               node* temp =head;
            for (int i=0;i<pos-1;i++){
                 temp=temp->next; // it will help us find the adress ofnode at pos -1 
            }
            newnode->next=temp->next;
            temp->next=newnode;
          }
          void pop_front(){
             if(head==NULL){
              return;
             }
             node* temp=head;
             head=head->next;// we updated the head pointer , since head is pointer variable so it can be changed
             temp->next=NULL;
             delete temp;
          }
          void pop_back(){
            node* temp=head ;//backword traversing is not allowed 
             while(temp->next->next!=NULL){
              temp=temp->next; // means we will reach at the position previous to tail
             }
             temp->next=NULL;
             delete tail;
             temp=tail;
          }
         int searchitr(int key){
          node* temp=head;
          int idx=0;
          while(temp!=NULL){
            if(temp->data=key){
              return idx;
            }
            temp=temp->next;
            idx++;
          }
          return -1;
        }
        int helper(node* h,int key){
               if(h==NULL){
                 return -1;
               }
                 if(h->data==key){
                  return 0;
                 }
                 int idx = helper(h->next,key);
                 if(idx==-1){
                  return -1;
                 }
                return idx+ 1;

        }
        int searchrec(int key){
         return helper(head,key);
        }
        void reversell(){
          node* curr=head;
          node* prev=NULL;  // 3 pointer variables
          
           while(curr!=NULL){
            node* nextnode=curr->next;// save it to avoide segmentation fault
              curr->next=prev;
               prev=curr;
               curr=nextnode;
           }
           head=prev;
          
        }
        int sizeofll(){
          int idx=0;
          node* temp=head;
          while(temp!=NULL){
           
           temp=temp->next; 
             idx++;
          }
          return idx;
        }
        void delnthnode(int n){
          node* prev=head;
          int size=sizeofll();
          for(int i=1;i<(size-n);i++){// to find previous node
            prev=prev->next;
          }
          node* del=prev->next; // store 
          prev->next=prev->next->next;// relation established with other node
         delete del; //delete
        }
            
          void printll(){
            node* temp=head;
            while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
            }
            cout<<"NULL"<<endl;;
          }
         
          ~list(){
            node* temp=head;
            while(temp!=NULL){
              node* nextnode=temp->next;
              delete temp;
              temp=nextnode;
            }
          }

};

  int main(){
    list ll;
     ll.push_front(50);
     ll.push_front(40);
     ll.push_front(30);
     ll.push_front(20);
     ll.push_front(10);
      ll.printll();
     ll.delnthnode(2);
      ll.printll();
     ll.pop_front();
     ll.pop_back();
     ll.insert(100,1);
     ll.printll();
     cout<<"idx = "<<ll.searchitr(20)<<endl;   
     cout<<"idx = "<<ll.searchrec(100)<<endl; 
  }

  

    
   