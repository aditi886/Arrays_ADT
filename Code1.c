#include<stdio.h>
#include<stdlib.h>
struct array 
{ 
    int A[10];
    int size;
    int length;
};

int Tail_RecursiveBinSearch(int a[],int l,int h, int key)
{  
    int mid;
    if(l<=h)
    {   
         mid=(l+h)/2;
        if(key==a[mid])
         return mid;
        else if(key<a[mid])
        return  Tail_RecursiveBinSearch(a,l,mid-1,key);
        else 
        return  Tail_RecursiveBinSearch(a,mid+1,h,key);
        
    }
    return -1;
}

int BinarySearch(struct array arr,int key)
{  
    int l,mid,h;
    l=0;
    h=arr.length;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
         return mid;
    
        else if(key<arr.A[mid])
    
            h=mid-1;
        
        else
        
            l=mid+1;
        
    }
    return -1;
}

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int LinearSearch(struct array *arr, int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
          swap(&arr->A[i],&arr->A[i-1]);  //transposition method to reduce the time   
          //swap(&arr->A[i],&arr->A[0]);    //move to front / head method to reduce time 
        return i;//return the loation of that key
        }
    }
    return -1;
}
int delete(struct array *arr,int index)
{
    if(index>=0 && index<arr->length)//check validation of index
    {    
        int x=arr->A[index];     //put the deletion value in the container x 
        for(int i=index; i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
            arr->length--;
        }
       return x;
    }
    return 0;
}
int insert(struct array *arr,int index,int x)
{  
    if(index>=0 && index<=arr->length-1 && arr->length < arr->size)
    {
        for(int i=arr->length ; i>= index   ; i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
        return x;
    }
    return 0;
}
void append(struct array *arr,int x)
{  
    if(arr->length<arr->size)
    {
        arr->A[arr->length++]=x;
    }
}
void display(struct array arr)
{
    
  for(int i=0;i<arr.length;i++)
  {
      printf("%d",arr.A[i]);
  }
    
}
int get(struct array arr,int index)
{
    if(index>=0 && index< arr.length)
    {
        return arr.A[index];
    }
    return -1;
}
int set(struct array *arr, int index, int x)
{
    if(index>=0 && index< arr->length)
    {
         arr->A[index]=x;
    }
    
}
int Max(struct array arr)
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        
            max=arr.A[i];
        
    }
    return max;
    
}
int Min(struct array arr)
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        {
            arr.A[i]=min;
        }
    }
    return min;
}
int Sum(struct array arr)
{
    int s=0;
    for(int i=0;i<arr.length;i++)
    {
        s=s+arr.A[i];
    }
    return s;
}
 float avg(struct array arr)
{
    return (float)Sum(arr)/arr.length;
}
void reverse(struct array *arr)
{
    
    int *B;      //auxillary array
    int i,j;
    B=(int *)malloc(arr->length * sizeof(int));            //A=i B=j A se B me copy karna 
    for(i=arr->length-1, j=0; i>=0;i--,j++)
      B[j]=arr->A[i];
    
    for(i=0;i<arr->length;i++)
  
        arr->A[i]=B[i];

}
void reverse2(struct array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;j--,i++)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

int main()
{    
    struct array arr={{1,2,3,4,5},10,5};
   // reverse(&arr);
       reverse2(&arr);
    //printf("%d\n",get(arr,4));
    
    //set(&arr,0,15);
    
   // printf("%d\n",Max(arr));
   
    //  printf("%d\n",Min(arr));
    
  //  printf("%d\n",Sum(arr));
  
   // printf("%f\n",avg(arr));
    
    
    //printf("%d\n",BinarySearch(arr,2));
    
   // printf("%d\n",Tail_RecursiveBinSearch(arr.A,0,arr.length,5));
    
   // printf("value to be searched %d\n",LinearSearch(&arr,3));
    
   // append(&arr,6);
    
    //insert(&arr,3,7);
    
    display(arr);
    
    //printf("\n");
    
    //printf("the deleted value is %d\n",delete(&arr,1));
    
    
    return 0;
}
