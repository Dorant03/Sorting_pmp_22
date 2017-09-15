#include <iostream>
#include <ctime>
using namespace std;
void print(int *mass, int n)
{
	for(int i=0; i<n; cout<<mass[i]<<ends,i++);
	cout<<endl;
}

void QuickSort(int *arr, unsigned int N, int L, int R) 
{
	int i = L,
		j = R;
	int m = (R + L) / 2;
	int x = arr[m];
	int w;
	do
	{
		while (arr[i]<x)
		{
			i++;
		}
		while (x < arr[j])
		{
			j--;
		}
		if (i <= j)
		{
			w = arr[i];
			arr[i] = arr[j];
			arr[j] = w;
			i++;
			j--;
		}
	} while (i < j);
	if (L < j)
	{
		QuickSort(arr, N, L, j);
	}
	if (i < R)
	{
		QuickSort(arr, N, i, R);
	}
}

void merge(int *arr, int n)
{
	int mid = n / 2;
	if (n % 2 == 1)
		mid++;
	int h = 1; 
	int *c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;  
		int j = mid; 
		int k = 0;   
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{ 
				if (arr[i] < arr[j])
				{
					c[k] = arr[i];
					i++; k++;
				}
				else {
					c[k] = arr[j];
					j++; k++;
				}
			}
			while (i < step)
			{   
				c[k] = arr[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j<n))
			{  
				c[k] = arr[j];
				j++; k++;
			}
			step = step + h; 
		}
		h = h * 2;
		for (i = 0; i<n; i++)
			arr[i] = c[i];
	}
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
        if(vybir==2){     merge(mass, n);      }
        if(vybir==3){    heapSort(mass, int n)      }
		if(vybir==4){ QuickSort(mass, n, 0, n - 1);  }
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

