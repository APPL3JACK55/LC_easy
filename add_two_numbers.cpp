#include <vector>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *result = new ListNode();
    ListNode *resultPtr = result;
    
    //iterate through and add each of the lists until reaching a null ptr of one
    //keep adding if other list has not reached the end 
    //account for carryover on the addition of each index
    while(l1 != nullptr || l2 != nullptr) {
        ListNode *nextNode = new ListNode();
        if(l2 == nullptr){
            //case l1 is longer than l2
            resultPtr->val += l1->val;
            nextNode->val = resultPtr->val/10;
            resultPtr->val = resultPtr->val%10;
            if(!(nextNode->val == 0 && l1->next == nullptr)){
                resultPtr->next = nextNode;
            }
            l1 = l1->next;
        }
        
        else if(l1 == nullptr){
            //case l2 is longer than l1
            resultPtr->val += l2->val;
            nextNode->val = resultPtr->val/10;
            resultPtr->val = resultPtr->val%10;
            if(!(nextNode->val == 0 && l2->next == nullptr)){
                resultPtr->next = nextNode;
            }
            l2 = l2->next;
        }
        else{
            //still adding common length
            resultPtr->val += l1->val+l2->val;
            nextNode->val = resultPtr->val/10;
            resultPtr->val = resultPtr->val%10;
            if(!(nextNode->val == 0 && l2->next == nullptr && l1->next == nullptr)){
                resultPtr->next = nextNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }  
    }
    return result;
}

ListNode* createList(vector<int> arr){
    ListNode* list1 = new ListNode();
    ListNode* currentNode = list1;
    for(int i = 0; i<arr.size(); i++) {
        ListNode* nextNode = new ListNode(arr[i]);
        currentNode->next = nextNode;
        currentNode = currentNode->next;
    }

    return list1->next;
}

int main(){

    vector<int> list1 = {2,4,3};
    vector<int> list2 = {5,6,4};

    ListNode* l1 = createList(list1);
    ListNode* l2 = createList(list2);

    ListNode* result = addTwoNumbers(l1, l2);

    return 0;
}