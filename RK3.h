#include <iostream> 
#include <ctime> 
#include <iomanip> 
using namespace std; 
 
void Sort(int* APtr, int length_of_A) 
{ 
for (int i = 0; i < length_of_A; i++) 
{ 
int temp = APtr[0]; 
for (int m = i + 1; m < length_of_A; m++) 
{ 
if (APtr[i] > APtr[m]) 
{ 
temp = APtr[i]; 
APtr[i] = APtr[m]; 
APtr[m] = temp; 
} 
} 
} 
} 
int Search(int *ptr, int left, int right, int key) 
{ 
int rh = 0; 
while (1) 
{ 
rh= (left + right) / 2; 

if (key < ptr[rh]) 
right = rh - 1; 
else if (key > ptr[rh]) 
left = rh + 1; 
else 
return rh; 

if (left > right) 
return -1; 
} 
} 

int main(int arg1, char* arg2[]) 
{ 
	int k;
       cout << "Enter size of array: "; 
       int size_A;  
       cin >> size_A; 
       int *A = new int [size_A]; 
for (int count = 0; count < size_A; count++) 
{ 
   A[count] = rand() % 100; 
   cout << A[count] << " "; 
} 
   cout << endl; 
   Sort(A, size_A); 
   cout <<"Sorted mass"; 
   for (int count = 0; count < size_A; count++) 
{ 
cout << A[count] << " "; 
} 
 
int elem = A[0]; 
for (int count = 1; count < size_A; count++) 
{ 
if ( elem == A[count] )  
k++; 
} 
cout << endl << " elements: " << k << endl; 
cout << endl; 

int key=0; 
int index; 
cout << "\n\n: "; 
cin >> key; 

index = Search(A, 0, size_A, key); 

if (index >= 0) 
cout << "Number index: " << index << "\n\n"; 
else 
cout << "No found"; 
delete [] A; 
system("pause"); 
return 0; 
} 
