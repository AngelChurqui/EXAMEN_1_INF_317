
//churqui Mamani Angel 
// INF 317
//PRIMER EXAMEN
#include "stdio.h"
#include "mpi.h"

int main() {
    MPI_Status status;
    int numero, x, nproceso, tag, next, from, a, b, c;
    a = 1;
    b = 1;
    c = 0;

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &x);
  MPI_Comm_size(MPI_COMM_WORLD, &nproceso);
 
    tag = 201;
    next = (x + 1) % nproceso;
    from = (x + nproceso - 1) % nproceso;

    if (x == 0) {
    printf("Introduce el numero: ");
        scanf("%d", &numero);

        MPI_Send(&c, 1, MPI_INT, next, tag, MPI_COMM_WORLD); 
    }
    do{      
    MPI_Recv(&c, 1, MPI_INT, from, tag, MPI_COMM_WORLD, &status);
        printf("Proceso %d\n", x, c);

         //proceso fibonacci

        if(x == 0) {
            numero = numero - 1;
            a = b;
            b = c;
            c = a + b;
        }

        MPI_Send(&c, 1, MPI_INT, next, tag, MPI_COMM_WORLD); 
    } 

    while(numero > 0);
  
    if (x == 0)
        MPI_Recv(&c, 1, MPI_INT, from, tag, MPI_COMM_WORLD, &status);

    MPI_Finalize;
    return 0;
}