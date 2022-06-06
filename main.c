#include <stdio.h>
#include <stdlib.h>
#define MAX_Libro 5

typedef struct{
    char nombre[30];
    char autor[30];
    int cantidad;
    float precio;

}Libro;

Libro lectura(Libro libro, int i);
void imprimirLibro(Libro libro);
float venderLibros(Libro libros[]);

int main(){

    int eleccion, numVentas=0,i;
    float ventas[30],totalDia;
    Libro libro[MAX_Libro];
    while(eleccion!=5){
        printf("Selecciona un opcion\n");
        printf("1)Leer inventario inicial\n2)Mostrar inventario de existencias\n3)Vender libros\n4)Informe de ventas\n5)Salir\n");
        scanf("%d",&eleccion);


        switch(eleccion){
            case 1:
                printf("Leyendo archivo...\n\n");


                for(i=0;i<MAX_Libro;i++){

                    libro[i]=lectura(libro[i],i);
                    imprimirLibro(libro[i]);
                }


                break;

            case 2:
                printf("Inventario:\n");
                for(i=0;i<MAX_Libro;i++){
                    imprimirLibro(libro[i]);
                }
                break;
            case 3:
                ventas[numVentas]=venderLibros(libro);
                numVentas++;
                break;

            case 4:
                printf("Informe de ventas:\n");
                printf("Numero de ventas:%d\n",numVentas);
                for(i=0;i<numVentas;i++){
                    printf("%d.-Total de la venta: %.2f\n",i+1,ventas[i]);
                    totalDia=totalDia+ventas[i];
                }
                printf("Total de todas las ventas:%.2f\n",totalDia);
                break;


        }
    }

}


Libro lectura(Libro libro, int i){
    FILE *archivo;
    archivo=fopen("Datos.txt","r");
    if (archivo==NULL){
        printf("No se pudo abrir el archivo\n");
    }
    //fgets(libro.nombre,30,archivo);
    int j;
    for (j=-1;j<i;j++){

        fscanf(archivo,"%[^\n,],%[^\n,],%d,%f\n",libro.nombre,libro.autor,&libro.cantidad,&libro.precio);

    }

    return libro;
}

void imprimirLibro(Libro libro){
    printf("Nombre:%s\n",libro.nombre);
    printf("Autor:%s\n",libro.autor);
    printf("Cantidad:%d\n",libro.cantidad);
    printf("Precio:%.2f\n\n",libro.precio);
}

float venderLibros(Libro libros[]){
    int j, seguir, compra;
    float total;
    Libro aux;
    do{


    printf("ID Nombre\tPrecio\n");
    for (j=0;j<MAX_Libro;j++){
        aux=libros[j];
        printf("%d) %s\t%.2f\n", j+1,aux.nombre,aux.precio);
        //imprimirLibro(libros[j]);
    }

    printf("Ingrese el ID del libro que desea comprar:\n");
    scanf("%d",&compra);
    aux=libros[compra-1];
    aux.cantidad--;
    total=total+aux.precio;
    libros[compra-1]=aux;

    printf("Desea comprar algun otro libro?\n");
    printf("1)Si\n2)No\n");
    scanf("%d",&seguir);
    }while (seguir!=2);
    total=total+total*0.10;
    printf("Total a pagar:%.2f\n\n",total);

    return total;
}
