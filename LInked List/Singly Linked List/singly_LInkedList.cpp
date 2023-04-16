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
    ~LinkedList()
    {
        while(head)
        {
            Node* cur = head->next;
            delete head;
            head = cur;
        }
    }
    void print();
    void insert_end(int val);
    Node* get_nth(int n);
    int searh(int val);
   void insert_front(int val);
   void delete_front();
   Node* get_nth_back(int n);
   bool  is_same(LinkedList &L2);
 
};
void LinkedList:: print()
{
    // Don't change the head itself
   for(Node* cur = head; cur; cur = cur->next)
   cout<< cur->data << "\n";
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
void LinkedList:: insert_front(int val)
{
    Node* item = new Node(val);
    if(!head)
    head = tail = item;
    else
    {
        item->next = head;
        head = item;
        tail->next = nullptr;
    }
        length++;

}
void LinkedList:: delete_front()
{
    Node* cur = head->next;
    delete head;
    head = cur;
    
}
Node* LinkedList::get_nth_back(int n){
     return get_nth(length - n + 1);
    
} 
bool LinkedList :: is_same(LinkedList &L2)
{
    if(length != L2.length)
    return 0;
    else
    {
    Node* cur2 = L2.head;
    for(Node* cur = head; cur;cur = cur->next)
    {
        if(cur->data != cur2->data)
        return 0;
        cur2 = cur2->next;
    }
    return 1;
    }
}
int main()
{

    LinkedList l;
    l.insert_end(5);
    l.insert_end(4);
    l.insert_end(3);
    l.insert_end(2);
 LinkedList l2;
    l2.insert_end(5);
    l2.insert_end(4);
    l2.insert_end(7);
    l2.insert_end(2);
   cout<< l.is_same(l2) <<endl;
    


    
    return 0;
}
