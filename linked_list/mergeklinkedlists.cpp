class Solution {
public:
ListNode* mergetwolists(ListNode* one,ListNode* two){
    if (one==NULL){
        return two;
    }
    if(two==NULL){
        return one;
    }
    if(one->val<=two->val){
        one->next=mergetwolists(one->next,two);
        return one;
    }
     if(two->val<=one->val){
        two->next=mergetwolists(one,two->next);
        return two;
    }
    return NULL;
}

ListNode* partitionandMerge(vector<ListNode*>& lists,int start,int end){
if(start>end){
    return NULL;
}
if(start==end){
    return lists[start];
}
int mid=start+(end-start)/2;
ListNode* l1=partitionandMerge(lists,start,mid);
ListNode* l2=partitionandMerge(lists,mid+1,end);
return mergetwolists(l1,l2);
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0){
            return NULL;
        }
        int start=0;

        return partitionandMerge(lists,start,k-1);
    }
};