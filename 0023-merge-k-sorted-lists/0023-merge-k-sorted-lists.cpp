/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;

    }
 };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      //min heap
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;

        //process first element 
        for(int i=0;i<lists.size();i++){
            ListNode* listHead=lists[i];
            if(listHead!=NULL){
            pq.push(listHead);
            }

        }
        //for new LL
        ListNode*head=NULL;
        ListNode*tail=NULL;
        while(!pq.empty()){
            ListNode* topNode=pq.top();
            pq.pop();
            //ye frontNode jo nikali h,
            //ye hmari first node m
            if(head==NULL){
            head=topNode;
            tail=topNode;
            if(tail->next!=NULL){
                pq.push(tail->next);
            }
        }
        else{
            //phele ke badd m koi node insert krta h
            tail->next=topNode;
            tail=topNode;
             if(tail->next!=NULL){
                pq.push(tail->next);
            }
        }
    }
    return head;
}
};
