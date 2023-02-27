class Solution{

  public:

    Node* mergeTwoLists(Node *a,Node *b){

        if(!a) return b;

        if(!b) return a;

        Node *result;

        if(a->data<=b->data){

            result=a;

            result->next=mergeTwoLists(a->next,b);

        }else{

            result=b;

            result->next=mergeTwoLists(a,b->next);

        }

        return result;

    }

    

    //Function to merge K sorted linked list.

    Node * mergeKLists(Node *arr[], int K)

    {

           if(K==1) return arr[0];

           Node *prev=mergeKLists(arr,K-1);

           arr[K-1]=mergeTwoLists(arr[K-1],prev);

           return arr[K-1];

    }

};