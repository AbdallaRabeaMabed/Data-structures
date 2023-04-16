
#include <iostream>

using namespace std;
struct Node{
    int data = 0;
    Node* next = nullptr;
    Node(int D)
    {
        data = D;
    }
};
void print(Node* head)
{
    while(head!= nullptr)
    {
        cout<< head->data << endl;
        head = head->next ;
    }
}
void print2(Node* head)
{
	// print node recursively
    if(head == nullptr)
    {
        cout<< "\n";
        return;
    }
    cout<< head->data << endl;
    print2(head->next);
}
void print_reverse(Node* head)
{
    if(head == nullptr)
    {
        return;
    }
    print_reverse(head->next);
    cout<< head->data << "\n";
}
int main()
{
    Node* node1 = new Node(5);
    Node* node2 = new Node(4);
    Node* node3= new Node(3);
    Node* node4 = new Node(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;
    print(node1);
    cout<< "=======================\n";
    print2(node1);
    cout<< "=======================\n";
    print_reverse(node1);
    
    return 0;
}
