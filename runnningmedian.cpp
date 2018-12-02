#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
using namespace std;



class MinHeap{


       
    public:
        int arr[1000000];
        int size=0;


        void Heapify(int index)
        {

            int left=2*index+1;
            int right=2*index+2;

            int minimum=index;
            if( left<size && arr[left] <arr[index])
                minimum=left;
            else
                minimum=index;
            if(right<size && arr[minimum]>arr[right])
                minimum=right;
            int temp=0;
         
         if(minimum!=index){
            temp=arr[index];
            arr[index]=arr[minimum];
            arr[minimum]=temp;
            Heapify(minimum);
        }

            




        }    

        void insert(int key)
        {



            size=size+1;
            arr[size-1]=key;
            int i=size-1;
           
            while(i>0 && arr[(i-1)/2]>arr[i])
            {
                int temp=arr[(i-1)/2];
                arr[(i-1)/2]=arr[i];
                arr[i]=temp;
                 i=(i-1)/2;


            }

      
        }   
       
        int extractMin()
        {      
            int min=arr[0];
            if(size==1){
                size-=1;
                return min;
            }
            else{
            int temp=arr[size-1];
            arr[size-1]=arr[0];
            arr[0]=temp;
            size=size-1;
            Heapify(0);

            return min;
        }
        }
        int sizeOf()
        {
            return size;
        }

        int fetchMin()
        {
            int min=arr[0];
            return min;
        }






};

class MaxHeap{


       
    public:
        int arr[1000000];
        int size=0;


        void Heapify(int index)
        {

            int left=2*index+1;
            int right=2*index+2;

            int maximum=index;
            if( left<size && arr[left] >arr[index])
                maximum=left;
            else
                maximum=index;
            if(right<size && arr[maximum]<arr[right])
                maximum=right;
            int temp=0;
         
         if(maximum!=index){
            temp=arr[index];
            arr[index]=arr[maximum];
            arr[maximum]=temp;
            Heapify(maximum);
        }

            




        }    
        int sizeOf()
        {
            return size;
        }

        void insert(int key)
        {

            size=size+1;
            arr[size-1]=key;
            int i=size-1;
           
            while(i>0 && arr[(i-1)/2]<arr[i])
            {
                int temp=arr[(i-1)/2];
                arr[(i-1)/2]=arr[i];
                arr[i]=temp;
                 i=(i-1)/2;


            }

      
        }   
       
        int extractMax()
        {      
            int max=arr[0];
            if(size==1){
                size-=1;
                return max;
            }
            else{
            int temp=arr[size-1];
            arr[size-1]=arr[0];
            arr[0]=temp;
           
            size=size-1;
            Heapify(0);

            return max;
        }
        }

        int fetchMax()
        {
            int max=arr[0];
            return max;
        }





};


int checkBalance(MinHeap &minheap,MaxHeap &maxheap)
{

    if(minheap.sizeOf()==maxheap.sizeOf() )
        return 1;
    else if(abs(minheap.sizeOf()-maxheap.sizeOf())==1)
        return 2;
    else
        return 0;

}


void addToHeap(int num,MinHeap &minheap,MaxHeap &maxheap)
{

      
    
                
                if(minheap.sizeOf()==0){
                    minheap.insert(num);
                }
                else
                {
                    int min=minheap.fetchMin();
                    if(num<min)
                    {  
                        maxheap.insert(num);
                    }
                    else
                    {
                        
                        minheap.insert(num);

                    }
                    if(!checkBalance(minheap,maxheap))    
                     {

                           if(minheap.sizeOf()>maxheap.sizeOf())
                           {

                            int min=minheap.extractMin();
                            maxheap.insert(min);
                           

                           } 
                           else
                           {
                            int max=maxheap.extractMax();
                            minheap.insert(max);
                              
                           }





                     }             

                    }
                


        



}
long double calculateMedian(MinHeap &minheap,MaxHeap &maxheap)
{
    
    double median=0;
    if(checkBalance(minheap,maxheap)==1)
    {
        int max=maxheap.fetchMax();
        int min=minheap.fetchMin();
        median=(long double)(max+min)/2.0;

    }
    else
    {

        if(minheap.sizeOf()>maxheap.sizeOf())
        {
            median=minheap.fetchMin();


        }
        else
            median=maxheap.fetchMax();

    }

    return median;

}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int arr[1000000];
    int n;
    cin>>n;
    MinHeap minheap;
    MaxHeap maxheap;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++)
    {
        
        addToHeap(arr[i],minheap,maxheap);
        cout<<fixed<<setprecision(1)<<calculateMedian(minheap,maxheap);
        cout<<"\n";
        
        
        
    }
    
    
    
    
    
    return 0;
}
