#include<stdio.h>
void bubbleSort(int arr[], int n,int *cntr);
void printUnion(int arr1[], int arr2[], int m, int n,int z,int cntr);
void printIntersection(int arr1[], int arr2[], int m, int n,int cntr);
void difference(int set1[],int set2[],int m, int n,int cntr);
void Cart(int a[],int b[],int m, int n,int cntr);
void compliment(int x[],int y[], int m, int n,int cntr);
void main()
{    
    int a[]={18,23,1,3,4,6,45,},i,s,z=0,cntr=0;
    int b[]={4,9,1,6,7};
    int u[50];
    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(b)/sizeof(b[0]);
    printf(" n=%d \n m=%d",n,m);
    bubbleSort(a,m,&cntr);
    bubbleSort(b,n,&cntr);
    printf("\n ");
   for (i = 0; i<m; i++)      
   {
       printf("%d ",a[i]);
   }
       printf("\n ");
   for (i = 0; i<n; i++)      
   {
       printf("%d ",b[i]); 
   }
   printf("\nUnion");
   printUnion(a,b,m,n,z,cntr);
   printf("\nIntersection");
   printIntersection(a,b,m,n,cntr);
   printf("\nDifference A-B \n ");
   difference(a,b,m,n,cntr);
   printf("\nDifference B-A \n ");
   difference(b,a,n,m,cntr);
   printf("\nCartesian Product");
   Cart(a,b,m,n,cntr);
   printf("\nCompliment U - A = A~");
   compliment(a,b,m,n,cntr);
}
void bubbleSort(int arr[], int n,int *cntr)
{
   int i, j,temp;
   for (i = 0; i < n-1; i++)      
    {
        cntr++;
       for (j = 0; j < n-i-1; j++) 
       {
           cntr++;
           if (arr[j] > arr[j+1])
           {
              temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
              cntr++;
           }
       }
    }
}

void printUnion(int arr1[], int arr2[], int m, int n,int z,int cntr)
{
  int i = 0, j = 0,k=0,u[50];
  printf("\n ");
  while (i < m && j < n)
  {
      cntr++;
    if (arr1[i] < arr2[j])
    {
        u[k]=arr1[i++];
        k++;
    }
    else if (arr2[j] < arr1[i])
    {
        u[k]=arr2[j++];
        k++;
    }
    else
    {
        u[k]=arr2[j++];
        k++;        i++;
    }
  }
  while(i < m)
   {
       cntr++;
       u[k]=arr1[i++];
       k++;
   }
  while(j < n)
   {
       cntr++;
       u[k]=arr2[j++];
       k++;
   }
    printf("\n ");
    if(z!=2)
    {
        for(i=0;i<k;i++)
        {
            cntr++;
            printf("%d ",u[i]);
        }        
        printf("\n Counter Union = %d",cntr);
    }
    else
    {
        difference(u,arr1,k,m,cntr);
    }
}
void printIntersection(int arr1[], int arr2[], int m, int n,int cntr)
{
  int i = 0, j = 0, p[50],c=0;
  while (i < m && j < n)
  {
      cntr++;
    if (arr1[i] < arr2[j])
      i++;
    else if (arr2[j] < arr1[i])
      j++;
    else /* if arr1[i] == arr2[j] */
    {
      p[c]=arr2[j++];
      i++; c++;
    }
  }
  printf("\n ");
    for(i=0;i<c;i++)
    {
        cntr++;
        printf("%d ",p[i]);
    }
        printf("\n Counter Intersection = %d",cntr);
}

void difference(int set1[],int set2[],int m, int n,int cntr)
{  
    int i,j,c=0,flag=0,d[50];
    for(i=0;i<m;i++)
    {
        cntr++;
        flag=0;
        for(j=0;j<n;j++)
        {
            cntr++;
            if(set1[i]==set2[j])
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            d[c]=set1[i];
            printf("%d ",d[c]);
            c++;
        }
    }
    printf("\n Counter = %d",cntr);
}

void Cart(int a[],int b[],int m, int n,int cntr)
{
    int i,j;
    printf("{");
    for(i=0;i<m;i++)
    {
        cntr++;
        for(j=0;j<n;j++)
        {
            cntr++;
            printf("(%d,%d)",a[i],b[j]);
            printf(",");
        }
        printf("\n");
    }
    printf("}");
    printf("\n Counter Cartasian = %d",cntr);
}
void compliment(int x[],int y[], int m, int n,int cntr)
{
    int z=2;
    printUnion(x,y,m,n,z,cntr);
}

