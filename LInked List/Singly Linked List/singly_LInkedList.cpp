#include <iostream>
#include <cassert>
using namespace std;
struct Node{
    int data = 0;
    Node* next = nullptr;
    Node(int D)
    {
        data = D;
    }
};
class LinkedList{
    private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;
    public:
    void print();
    void insert_end(int val);
    Node* get_nth(int n);
    int searh(int val);
    void debug_verify_data_integrity();
    
};
void LinkedList:: print()
{
    // Don't change the head itself
   for(Node* cur = head; cur; cur = cur->next)
   cout<< cur->data << " ";
    cout<< "\n";
}
void LinkedList:: insert_end(int val)
{
    Node* item = new Node(val);
    if(!head)
    head = tail = item;
    else
    {
        tail->next = item;
        tail = item;
        tail->next = nullptr;
    }
    length++;
}
Node* LinkedList::get_nth(int n){
    int cnt = 1;
    for(Node* cur = head; cur; cur = cur->next){
    if(cnt ==n)
    return cur;
    cnt++;
    }
    return nullptr;
    
} 
int LinkedList:: searh(int val)
{
    // we consider it one based LinkedList
    int idx = 1;
    for(Node* cur = head; cur; cur = cur->next)
    {
        if(cur->data == val)
        return idx;
        idx++;
    }
    return -1;
}
int main()
{

    LinkedList l;
    l.insert_end(5);
    l.insert_end(4);
    l.insert_end(3);
    l.insert_end(2);

    l.print();
   cout<< l.get_nth(4) <<endl;
   cout<< l.searh(2);


    
    return 0;
}
