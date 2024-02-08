#include <bits/stdc++.h>
using namespace std;
#define ll long long int


// **** Design Linkedlist ****
class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int n){
            val = n;
            next = NULL;
        }
    } *head, *last;
    int n = 0;
    
    int get(int index) {
        if(index >= n) return -1;
        ListNode* temp = head;
        while(index--) temp = temp->next;
        return temp->val;
    }

    // Add
    void addAtHead(int val) {
        n++;
        ListNode* temp = new ListNode(val);
        temp->next = head;
        head = temp;
        if(n == 1) last = head;
    }
    void addAtTail(int val) {
        n++;
        ListNode* temp = new ListNode(val);
        if(n == 1){
            head = temp;
            last = head;
            return;
        }
        last->next = temp;
        last = temp;
    }
    void addAtIndex(int index, int val) {
        if(index > n) return;
        if(index == 0){
            addAtHead(val);
            return;
        }
        else if(index == n){
            addAtTail(val);
            return;
        }
        n++;
        ListNode* temp = head;
        ListNode* node = new ListNode(val);
        while(--index) temp = temp->next;
        node->next = temp->next;
        temp->next = node;
    }

    // Delete
    void deleteAtHead(ListNode *&head){
        if(!head) return;
        n--;
        ListNode* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    void deleteAtIndex(int index) {
        if(index >= n) return;
        if(index == 0){
            deleteAtHead(head);
            return;
        }
        n--;
        ListNode *temp = head, *toDelete;
        while(--index) temp = temp->next;
        if(temp->next && !temp->next->next) last = temp;
        toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Useful
    int size(){
        return n;
    }
    void display(ListNode *&head){
        ListNode *temp = head;
        while(temp){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    bool search(ListNode *&head, int key){
        ListNode *temp = head;
        while(temp){
            if(temp->val == key) return 1;
            temp = temp->next;
        }
        return 0;
    }
    ListNode *reverse(ListNode *&head){
        ListNode *prevptr = NULL, *currptr = head;
        while(currptr){
            ListNode *nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr;
    }
};


// **** Create a linkedlist node ****
class ListNode{
public:
    int val;
    ListNode *next; // next = pointer of ListNode type
    ListNode(int n){ // ListNode will take n
        val = n;
        next = NULL;
    }
};


// **** Insert a node at tail ****
void insertAtTail(ListNode* &head, int val){
    ListNode* n = new ListNode(val); // n = address of val
    if(head == NULL){ // no node in the linkedlist
        head = n; // n = address of first node
        return;
    }
    ListNode* temp = head; // temp = iterator. temp = address of head
    while(temp->next != NULL){ // looping to point iterator at tail
        temp = temp->next; // temp->next means temp is pointing at the address of next node
    }
    temp->next = n; // tail's pointer is now pointing at n
}


// **** Insert a node at head ****
void insertAtHead(ListNode* &head, int val){
    ListNode *n = new ListNode(val); // n = address of val
    n->next = head; // n's pointer is now pointing at head
    head = n; // n is now head
    return;
}


// **** display linkedlist ****
void display(ListNode* head){
    ListNode* temp = head; // iterator pointing at head
    while(temp){ // traversing
        cout<<temp->val<<"->"; // printing data
        temp = temp->next; // update iterator
    }
    cout<<"NULL"<<endl;
    return;
}


// **** search an element ****
bool search(ListNode* head, int key){
    ListNode* temp = head; // iterator
    while(temp){
        if(temp->val == key){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}


// **** Deletion of head ****
void deleteAtHead(ListNode* &head){
    ListNode* toDelete = head;
    head = head->next;
    delete toDelete;
}


// **** Deletion of node ****
void deletion(ListNode* &head, int n){
    if(head == NULL){ // if linkedlist is empty
        return;
    }
    if(head->next == NULL){ // if only one node is present
        deleteAtHead(head);
        return;
    }
    ListNode* temp = head;
    while(temp->next->val != n){
        temp = temp->next;
    }
    // temp now has the address of (n)th node
    ListNode* toDelete = temp->next; // toDelete has the address of the node to delete
    temp->next = temp->next->next; // temp now has the address of (n+1)th node
    delete toDelete; // delete (n)th node
    return;
}



// **** Reverse a linkedlist ****
// 1. Iterative
ListNode* reverseIterative(ListNode* &head){ // returning new head

    // NULL 1 2 3 4 NULL
    // p    c n
    ListNode* prevptr = NULL; // prevptr = NULL
    ListNode* currptr = head; // currptr = 1

    while(currptr != NULL){
        ListNode* nextptr = currptr->next; // nextptr = 2
        currptr->next = prevptr; // 1 -> NULL

        prevptr = currptr; // prevptr = 1
        currptr = nextptr; // currptr = 2
    }
    return prevptr; // new head
}

// 2. Recursive
ListNode* reverseRecursive(ListNode* &head){ // returning new head
    if(head == NULL || head->next == NULL){
        return head;
    }
    // NULL 1 2 3 4 NULL
    // h.n  h 
    ListNode* newHead = reverseRecursive(head->next); // backtracking
    head->next->next = head; // 
    head->next = NULL;
    return newHead;
}


// **** Reverse K Nodes in a linkedlist **** (Didn't understand)
ListNode* reverseK(ListNode* &head, int k){ // returning new head
    ListNode* prevptr = NULL;
    ListNode* currptr = head;
    ListNode* nextptr;
    // first k nodes
    int count = 0;
    while(currptr != NULL && count < k){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    // recursion for the rest
    if(nextptr != NULL){
        head->next = reverseK(nextptr, k);
    }
    return prevptr;
}


int main(){
    ListNode* head = NULL; // creating an empty linkedlist

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAtHead(head, 4);
    insertAtHead(head, 7);
    insertAtHead(head, 9);
    display(head);

    cout<<search(head, 5)<<endl; // 5 is not present
    cout<<search(head, 3)<<endl; // 3 is present

    deletion(head, 1); // delete 1
    display(head);

    deleteAtHead(head); // delete head i.e 4
    display(head);

    deletion(head, 3); // delete 3
    display(head);

    deleteAtHead(head); // delete head i.e 2
    display(head);

    display(reverseIterative(head));

    int k = 2;
    ListNode* newhead = reverseK(head, k);
    display(newhead);


    return 0;
}