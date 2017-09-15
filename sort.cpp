#include <iostream>
#include <ctime>
using namespace std;
void print(int *mass, int n)
{
	for(int i=0; i<n; cout<<mass[i]<<ends,i++);
	cout<<endl;
}

int* bubblesort1(int *mas, int m)//В порядку зростання
{
	int c;
	for (int i = 0; i < m - 1; ++i)
	{
		while (mas[i] > mas[i + 1])
		{
			c = mas[i + 1];
			mas[i + 1] = mas[i];
			mas[i] = c;
			--i;
		}
	}
	return mas;
}

void MaxHeapify(int A[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;
    int r = 2*i + 2; 
    if (l < n && A[l] > A[largest])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        swap(A[i], A[largest]);
        MaxHeapify(A, n, largest);
    }
}
  
void BuildMaxHeap(int A[], int n)
{
    int i;
    for (i=(n/2)-1;i>=0;i--)
	{
        MaxHeapify(A, n, i);
    }
}

void heapSort(int A[], int n)
{
    int i;
    BuildMaxHeap(A, n);
    for (i=n-1; i>=0; i--)
    {
        swap(A[0], A[i]);
        int heap_size= i;
        MaxHeapify(A, heap_size, 0);
    }
}

int main()
{
	srand(time(NULL));
	int n, vybir=1; 
	clock_t t;
	double T;
	cout<<"Vybir: "; cin>>vybir;
	while(vybir)
	{   


		if(0<vybir && vybir<4)
		{
        cout<<"n="; cin>>n;
	    int *mass = new int [n];

	    cout<<"Input: "<<endl;
	    //for(int i=0; i<n; cin>>mass[i], i++);
	    for(int i=0; i<n; mass[i]=-10+rand()%1000, i++);
	    //print(mass, n);

		t = clock();
	    if(vybir==1){   bubblesort1(mass, n);      }
        if(vybir==2){           }
        if(vybir==3){    heapSort(mass, int n)      }
		if(vybir==4){   }
		t = clock() - t;
		T=(float)t/ CLOCKS_PER_SEC;
		cout<<"Result:"<<endl;
		//print(mass, n);
		cout<<"Time:  "<<T<<"c"<<endl<<endl;
	    delete [] mass;
		}
		else{  cout<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;                 }
		cout<<"Vybir: ";
		cin>>vybir;
	}
	cout<<"END"<<endl;
}

