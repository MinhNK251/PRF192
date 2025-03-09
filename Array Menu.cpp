#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
int menu ()
{ printf("\none-Dimensional Array of Integers");
  printf("\n1  - Add a value");
  printf("\n2  - Search a value");
  printf("\n3  - Remove the first existence of a value");
  printf("\n4  - Remove all existences of a value");
  printf("\n5  - Print out the array");
  printf("\n6  - Print out the array in ascending order");
  printf("\n7  - Print the array in descending order");
  printf("\n8  - Print out the sum of all values in the array");
  printf("\n9  - Print out the average of all values in the array");
  printf("\n10 - Clear out the array");
  printf("\nOthers - Quit");
  printf("\nSelect: ");
  int choice;
  scanf("%d", &choice);
  return choice;}
int isFull (int*a, int n)
{ return n==MAXN;}
int isEmpty (int *a, int n)
{ return n==0;}
void add (int value, int*a, int*pn)
{ a[*pn] = value ;
  (*pn) ++;}
int search (int x, int *a, int n)
{ int i;
  for (i=0; i<n; i++) 
    if (a[i]==x) 
    return i;
  return -1;}
int removeOne (int pos, int*a, int*pn)
{ if (pos<0||pos>=*pn)
    return 0;
  for(int i=pos; i<*pn-1; i++) 
    a[i]=a[i+1];
  (*pn)--;
  return 1;}
int removeAll (int x, int*a, int*pn)
{ int result=0,i,j;
  for(i=(*pn)-1;i>=0;i--)
    if(a[i]==x)
    { result=1;
      for(j=i;j<(*pn)-1;j++)
      a[j]=a[j+1];
      (*pn)--;}
  return result;}
void printAsc(int*a, int n)
{ int** adds =(int**)calloc(n, sizeof (int*));
  int i,j,*t;
  for(i=0; i<n; i++) 
    adds[i]= &a[i];
  for (i=0;i<n-1; i++)
    for (j=n-1; j>i; j--)
      if (*adds[j]< *adds[j-1])
      { t=adds[j];
        adds[j]=adds[j-1];
        adds[j-1]=t;}
  for (i=0;i<n; i++) 
    printf("%d ", *adds[i]);
  free(adds);}
void printDesc(int*a, int n)
{ int** adds = (int**) calloc (n, sizeof (int*));
  int i, j,*t;
  for(i=0; i<n; i++) 
    adds[i]= &a[i];
  for(i=0;i<n-1; i++)
    for (j=n-1; j>i; j--)
      if (*adds[j]>*adds[j-1])
      { t=adds[j];
        adds[j]=adds[j-1];
		adds[j-1]=t;}
  for (i=0;i<n; i++) 
    printf("%d ", *adds[i]);
  free(adds);}
void print (int*a, int n)
{ int i;
  for (i=0;i<n;i++) 
    printf("%d ",a[i]);}
void printSum (int*a, int n)
{ int i,sum=0;
  for (i=0;i<n;i++)
    sum+=a[i];
  printf("Sum: %d",sum);}
void printAverage (int*a, int n)
{ int i, average=0;
  for (i=0;i<n;i++)
    average+=a[i];
  average/=n;
  printf("Average: %d",average);
}
void clear (int*a, int*pn)
{ for(int i=(*pn)-1;i>=0;i--)
  { a[i]=a[i+1];
    (*pn)--;}
  printf("Array cleared!");
}
int main()
{ int a[MAXN];
  int n=0,value,userChoice;
  do
  { userChoice= menu();
    switch (userChoice)
    { case 1:
      if (isFull(a,n)) printf("\nSorry! The array is full.\n");
      else
	  { printf("Input an added value: ");
        scanf("%d", &value);
        add(value,a,&n);
        printf("Added\n");}
      break;
      case 2:
      if (isEmpty(a,n))
	    printf("\nSorry! The array is empty.\n");
	  else
      { printf("Input the searched value: ");
        scanf("%d", &value);
        int pos=search(value,a,n);
        if(pos<0)
		  printf ("Not found!\n");
        else printf("Postion is found: %d\n",pos);}
      break;
      case 3:
      if (isEmpty(a,n))
	    printf("\nSorry! The array is empty.\n");
      else
      { printf("Input the removed value: ");
        scanf("%d", &value);
        int pos=search(value, a, n);
        if (pos<0)
		  printf ("Not found!\n");
        else
        { removeOne (pos, a, &n);
          printf ("Removed!\n");}}
      break;
      case 4:
      if (isEmpty(a,n))
	    printf("\nSorry! The array is empty.\n");
      else
      { printf ("Input a value that will be remove all: ");
        scanf ("%d", &value);
        if (removeAll(value,a,&n)==0)
		  printf ("Not found!\n");
        else printf ("Removed!\n");}
      break;
      case 5:
      print(a,n);
      printf("\n");
      break;
      case 6:
      printAsc(a,n);
      printf("\n");
      break;
	  case 7:
	  printDesc(a,n);
	  printf("\n");
	  break;
	  case 8:
	  printSum(a,n);
	  printf("\n");
	  break;
	  case 9:
	  printAverage(a,n);
	  printf("\n");
	  break;
	  case 10:
	  clear(a,&n);
	  printf("\n");
	  break;
	  default: printf("\nGoodbye.\n");}}
  while (userChoice>0 && userChoice<11);
  getchar ();
  return 0;}

