//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
Node* solve(Node* head){
    Node* zero=new Node(-1);
    Node* one=new Node(-1);
    Node* two=new Node(-1);
    Node* newhead=zero;
    Node* initial_one=one;
    Node* initial_two=two;
    Node* curr=head;
    int current_value;
    while(curr!=NULL){
        current_value=curr->data;
        if(current_value==0){
            zero->next=new Node(0);
            zero=zero->next;
        }
        else if(current_value==1){
            one->next=new Node(1);
            one=one->next;
        }
        else{
            two->next=new Node(2);
            two=two->next;
        }
        curr=curr->next;
        
    }
    if(initial_one->next!=NULL){
        
    zero->next=initial_one->next;
    }
    else{
        zero->next=initial_two->next;
        return newhead->next;
    }
    if(initial_two->next!=NULL){
        
    one->next=initial_two->next;
    }
    return newhead->next;
}
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* newhead=new Node(-1);
        newhead->next=solve(head);
        return newhead->next;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends