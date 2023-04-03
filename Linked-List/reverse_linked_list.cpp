#include<iostream>
#include<string>

struct Node{

    char data;
    Node* next;

};

class List{
  private:
    Node *head;
  public:
    List(std::string str);
    void display_linked_list(Node *head);
    Node* reverse_linked_list(Node *head);
    Node* get_head() { return head; }
};

class reversed_linked_list{
    private:
    Node *head;
    public:
    reversed_linked_list(List list);
    void display_linked_list(Node *head);
    Node* get_head(){return head;}


};
void reversed_linked_list::display_linked_list(Node *head){
    Node*ptr= head;
    while (ptr!=nullptr){
        std::cout<<ptr->data;
        ptr=ptr->next;
    }
}

reversed_linked_list::reversed_linked_list(List list){
    Node* current= list.get_head();
    Node *forward= nullptr;
    Node* previous=nullptr;
    while (current!=nullptr)
    {
        forward=current->next;
        current->next=previous;
        previous=current;
        current=forward;
    }
    head=previous;

    
}


void List::display_linked_list(Node *head){
    Node*ptr= head;
    while (ptr!=nullptr){
        std::cout<<ptr->data;
        ptr=ptr->next;
    }
}

List::List(std::string str){
    head = nullptr;
    Node* tail = nullptr;
    for (size_t i = 0; i < str.length(); i++){
        Node* new_node= new Node;
        new_node->data=str[i];
        new_node->next=nullptr;
        if (head==nullptr){
            head=new_node;
            tail=new_node;
        }
        else{
            tail->next=new_node;
            tail=new_node;
        }   
    }
}

int main(){
    std::string str;
    std::getline(std::cin, str);
    List myList{str}; 
    //myList.display_linked_list(myList.get_head()); 
    //Node* reversed_head = myList.reverse_linked_list(myList.get_head());
    reversed_linked_list reversedList {myList};
    reversedList.display_linked_list(reversedList.get_head());



    return 0;
}
