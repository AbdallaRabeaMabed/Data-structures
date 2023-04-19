
#include <iostream>

using namespace std;
struct Node{
    int data = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int d)
    {
       this-> data = d;
    }
    void set(Node* n, Node*p)
    {
        this->next = n;
        this->prev = p;
    }
};
class Douply_LinkedList{
   private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int len = 0;
    public:
    void print_reverse()
    {
        for(Node* cur = tail; cur; cur = cur->prev)
        cout<< cur->data << " ";
        cout<< "\n";
        
    }
     void print()
    {
        for(Node* cur = head; cur; cur = cur->next)
        cout<< cur->data << " ";
        cout<< "\n";
        
    }
    void link(Node* first, Node* second)
    {
        if(first)
        first->next = second;
        if(second)
        second->prev = first;
    }
    void insert_front(int val)
    {
        Node* item = new Node(val);
        if(!head)
        tail = head = item;
        else
        {
            link(item,head);
            head = item;
        }
        len++;
        
    }
     void insert_end(int val)
    {
        Node* item = new Node(val);
        if(!head)
        tail = head = item;
        else
        {
            link(tail,item);
            tail = item;
        }
        len++;
    }
    void emped_after(Node* node_before,int val)
    {
        Node* middle = new Node(val);
        len++;
        Node* node_after = node_before->next;
        link(node_before,middle);
       link(middle,node_after);

    }
    void insert_sorted(int val)
    {
        if(!len || val <= head->data)
        insert_front(val);
        else if(tail->data <= val)
        insert_end(val);
        else
        {
            for(Node*cur = head; cur; cur = cur->next)
            {
                if(val <= cur->data)
                {
                    emped_after(cur->prev,val);
                    len++;
                    break;
                }
            }
        }
    }
    void delete_front(){
        if(!head)
        return;
        Node* cur = head->next;
        delete head;
        head = cur;
        cur->prev = nullptr;
        len--;
    }
     void delete_end(){
        if(!head)
        return;
        Node* cur = tail->prev;
        delete tail;
        tail = cur;
        tail->next = nullptr;
        len--;
    }
    Node* delete_and_link(Node* cur)
    {
        Node* ret = cur->prev;
        link(cur->prev,cur->next);
        delete cur;
        return ret;
    }
    void delete_node_with_key(int val)
    {
        if(!len)
        return;
        if(head->data == val)
        delete_front();
        else
        {
            for(Node* cur = head; cur; cur = cur->next)
            {
                if(cur->data == val)
                {
                    cur = delete_and_link(cur);
                    if(!cur->next)
                    tail = cur;
                    break;
                }
            }
        }
    }
};
int main()
{
    cout<<"Hello World"<<endl;
    Douply_LinkedList d;
    d.insert_end(5);
    d.insert_end(4);
    d.insert_end(3);
    d.insert_end(2);
    d.insert_end(1);
    d.delete_node_with_key(3);
    d.print_reverse();
    d.print();

    return 0;
}
