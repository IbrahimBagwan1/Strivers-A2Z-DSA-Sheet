void deleteLL(Node* head, int item){
  Node* temp = head;
  Node* prev = NULL;
  while(temp->next != nullptr){
    if(temp->data == item){
      prev->next = temp->next;
      temp->next = NULL;
    }
    prev = temp;
    temp = temp->next;
  }
}