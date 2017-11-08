#include<iostream>
#include<cstring>
using namespace std;

struct node{
 int number;
 node *next;
};

bool IsEmpty( node *head);
char menu();
void insertAsFirstElement (node *&head, node *&last, int number );
void insert (node *&head, node *&last, int number);
void remove (node *&head, node *&last);
void showList (node*current);

bool isEmpty( node *head){
  if (head == nullptr)
      return true;
  else
      return false;
}
char menu(){
 char choice;
 cout << "menu" << endl;
 cout << "1. Add an item" << endl;
 cout << "2. Remove an item" << endl;
 cout << "3. Show the list" << endl;
 cout << "4. Exit" << endl;
 cin >> choice;
 return choice;
}
void insertAsFirstElement (node *&head, node *&last, int number ){
 node *temp = new node;
 temp -> number = number;
 temp -> next = nullptr;
 head = temp;
 last = temp;
}
void insert (node *&head, node *&last, int number){
 if( isEmpty(head) )
    insertAsFirstElement(head, last, number);
 else {
    node *temp = new node;
 temp -> number = number;
    temp -> next = nullptr;
    last->next = temp;
    last = temp;
 }

}
void remove (node *&head, node *&last){
 if (isEmpty(head))
      cout << "The list is ready empty" << endl;
 else if ( head == last){
      delete head;
      head == nullptr;
      last == nullptr;
      }
 else {
    node *temp = head;
    head = head ->next;
    delete temp;
 }
}
void showList (node*current){
 if(isEmpty(current))
  cout << "the list is empty" << endl;
 else{
   cout << "the list contains" << endl;
   while(current !=nullptr){
    cout << current->number << endl;
    current = current -> next;
}
}
}
int main(){
 node *head = nullptr;
 node *last = nullptr;
 char choice;
 int number;
 do {
   choice = menu();
    switch(choice){
   case '1': cout << "please enter a number :";
             cin >> number ;
             insert (head,last,number);
             break;
   case '2': remove(head,last);
             break;
 case '3': showList(head);
             break;
   default: cout << "system exit" << endl;
    }
   }while (choice != '4');
 }
