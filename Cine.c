#include<stdio.h>
struct EntradaCine
{
    char Cliente[100];
    char Pelicula[100];
    char Duracion[20];
    int Puesto;
    char Comida[100];
    float Costo;
};
void LlenarInformacion (struct EntradaCine *InfCliente)
{

       fflush(stdin);
       printf("Ingrese su Nombre y Apellido: ");
       gets(&(*InfCliente).Cliente);
       printf("Pelicula que desea mirar: ");
       fflush(stdin);
       gets(&(*InfCliente).Pelicula);
       printf("Duración de la pelicula: ");
       fflush(stdin);
       gets(&(*InfCliente).Duracion);
       printf("Costo de la Funcion: ");
       fflush(stdin);
       scanf("%f",&(*InfCliente).Costo);
       printf("Puesto que ocupara para la funcion: ");
       fflush(stdin);
       scanf("%i",&(*InfCliente).Puesto);
       printf("Comida que se va a servir: ");
       fflush(stdin);
       gets(&(*InfCliente).Comida);

}
void guardarInfoClienteEnArchivo(FILE *Archivo, struct EntradaCine Cliente)
{
    fprintf(Archivo,"NOMBRE DEL CLIENTE: %s \n", Cliente.Cliente);
    fprintf(Archivo,"PELICULA: %s \n ", Cliente.Pelicula);
    fprintf(Archivo,"DURACIÓN: %s \n", Cliente.Duracion);
    fprintf(Archivo,"COSTO: %.2f \n", Cliente.Costo);
    fprintf(Archivo,"PUESTO DESIGNADO: %i \n", Cliente.Puesto);
    fprintf(Archivo,"COMIDA: %s \n\n", Cliente.Comida);

}
void Imprimirinformacion (struct EntradaCine infCliente)
{
        printf("NOMBRE DEL CLIENTE: %s\n",infCliente.Cliente);
        printf("PELICULA: %s \n",infCliente.Pelicula);
        printf("DURACIÓN: %s \n",infCliente.Duracion);
        printf("COSTO: %.2f \n",infCliente.Costo);
        printf("PUESTO DESIGNADO: %i\n",infCliente.Puesto);
        printf("COMIDA: %s\n",infCliente.Comida);
}
int main()
{
    FILE *ArchivoCine;
    ArchivoCine=fopen("DatosdelCine.txt","wt");
    int N,i;
    printf("Ingrese el numero de clientes que deseen una entrada al Cine: ");
    scanf("%i",&N);
    struct EntradaCine Clientes[N];
    for(i=0;i<N;i++)
    {
        LlenarInformacion(&Clientes[i]);
    }
    for(i=0;i<N;i++)
    {
        guardarInfoClienteEnArchivo(ArchivoCine,Clientes[i]);
    }
    for(i=0;i<N;i++)
    {
        printf("\nLa informacion del cliente es: \n");
        Imprimirinformacion(Clientes[i]);
    }
 return 0;
}
