#include <iostream>

using namespace std;

class Node {
  public:
  int data;
  Node* next;
  Node* head =  NULL;
  Node* curr;
  Node* prev = NULL;

  Node* getNode(){
    Node* newNode = new Node();
    cout << "Enter data for node: \n";
    cin >> newNode->data;
    newNode->next = NULL;

    return newNode;
  }

  Node* createList(){
    int n;
    cout << "Please enter number of elements: \n";
    cin >> n;
    Node* newNode;
    
    for(int i = 0; i < n; i++){
        newNode = getNode();

        if(head == NULL){
          head = newNode;
        }else{
            curr = head;
            while(curr->next != NULL){
              curr = curr->next;
            }
            curr->next = newNode;
        }
    } 

    return head;

  }

  Node* reverseLlist(Node* head){
    curr = head;
    prev = NULL;

    while(curr != NULL){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;

    }
    head = prev;
    return head;
  }

  
};

int main() {
  
  Node node;
  Node* head;
  Node* curr;

  head = node.createList();

  curr = head;

  while(curr->next != NULL){
    cout << curr->data << "->";
    curr = curr->next;
  }
    cout << curr->data << "->NULL\n\n";

    curr = head;
    cout << "Printing my reverse Linked List: \n";
    head = node.reverseLlist(curr);

    curr = head;

    while(curr->next != NULL){
    cout << curr->data << "->";
    curr = curr->next;
  }
    cout << curr->data << "->NULL\n\n";

  return 0;
}