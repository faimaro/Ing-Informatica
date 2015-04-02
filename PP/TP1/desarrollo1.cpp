/*
Franco Aimaro
Programacion por procedimientos
Desarrollo 1.
26/08/13
*/
#include<iostream>
#include<cstdlib>
#include <cstdio>
#include <string.h>
#define T 50
using namespace std;

struct cliente
{
    int dni;
    char matricula[10];
    float importe;
    int provincia;
    int tipo;
};

void cargar(cliente array[T],int&n);
void mostrar(cliente array[T],int n);
void nvo_valor(cliente array[T],int n); //ingresar un valor p..
void buscar(cliente array[T],int n);    //Busqueda de matricula ingresada por teclado
void seg_array(cliente array[T],int n); //segundo vector generado segun las condiciones de la consigna..
void cant_clien_pro(cliente array[T],int n);    // cantidad de cliente por provincia..
void mtz_acum(cliente array[T],int n);


int main()
{
    int op,n=0;
    cliente array[T];
     do
    {

        system("/usr/bin/clear"); //borrar pantalla..
        cout<<"1)Cargar datos.."<<endl;
        cout<<"2)Ver datos.."<<endl;
        cout<<"3)Ver los datos de los clientes del vector que hayan pagado un importe menor a un valor p."<<endl;
        cout<<"4)Buscar patente.."<<endl;
        cout<<"5)Ver un nuevo vector de clientes.."<<endl;
        cout<<"6)Ver la cantidad de clientes que viajaron a las distintas provincias"<<endl;
        cout<<"7)Ver una matriz de acumulacion , en funcion de las provincias y los tipos de automoviles.."<<endl;
        cout<<"8)Salir del sistema.."<<endl;
        cin>>op;
        system("/usr/bin/clear");    //borra pantalla
        //borrar pantalla..
        switch (op)
        {
            case 1:
                cargar(array,n);
                cin.ignore();   //pausa
                cin.get();
                break;
            case 2:
                mostrar(array,n);
                cin.ignore();   //pausa
                cin.get();
                break;
            case 3:
                nvo_valor(array,n);
                cin.ignore();   //pausa
                cin.get();
                break;
            case 4:
                buscar(array,n);
                cin.ignore();   //pausa
                cin.get();
                break;
            case 5:
                seg_array(array,n);
                cin.ignore();   //pausa
                cin.get();
                break;
            case 6:
                cant_clien_pro(array,n);
                cin.ignore();   //pausa
                cin.get();
                break;
            case 7:
                mtz_acum(array,n);
                cin.ignore();   //pausa
                cin.get();
                break;
            case 8:
                break;
        }

    }
    while(op!=8);
    return 0;
}

void cargar(cliente array[T],int&n)
{

    do
    {
        cout<<"Cargue la cantidad de clientes que desea procesar... (0<n<="<<T<<"): "<<endl;
        cin>>n;
        if(n<=0 || n>T)
        {
            cout<<"se pidio n entre 0 y "<<T<<" ...cargue de nuevo.."<<endl;
        }
    }
    while(n<=0 || n>T);

    for (int i=0; i<n; i++)
    {
        cout<<endl<<"Datos del cliente n° "<<i<<": "<<endl<<endl;

        cout<<"Cargue el dni: "<<endl;
        cin>>array[i].dni;
        cout<<"Cargue la matricula (maximo 10 caracteres)"<<endl;
        setbuf( stdin, NULL );
        gets(array[i].matricula);
        cout<<"Cargue el importe: "<<endl;
        cin>>array[i].importe;

        do
        {
            cout<<"Cargue la provincia (decimal de 0 a 22)"<<endl;
            cin>>array[i].provincia;
            if(array[i].provincia<0 || array[i].provincia>=23){cout<<"Argentina tiene 23 provincias.. cargue un dato logico porfavor!.."<<endl;}
        }
        while (array[i].provincia<0 || array[i].provincia>=23);

        do
        {
            cout<<"Cargue el tipo de vehiculo..(decimal de 0 a 5)"<<endl;
            cin>>array[i].tipo;
            if (array[i].tipo<0 || array[i].tipo>5){cout<<"Ingrese de nuevo un tipo en decimal que no exceda 5 ni este por debajo de 0.."<<endl;}
        }
        while (array[i].tipo<0 || array[i].tipo>5);

    }
    cout<<endl<<"Precione enter para volver al menú..";
}
void mostrar(cliente array[T],int n)
{
    if(n != 0){

    cout<<"Datos cargados.."<<endl<<endl;
    for (int i=0;i<n;i++)
    {

        cout<<"Cliente n° "<<i<<" :"<<endl<<endl;
        cout<<"DNI => "<<array[i].dni<<endl;
        cout<<"Matricula => "<<array[i].matricula<<endl;
        cout<<"Importe => "<<array[i].importe<<endl;
        cout<<"Numero de provincia => "<<array[i].provincia<<endl;
        cout<<"Numero de tipo => "<<array[i].tipo<<endl<<endl;
    }
    }
    else cout<<"Cargue primero la cantidad de vehículos que desea procesar.."<<endl<<"Precione enter para volver al menú";
}
void nvo_valor(cliente array[T],int n)
{
    cliente aux;                //primero ordeno el arreglo, en funcion de los numeros dni de cada cliente..
    if(n != 0){
    for (int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((array[j].dni)<(array[i].dni))
            {
                aux=array[j];
                array[j]=array[i];
                array[i]=aux;
            }
        }
    }
                                //muestro en pantalla los clientes que cumplan con las condiciones de la consigna.
    int n_i=0;  //nuevo importe
    cout<<"Ingrese el importe.."<<endl;
    cin>>n_i;
    cout<<"Clientes con importe menor a "<<n_i<<" y que no fueron a las provincias ni 0 ni 1.(Ordenados de menor a mayor numero de dni)"<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        if ((array[i].importe<n_i)&&(array[i].provincia!=0)&&(array[i].provincia!=1)) //condicion de "filtro"
        {
            cout<<"DNI => "<<array[i].dni<<endl;
            cout<<"Matricula => "<<array[i].matricula<<endl;
            cout<<"Importe => "<<array[i].importe<<endl;
            cout<<"Numero de provincia => "<<array[i].provincia<<endl;
            cout<<"Numero de tipo => "<<array[i].tipo<<endl<<endl;
        }
    }
    }
    else cout<<"Cargue primero la cantidad de vehículos que desea procesar.."<<endl<<"Precione enter para volver al menú";
}
void buscar(cliente array[T],int n)
{
    char matri[10];
    if(n != 0){
    cout<<"Busqueda de cliente, ingresando la metricula del vehículo.."<<endl<<endl;
    cout<<"Ingrese la patente que necesita buscar..."<<endl;
    setbuf( stdin, NULL );      //equivale a la funcion fflush(stdin).. limpia el buffer..
    gets(matri);
    //algoritmo de busqueda..
    for(int i=0; i<n; i++)
    {
        if (strcmp(matri,array[i].matricula)==0)
        {
            cout<<"Busqueda exitosa!.."<<endl<<endl;
            cout<<"DNI => "<<array[i].dni<<endl;
            cout<<"Matricula => "<<array[i].matricula<<endl;
            cout<<"Importe => "<<array[i].importe<<endl;
            cout<<"Numero de provincia => "<<array[i].provincia<<endl;
            cout<<"Numero de tipo => "<<array[i].tipo<<endl;
            return;
        }

    }
    cout<<"La matricula que busca, no existe en la base de datos.."<<endl;
    }
    else cout<<"Cargue primero la cantidad de vehículos que desea procesar.."<<endl<<"Precione enter para volver al menú";
}
void seg_array(cliente array[T],int n)
{
    cliente seg_array[T];
    int c=0;
    if(n != 0){
    for (int i=0;i<n;i++)
    {
        if ((array[i].provincia==8)||(array[i].provincia==10)||(array[i].provincia==13))
        {
            seg_array[c]=array[i];      //genero un nuevo vector, pero no paralelo..
            c++;
        }
    }

    cout<<c<<"Clientes viajaron a las provincias 8 , 10 o 13.."<<endl<<endl;
    for (int j=0;j<c;j++)
    {                                   //Muestro en pantalla el nuevo arreglo

        cout<<"Cliente n° "<<j<<" :"<<endl<<endl;
        cout<<"DNI => "<<seg_array[j].dni<<endl;
        cout<<"Matricula => "<<seg_array[j].matricula<<endl;
        cout<<"Importe => "<<seg_array[j].importe<<endl;
        cout<<"Numero de provincia => "<<seg_array[j].provincia<<endl;
        cout<<"Numero de tipo => "<<seg_array[j].tipo<<endl<<endl;
    }
    }
    else cout<<"Cargue primero la cantidad de vehículos que desea procesar.."<<endl<<"Precione enter para volver al menú";
}
void cant_clien_pro(cliente array[T],int n)
{
    if(n != 0){
    int cont[23];
    for(int j=0;j<23;j++)
    {
        cont[j]=0;          //lleno el vector contador con un 0 en cada casillero del mismo.
    }
    for (int i=0;i<n;i++)       //vector de contadores de clientes en cada provincia
    {
        cont[array[i].provincia]++;
    }
    cout<<"Contador de clientes a las distintas provincias.."<<endl<<endl;
    for(int j=0;j<23;j++)
    {                           //muestro en pantalla el contador.
        if(cont[j]!=0)
        {
        cout<<"Provincia n°"<<j<<"=> "<<cont[j]<<" clientes."<<endl;
        }
    }
    }
    else cout<<"Cargue primero la cantidad de vehículos que desea procesar.."<<endl<<"Precione enter para volver al menú";
}
void mtz_acum(cliente array[T],int n)
{
    if(n != 0){
    int mtz_acum[23][5];    //matriz acumulativa , 2 indices de acceso(filas:provincias,columnas:tipo)

    for(int i=0; i<23; i++)
    {
        for(int j=0;j<5;j++)
        {
            mtz_acum[i][j]=0;       //inicializo la acumulacion en cero.
        }
    }
    for(int k=0; k<n;k++)
    {
        mtz_acum[array[k].provincia][array[k].tipo]=mtz_acum[array[k].provincia][array[k].tipo]+array[k].importe;       //acumulo el importe
    }
    cout<<"Acumulacion de importes en funcion del n° de provincia y el tipo de vehiculo.."<<endl<<endl;
    for(int i=0; i<23; i++)
    {
        for(int j=0;j<5;j++)
        {
            if(mtz_acum[i][j]!=0)
            {
                cout<< "El importe acumulado en la provincia n° "<<i<<" con tipo de vehículo n° "<<j<<" es de: $"<<mtz_acum[i][j]<<endl;
            }
        }
    }
    }
    else cout<<"Cargue primero la cantidad de vehículos que desea procesar.."<<endl<<"Precione enter para volver al menú";
}
