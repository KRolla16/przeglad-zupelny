/*Problem przep³ywowy, implementacja dla przypadku dwóch oraz trzech maszyn,
program zczytuje dane w for macie podanym w instancji ta000. */


#include <iostream>   
#include <algorithm>    
#include <fstream>
using namespace std;

int getcmacx(int M1[], int M2[], int M3[], int n, int myints[], int m)
{
    int cmax = 0;
    int D1 = 0;
    int D2 = 0;
    for(int i=0;i<n;i++)
    {
        D1 = D1+M1[myints[i]-1];
        if(D2<D1)
        D2=D1+M2[myints[i]-1];
        else
        D2 = D2 + M2[myints[i]-1];
        if(cmax<D2)
        cmax = D2+M3[myints[i]-1];
        else
        cmax = cmax + M3[myints[i]-1];
    }
    if(m>2)
    return cmax;
    else
    {
    return D2;
    }
}

int main () {
    int n, k, m;
    k=0;
    ifstream data("data.txt");
    data>>n>>m;
    int M1[n], M2[n], M3[n];
    int myints[n];
    int ilosc=1;
    for(int i = n;i>0;i--)
    ilosc = ilosc*i; 
    int C[ilosc];
    for(int i=0;i<n;i++)
    {
        if(m>2)
        data>>M1[i]>>M2[i]>>M3[i];
        else
        {
        data>>M1[i]>>M2[i];
        M3[i]=0;
        }
        myints[i]=i+1;
        
    }
  do {
    C[k]=getcmacx(M1,M2,M3,n,myints,m);
    for(int i=0;i<n;i++)
    cout << myints[i] <<' ';
    cout << "- " << C[k] << " j"<< endl;
    k++;
    
  } while ( next_permutation(myints,myints+n) );
  return 0;
}