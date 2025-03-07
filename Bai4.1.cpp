// Ta Quoc Tuan 20225110
#include <bits/stdc++.h> 
using namespace std;
struct node { 
    int data; 
    struct node* next;
};
node* makenode (int x){
	node* newnode = new node;
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
// push a new element to the beginning of the list
node* prepend(node* head, int data) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    node* newnode = makenode(data);
    if(head == NULL){
    	head = newnode;
	}
	else{
		newnode->next = head; 
		head = newnode;
	}
	return head;
}

// print the list content on a line
void print(node* head) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    if(head == NULL) return;
    node* temp = head;
    while(temp != NULL){
    	cout<<temp->data<<" ";
    	temp = temp->next;
	}
	cout<<"\n";
}

// return the new head of the reversed list
node* reverse(node* head) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    node* current = head->next;
    node* prev = head;
    prev->next = NULL;
    node* next = NULL;
    while(current != NULL){
    	next = current -> next;
    	current->next = prev ; 
    	prev = current;
    	current = next;
	}
	head = prev;
	return head;
}
  
int main() {
    int n, u;
    cin >> n;
    node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}
// Ta Quoc Tuan 20225110
