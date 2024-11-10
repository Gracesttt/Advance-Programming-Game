#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int i) : name(n),score(i) {}
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr),tail(nullptr){}

    void enqueue(string name,int score) {
        Node* newNode=new Node(name,score);
        if(tail==nullptr){
            head=tail=newNode;
        } 
        else{
            tail->next = newNode;
            tail=newNode;
        }
    }

    void print(int x){
        Node* temp=head;
        while (temp!=nullptr){
          cout << "Game: " << temp->name << ", SCORE: " << temp->score << endl;
          temp=temp->next;
        }
    }

    ~Queue(){
        while(head!=nullptr){
            Node* temp=head;
            head= head->next;
            delete temp;
        }
        tail=nullptr;
    }
};