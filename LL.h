#include <iostream>
#include "monster.h"

class node{
   public:
   Monster monster;
   node* next;
   node(Monster m): monster(m), next(nullptr){}
};

class LL{
private:
   node* head;
public:
  LL(){
  head=nullptr;
  }

  void insert(Monster m){
  node* new_node=new node(m);
  new_node->next = head;
  head = new_node;
  }

  void swap(node* &a,node* &b){
  node* temp=a;
  a=b;
  b=temp;
  }

  void sortMonsters(){
    if(head==nullptr||head->next==nullptr) return; 
    node* current=head;
    node* prev=nullptr;
    int sorted=0;
    while(!sorted){
      sorted=1;
      current=head;
      prev=nullptr;

      while(current->next!=nullptr){
        if(current->monster.hp>current->next->monster.hp){  
          node* nextNode=current->next;
          current->next=nextNode->next;
          nextNode->next=current;
        if(prev!=nullptr) prev->next=nextNode;
        else head=nextNode;
        prev=nextNode;
        sorted=0;
        }
        else{
          prev=current;
          current=current->next;
        }
      }  
    }
  } 

  node* getHead(){
  return head;
  }

  ~LL(){
    while(head){
      node* temp=head;
      head=head->next;
      delete temp;
    }
  }

};

  



