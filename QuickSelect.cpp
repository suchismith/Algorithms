#include <iostream>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
queue<int> vertices;

bool comp(int a, int b) 
{ 
    if(a<b)
    return true;
    return false;
} 
stack<int> finish;

int partition(int* numbers,int low,int high,int pivot)
{
    int pivotelement=numbers[pivot];
    swap(numbers[pivot],numbers[high]);
    int j=low-1;
    for(int i=low;i<=high;i++)
    {
        if(numbers[i]<pivotelement)
        {
            j++;
            swap(numbers[j],numbers[i]);
            
        }
    }
    swap(numbers[j+1],numbers[high]);    
    return j+1;

}

int quickselect(int * numbers,int k,int low,int high)
{

    if(low==high)
        return numbers[high];
    if(low>high)
        return -1;
    int n=high-low+1;
    int pivotindex;
    int res=rand()%n;
    if(res<n-1)
        pivotindex=(res+1+low);
    else
        pivotindex=(res+low);        

    int i=partition(numbers,low,high,pivotindex);
    if(i>0){
    if(i==k)
        return numbers[i];
    else if(i<k)
        quickselect(numbers,k,i+1,high);
    else
        quickselect(numbers,k,low,i-1);


}

}
  
int main() {
 

  int j=1;
   int k;
   
   int n;
   
   cin>>n;
   int numbers[n+1];
   int numberscopy[n+1];
   for(int i=n;i>=1;i--)
   {

      numbers[j++]=i;
   }
   cin>>k;

     clock_t start, end;
     double time_taken;
     
     start = clock();
     cout<<"kth smallest "<<quickselect(numbers,k,1,n)<<"\n";
     end = clock();
     time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
     cout<<"seconds to execute quickselect "<<time_taken<<"\n"; 


    start = clock();
    nth_element(numbers,numbers+k,numbers+n,comp);
    cout<<"nth element returns "<<numbers[k]<<"\n";
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
     cout<<"seconds to execute nth element "<<time_taken<<"\n"; 
  return 0;
}
