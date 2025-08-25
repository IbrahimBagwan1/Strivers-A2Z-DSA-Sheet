#include<bits/stdc++.h>
using namespace std;

class ListNode{
  public:
  int val;
  ListNode* next;
  ListNode* prev;

  ListNode(int data1, ListNode* next1=nullptr,  ListNode* prev1=nullptr){
    val = data1;
    next = next1;
    prev = prev1;
  }
};

void insertNode(ListNode* &head, int data){
  if(head == nullptr){
    head = new ListNode(data);
    return ;
  }

  ListNode* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = new ListNode(data, nullptr, temp);
}

void diplay_forward(ListNode* head){
  if(head == NULL) return ;
  ListNode* temp = head;
  cout<<endl;
  while(temp!=NULL){
    cout<<temp->val<<" ";
    temp = temp->next;
  }
}

void display_reverse(ListNode* head){
  if(head == NULL) return ;
  ListNode* temp = head;
  cout<<endl;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  while(temp != head){
    cout<<temp->val<<" ";
    temp = temp->prev;
  }
  cout<<head->val;
}

void delete_node(ListNode* &head, int item){
  if(head == nullptr)return ;
  ListNode* temp = head;
  if(head->val == item){
    head = head->next;
    head->prev= NULL;
    delete(temp);
    return ;
  }

  while(temp->val != item && temp->next!=NULL){
    temp = temp ->next;
  }
  ListNode* previous = temp->prev;
  previous->next = temp->next;
  temp->next->prev = previous;
}

int main(){
  vector<int> v = {3,4,2,1,55,3,2,9};
  ListNode* head=nullptr;
  for(int ele : v){
    insertNode(head,ele);
  }

  diplay_forward(head);
  display_reverse(head);

  delete_node(head, 2);
  display_reverse(head);
  return 0;
}