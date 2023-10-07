//{ Driver Code Starts
//

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        struct Node *neww = new Node(data);
        if(data<=head->data){
            neww->next=head;
            head=neww;
            return head;
        }
        struct Node* prev=head;
        struct Node* curr=head->next;
        while(curr->next!=NULL){
            if(data<=curr->data){
                neww->next=curr;
                prev->next=neww;
                return head;
            }
            curr=curr->next;
            prev=prev->next;
        }
        if(data<=curr->data){
            neww->next=curr;
            prev->next=neww;
            return head;
        }
        else{
            curr->next=neww;
            neww->next=NULL;
            
        }
        return head;
    }
};



//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends