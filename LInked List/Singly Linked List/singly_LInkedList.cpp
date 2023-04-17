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
   void reverse();
   void delete_last();
   void delete_nth_node(int n);
 
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
void LinkedList :: reverse() {		// O(n) time - O(1) memory
		if (length <= 1)
			return;

		tail = head;
		Node *prv = head;
		head = head->next;
		while (head) {
			// store & reverse link
			Node* next = head->next;
			head->next = prv;

			// move step
			prv = head;
			head = next;
		}
		// Finalize head and tail
		head = prv;
		tail->next = nullptr;
	}
	void LinkedList :: delete_last() {
		if (length <= 1) {
			delete_front();
			return;
		}
		// Get the node before tail: its order is length-1 node
		Node* previous = get_nth(length - 1);

		delete tail;
		tail = previous;
		tail->next = nullptr;
	}
	void LinkedList :: delete_nth_node(int n) {
		if (n < 1 || n > length)
			cout << "Error. No such nth node\n";
		else if (n == 1)
			delete_front();
		else {
			// Connect the node before nth with node after nth
			Node* before_nth = get_nth(n - 1);
			Node* nth = before_nth->next;
			bool is_tail = nth == tail;
			// connect before node with after
			before_nth->next = nth->next;
			if (is_tail)
				tail = before_nth;

			delete nth;
		}
	}
int main()
{

    LinkedList l;
    l.insert_end(5);
    l.insert_end(4);
    l.insert_end(3);
    l.insert_end(2);
    l.print();
    l.delete_nth_node(2);
    l.print();
    


    
    return 0;
}

