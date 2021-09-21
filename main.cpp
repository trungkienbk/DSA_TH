#include <iostream>
using namespace std;
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
public:
    LLNode* reverseLinkedList(LLNode* head){
        LLNode *cur=head;
        LLNode *next= nullptr;
        LLNode *prev = nullptr;
        while (cur != nullptr){
            next = cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    LLNode* foldLinkedList(LLNode* head){
        int size = 0;
        LLNode *temp=head;
        while(temp!= nullptr){
            size++;
            temp=temp->next;
        }
        int arr[size];
        LLNode *foo=head;
        int k = 0;
        while(k<size){
            arr[k]=foo->val;
            foo=foo->next;
            k++;
        }
        int length = 0;
        length = size %2==0 ? size/2 : size/2 +1 ;
        int llist[length];
        int i = 0;
        int j = size-1;
        int t = length-1;
        while(i<=j){
            if(i==j){
                llist[t]=arr[i];
            } else {
                llist[t]=arr[i]+arr[j];
            }
            i++;
            j--;
            t--;
        }
       // LLNode* newhead = LLNode::createWithIterators(llist, llist + sizeof(llist) / sizeof(int));
        LLNode* newhead;
        return newhead;
    }
    LLNode* rotateLinkedList(LLNode* head, int k){
        int size = 0;
        LLNode *temp=head;
        while(temp!= nullptr){
            size++;
            temp=temp->next;
        }
        if(size == 0 ) return head;
        int t = size - (k%size);
        LLNode *cur = head;
        while (cur->next != nullptr){
            cur=cur->next;
        }
        cur->next=head;
        cur = head;
        for(int i = 0 ; i < t-1; ++i){
            cur=cur->next;
        }
        head=cur->next;
        cur->next= nullptr;
        return head;
    }

};

int main() {
//[9, 5, 7, 5, 0]
 int size = 5;
 int arr[5]={9, 5, 7, 5, 0};
 int length;
 length = size %2==0 ? size/2 : size/2 +1 ;
 int llist[length];
 int i = 0;
 int j = size-1;
 int t = length-1;
    while(i<=j){
        if(i==j){
            llist[t]=arr[i];
        } else {
            llist[t]=arr[i]+arr[j];
        }
        i++;
        j--;
        t--;
    }
    cout<<"llist[] ";
    for(int m = 0 ; m < length ; ++m){
        cout<<llist[m]<<" ";
    }
}
