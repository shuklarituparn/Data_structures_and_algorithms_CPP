
#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* next;
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    Node* head = NULL;  //Initializing it as NUll to not create any garbage
    Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        char num;
        cout << "Enter element " << i+1 << ": ";
        cin >> num;

        Node* new_node = new Node;  //creating a space on the memory
        new_node->data = num;   //assigning the data num to the data part
        new_node->next = NULL;   //assigning the nullptr to the pointer part

        if (head == NULL) {    //if there's only one element, both head and temp pointing to same
            head = new_node;
            temp = new_node;
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }

    Node* curr=NULL;

    cout << "\nThe linked list is: ";
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    return 0;
}

/*

In this code, we first ask the user to input the number of elements they want in the linked list. Then we declare two pointers: head and temp. 
The head pointer points to the first node in the linked list, and the temp pointer is used to traverse the list and add new nodes.

Next, we use a for loop to iterate n times and add new nodes to the linked list. Inside the loop, we ask the user to input the data value for each new node. 
Then we create a new node dynamically using the new operator and assign the user input as its data value. We also set the next pointer of the new node to NULL.

If the linked list is empty (i.e., the head pointer is NULL), we make the new node the first node in the list and set both the head and temp pointers to point to it. 
Otherwise, we make the new node the next node after the current node that temp is pointing to, and then we move temp to point to the new node.

Finally, we use a while loop to traverse the linked list from the beginning to the end and print out the data values of each node.



*/