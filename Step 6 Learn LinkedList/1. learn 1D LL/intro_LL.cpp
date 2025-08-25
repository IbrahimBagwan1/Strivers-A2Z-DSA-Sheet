#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node * next;

  Node(int data1, Node*next1=nullptr){
    data = data1;
    next = next1;
  }
};

Node* convertArrToLL( vector<int> v){
  Node* head = new Node(v[0],nullptr);
  Node* temp = head;
  int n = v.size();
  for(int i=1; i<n ;i++){
    Node *a = new Node(v[i], nullptr);
    temp->next = a;
    temp = a; 
  }
  return head;
}

int lengthLL(Node* head){ 
  Node* temp = head;
  int count =0;
  while(temp !=NULL){
    count++;
    temp = temp->next;
  }
  return count;
}

int searchLL(Node* head, int item){
  Node* temp = head;
  while(temp!= NULL){
    if(temp->data == item) return 1;
    temp = temp->next;
  }
  return 0;
}

void deleteLL(Node*& head, int item){
  if(head == nullptr)return ;
  Node* temp = head;
  Node* prev = NULL;

  if(temp->data==item){
    head = head->next;
    temp->next = nullptr;
    delete temp;
    return ;
  }
  while(temp != nullptr){
    if(temp->data == item){
      prev->next = temp->next;
      delete temp;
      return ;
    }
    prev = temp;
    temp = temp->next;
  }
}

void insertLL(Node* &head, int item){
  if(head== nullptr){
    head = new Node(item);
    return ;
  }
  Node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = new Node(item);
}

void displayList(Node*head){
  Node* temp = head;

  while(temp!= nullptr){
    cout<< temp->data<< " ";
    temp = temp->next;
  }
}

int main(){
  Node*y = new Node(3, nullptr);
  cout<< y->data<<endl;
  vector<int> v = {12,3,4,5,6};
  Node* head=convertArrToLL(v);
  
  displayList(head);
  int length_L = lengthLL(head);
  cout<< endl<<searchLL(head, 5);
  deleteLL(head, 5);
  cout<<endl;
  displayList(head);
  
  cout<<endl;
  insertLL(head, 333);
  displayList(head);
  return 0;
}