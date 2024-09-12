#include<stdio.h>//Including the standard input and output header file
#include<time.h>//Including the time.h header file
#include<stdlib.h>//including te stdlib.h header fie
void swapping(int *x, int *y)//The swapping function
{
int temp = *x;
*x = *y;
*y = temp;
}
void heapify(int a[], int n, int i)//the heapify function
{
int max = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && a[left] > a[max])
max = left;
if (right < n && a[right] > a[max])
max = right;
if (max != i)
{
swapping(&a[i], &a[max]);//calling the swapping function
heapify(a, n, max);//calling the heapify function
}
}
void heapSort(int a[], int n)//the heapSort function
{
for (int i = n / 2 - 1; i >= 0; i--)
heapify(a, n, i);//calling the heapify function
for (int i = n - 1; i >= 0; i--)
{
swapping(&a[0], &a[i]);//Calling the swapping function
heapify(a, i, 0);//calling the heapify function
}
}
void display(int a[], int n)//the display function
{
for(int i = 0; i < n; i++)
{
printf("%d\t", a[i]);
}
}
int main()//the main function
{
printf("Enter the number of random numbers to be generated\n");
int limit;
scanf("%d",&limit);//accepting the limit of the array from the user
int a[limit];
clock_t start=clock();//starting the clock function 
for(int i=0;i<limit;i++)
{
a[i]= (rand() %(100 - 0 + 1)) + 0;//generating random integers between 0 and 100
}
printf("\nOriginal array:\n");
//Printing the original array
display(a,limit);
heapSort(a,limit);
printf("\nSorted array:\n");
//Printing the sorted array
display(a,limit);
clock_t end=clock();//clock end time
clock_t timereq;
timereq =(double)(end-start);//calculating the otal time required
printf("\nProcessor time taken :%f\n",(double)timereq);//printing the total processor time required
return 0;
}
