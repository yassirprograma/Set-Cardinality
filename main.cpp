#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int tam; //cantidad de numeros aleatorios
int bucket[12]; //este arreglo nos permite llevar a cabo el ordenamiento por bucketsort

int conjuntoconrepetidos[102]; //guardara todos los numeros aleatorios generados
int conjuntoabsoluto[102]; // guardará los numeros sin repetir

int posabsoluto=1; // cantidad de numeros distintos
int aleatorio; //guardará el valor aleatorio
int rango; // hace que el rango sea aleatorio de numeros del 1 al 10

void ordenamientocubeta(){
/* revisa en orden ascendente cuantos elementos hay de cada numero
    y solo toma en cuenta uno, que lo manda a un arreglo absoluto
*/
    for(int i=0;i<=10;i++){
            if(bucket[i]>=1){
                conjuntoabsoluto[posabsoluto]=i;
                posabsoluto++;
            }
    }
}
void imprime(int arr[], int tamanyo){
    for(int j=1;j<=tamanyo;j++){
        cout<<arr[j]<<",";
    }

}
int main()
{
    puts("Escribe cuantos elementos aleatorios desea generar");
    cin>>tam;
    srand (time(NULL)); //inicializa seed
    rango=rand()%10+1; //genera un rango aleatorio entre 1 y 10

    for(int i=1;i<=tam;i++){
            aleatorio=rand()%rango+0; //genera un numero aleatorio en un rango aleatorio
            conjuntoconrepetidos[i]=aleatorio; //manda el valor aleatorio actual a un arreglo
            bucket[aleatorio]+=1; //se va al arreglo bucet en la posicion "aleatorio" y escribe cuantos elementos hay de ese numero
    }
    ordenamientocubeta(); //ordena los numeros y deja un solo elemento de cada numero
    cout<<"El conjunto aleatorio es: {";
    imprime(conjuntoconrepetidos,tam); cout<<"}"<<endl;  //imprime el conjunto original

    cout<<"El conjunto sin repeticiones es: {";
    imprime(conjuntoabsoluto,posabsoluto-1); cout<<"}"<<endl; //imprime el conjunto sin repetir elementos

    cout<<"Cuya cardinalidad es:"<<posabsoluto-1<<endl; //imprimer la cardinalidad

    return 0;
}
