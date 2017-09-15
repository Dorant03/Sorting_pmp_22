#include <iostream>
#include <ctime>
using namespace std;
void print(int *mass, int n)
{
	for(int i=0; i<n; cout<<mass[i]<<ends,i++);
	cout<<endl;
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
	    if(vybir==1){           }
        if(vybir==2){           }
        if(vybir==3){          }
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