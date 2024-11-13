#include<stdio.h> 
#include<stdlib.h> 
 
int *w, *p, *item; //declaring required arrays 
float *r; //array of profit / unit weight per item 
 
void sort(int n)  // Bubblesort Module 
{ 
 int i, j; 
 for(i=n-1; i>=0; i--) 
 { int f=0; //flag variable 
  for(j=0; j<i; j++) 
   if(r[j]<r[j+1]) //descending order of ratios 
   { //swapping elements 
    f=1; //updating flag 
    float tmp; 
    //r[] 
    tmp = r[j]; 
    r[j] = r[j+1]; 
    r[j+1] = tmp; 
    //w[] 
    tmp = w[j]; 
    w[j] = w[j+1]; 
    w[j+1] = tmp; 
    //p[] 
    tmp = p[j]; 
    p[j] = p[j+1]; 
    p[j+1] = tmp; 
    //item[] 
    tmp = item[j]; 
    item[j] = item[j+1]; 
    item[j+1] = tmp; 
   } 
 
  if (f==0) //array is already sorted, hence no swaps take place 
   return; //sorting hence complete 
 } 
} 
 
//greedy module  
void greedy(int n, int m) 
{ 
 sort(n);//Sorting the items using bubble sort 
 float x; //proportion of item to be in knapsack 
 int u=m, profit=0, i; //capacity left in knapsnack and profit 
 for (i=0; i<n; i++) 
 { 
  if(w[i] > u) 
   break; // knapsack exhausted 
 
  x=1.0;  //the entirity of the item can be stored in knapsack 
  u -= w[i]; //updating capacity left 
  profit += p[i]; //adding profit 
 } 
 
 if (i<n) //item present as a fraction 
 { 
  x=(float)(u)/w[i]; 
  profit += p[i]*x; //adding fractional profit 
 } 
 
 // Printing Profit 
 printf("\nTotal Profit= %d", profit); 
} 
 
// main module 
int main() 
{ 
 int n, m, i; 
 printf("Enter Knapsack capacity: "); 
 scanf("%d", &m); 
 printf("Enter no. of items: "); 
 scanf("%d", &n); 
 
 item=(int*)malloc(sizeof(int)*n); //item list 
 w=(int*)malloc(sizeof(int)*n); //matrix for weight 
 p=(int*)malloc(sizeof(int)*n); //matrix for profit 
 r=(float*)malloc(sizeof(float)*n); //matrix for profitability 
 
 //taking input 
 printf("Enter total profit and weight for the items\n"); 
 for (i=0; i<n; i++) 
 { item[i]=i+1; 
  printf("I%d\n", i+1); 
  printf("Weight: "); 
  scanf("%d", &w[i]); 
  while (w[i] <= 0) 
  { printf("Can not be zero"); 
   scanf("%d", &w[i]); 
  }   
  printf("Cost: "); 
  scanf("%d", &p[i]); 
  r[i] = (float)(p[i])/w[i];  //calculating ratio 
 } 
 
 //calling greedy module 
 greedy(n, m); 
 
 return 0; 
}
