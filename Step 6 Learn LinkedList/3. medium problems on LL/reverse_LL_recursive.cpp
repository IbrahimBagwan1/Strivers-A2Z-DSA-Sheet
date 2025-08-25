#include<bits/stdc++.h>
using namespace std;

class ListNode{
  public:
  int val;
  ListNode* next;

  ListNode(int data, ListNode* next1=NULL){
    val = data;
    next = next1;
  }
};

ListNode* reverse_l(ListNode* &head){
  if(head==NULL || head->next==NULL) return head;
  ListNode* temp = reverse_l(head->next);
  ListNode* curr=head->next;
  curr->next = head;
  head->next=NULL;
  return temp;
}

void displayList(ListNode*head){
  ListNode* temp = head;

  while(temp!= nullptr){
    cout<< temp->val<< " ";
    temp = temp->next;
  }
}

int main(){
  ListNode* head=new ListNode(5);
  ListNode* temp = head;
  temp->next = new ListNode(4);
  temp->next->next = new ListNode(3);
  temp->next->next->next = new ListNode(2);
  temp->next->next->next->next = new ListNode(1);

  head=reverse_l(head);
  displayList(head);
  return 0;
}