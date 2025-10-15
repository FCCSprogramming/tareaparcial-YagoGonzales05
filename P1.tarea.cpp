#include <iostream>
#include <iomanip>
using namespace std;
 float Promedio(int arr[],int l,int *n){
     float S=0, resultado;
     for(int i=0;i<l;i++){
         S+=*(n+i);
     }
     resultado=S/l;
     return resultado;
 }
 void DiferenciaCentrada(int arr[],int l,int *n,float D[]){
     for(int i=0;i<l;i++){
         if(i==0 || i==l-1){
             D[i]=0.0;
         }else {
              D[i]=(*(n+i+1)-*(n+i-1))/2;
         }
     }
 }




int main()
{
    int med;
     cout<<"Digite el numero de mediciones: ";
    cin>>med;
    int E[100];
    int *ptr=E;
   float D[100];

    cout<<"RELLENAR ARREGLO: "<<endl;
    for(int i=0;i<med;i++){
        cout<<"Ingrese el valor para E["<<i<<"]: ";
        cin>>*(ptr+i);
    }

    cout<<"ARREGLO ORIGINAL: "<<endl;
    for(int i=0;i<med;i++){
        cout<<*(E+i)<<" ";
    }
    cout<<endl;
    Promedio(E,med,ptr);
    cout<<"El promedio de las energias es: "<<fixed<<setprecision(2)<<Promedio(E,med,ptr)<<endl;
    DiferenciaCentrada(E,med,ptr,D);
    cout<<"RESULTADOS: "<<endl;
    cout<<left<<setw(10)<<"Indice"<<setw(20)<<"Energias"<<setw(20)<<"Diferencia centrada"<<endl;
    cout<<string(50,'-')<<endl;
    for(int i=0;i<med;i++){
        cout<<left<<setw(10)<<i<<setw(20)<<*(E+i);
        if(i==0||i==med-1){
            cout<<setw(20)<<"--";
        }
            else{
                cout<<setw(20)<<fixed<<setprecision(2)<<*(D+i);
            }
            cout<<endl;



    }

    return 0;
}
