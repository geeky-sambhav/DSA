
#include<iostream>
using namespace std;
int partition(int *a,int s,int e){
    int count=0;
    int pivot=a[s];
    for (int i = s+1; i <= e; i++)
    {
        if(a[i]<pivot){
            count++;
        }
    }
    int pivotindex=s+count;
swap(a[pivotindex],a[s]);

int i=s;
int j=e;
while (i<pivotindex && j>pivotindex){
    while(a[i]<pivot){
        i++;
    }
    while(a[j]>pivot){
        j--;
    }
    if (i<pivotindex && j>pivotindex)
    {
        swap(a[i++],a[j--]);
        /* code */
    }
    
}
}
void quicksort(int *a,int s,int e){
if (s>=e){
    return;
}
int p=partition(a,s,e);
quicksort(a,s,p);
quicksort(a,p+1,e);

    
}

int main(){
  int a[]={5,3,2,6,0,2};
  int n=6;
  quicksort(a,0,n-1);
  for (int i = 0; i < 6; i++)
  {
    cout<<a[i]<<endl;
  }
  


 

return 0;}