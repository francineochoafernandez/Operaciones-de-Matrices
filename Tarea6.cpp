# Operaciones-de-Matrices
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

void ImprimeOp6x6(char op, int matriz1[6][6],int matriz2[6][6],int matrizR[6][6]);
void ImprimeOp3x3(char op, int matriz1[3][3],int matriz2[3][3],int matrizR[3][3]);
void Mult3x3(int matriz1[3][3],int matriz2[3][3], int matrizR[3][3]);
void Mult6x6(int matriz1[6][6],int matriz2[6][6], int matrizR[6][6]);
void ImprimeMat3x3(int matriz[3][3]);
void ImprimeMat6x6(int matriz[6][6]);

int main (void)
{
  int i,j;
  //Ejercicio 1 O(n^2)
  int matriz5[5][5];
  int c=0;
  //Llenando de valores la matriz
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      matriz5[i][j]=c;
      c++;
    }
  }

  //Imprimiendo la diagonal principal
  printf("\nImprimiendo la diagonal principal:\n");
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      if (i!=j)
      {
        printf(" \t");
      }
      else
      {
        printf("%i \t",matriz5[i][j]);
      }
    }
    printf("\n");
  }

  //Ejercicio 2 O(n^2)
  int matriz3[3][3];
  //Leyendo valores
  /*printf("\nDame los valores para una matriz de 3x3 separados por enter: \n");
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      scanf("%i",&matriz3[i][j]);
    }
  }*/

  //Imprimiendo matriz con valores
  ImprimeMat3x3(matriz3);

  int cont=0;
  //Comparando elementos de la matriz
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(matriz3[i][j]!=matriz3[j][i])
      {
        printf("\nLa matriz no es simétrica en la posicíon %i,%i\n",i,j);
        cont++;
      }
    }
  }
  if(cont==0)
  {
    printf("\nLa matriz es simétrica\n");
  }

  //Ejercicio 3
  printf("\nLa suma de dos matrices es:\n");
  int matriz61[6][6], matriz62[6][6], matriz6R[6][6];
  int val1=0, val2=1;
  //Llenando de valores las matrices
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      matriz61[i][j]=val1;
      matriz62[i][j]=val2;
      val1=val1+2;
      val2++;
    }
  }

  //Sumando matrices
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      matriz6R[i][j]=matriz61[i][j]+matriz62[i][j];
    }
  }

  //Imprimiendo
  ImprimeOp6x6('+', matriz61,matriz62,matriz6R);

  //Ejercicio 4
  int matriz6R2[6][6];
  printf("\nLa multiplicación de dos matrices es:\n");

  //Multiplicando matrices
  Mult6x6(matriz61,matriz62,matriz6R2);

  //Imprimiendo matrices
  ImprimeOp6x6('*', matriz61,matriz62,matriz6R2);

  //Ejercicio 5
  int matriz6Tr[6][6];
  printf("\nMatriz Original: \n" );

  //Imprimiendo matriz original
  ImprimeMat6x6(matriz61);

  //Haciendo transpuesta
  for(i=0;i<6;i++)
  {
    for(j=0;j<6;j++)
    {
      matriz6Tr[j][i]=matriz61[i][j];
    }
  }
  printf("\n");

  //Imprimiendo la matriz transpuesta
  printf("Tu matriz transpuesta:\n");
  ImprimeMat6x6(matriz6Tr);

  //Ejercicio 6
  int matrizns1[3][3],matrizns2[3][3],matrizs1[3][3],matrizs2[3][3],matrizRns1[3][3],matrizRns2[3][3],matrizRs1[3][3],matrizRs2[3][3];

  int va1=2, va2=3;
  //Llenando de valores las matrices no simétricas
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      matrizns1[i][j]=va1;
      matrizns2[i][j]=va2;
      va1=va1+3;
      va2++;
    }
  }

  int valo1=1, valo2=2;
  //Llenando de valores las matrices  simétricas
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      matrizs1[i][j]=valo1;
      matrizs2[i][j]=valo2;

      matrizs1[i][j]=matrizs1[j][i];
      matrizs2[i][j]=matrizs2[j][i];
      valo1=valo1+2;
      valo2++;
    }
  }

  printf("\nMultiplicación de matrices NO simétricas:\n");

  printf("A*B\n");
  Mult3x3(matrizns1,matrizns2, matrizRns1);
  ImprimeOp3x3('*', matrizns1,matrizns2,matrizRns1);

  printf("\nB*A\n");
  Mult3x3(matrizns2,matrizns1, matrizRns2);
  ImprimeOp3x3('*', matrizns2,matrizns1,matrizRns2);

  printf("\nMultiplicación de matrices simétricas:\n");

  printf("A*B\n");
  Mult3x3(matrizs1,matrizs2, matrizRs1);
  ImprimeOp3x3('*', matrizs1,matrizs2,matrizRs1);

  printf("\nB*A\n");
  Mult3x3(matrizs2,matrizs1, matrizRs2);
  ImprimeOp3x3('*', matrizs2,matrizs1,matrizRs2);

  //Ejercicio 7
  printf("\nA^2 * A=\n");
  int matrizRes1[3][3],matrizRes2[3][3],matrizRes3[3][3];

  Mult3x3(matrizns1,matrizns1, matrizRes1);//Haciendo A^2
  Mult3x3(matrizRes1,matrizns1, matrizRes2);//Multiplicando A^2 por A
  ImprimeOp3x3('*', matrizRes1,matrizns1,matrizRes2);

  printf("\nA * A^2=\n");
  Mult3x3(matrizns1,matrizRes1, matrizRes3);//Multiplicando A por A^2
  ImprimeOp3x3('*', matrizns1,matrizRes1,matrizRes3);
  return 0;
}



void ImprimeOp6x6(char op, int matriz1[6][6],int matriz2[6][6],int matrizR[6][6])
{
  int i,j;
  //Imprimiendo matrices
  for(i=0;i<6;i++)
  {
    for(j=0;j<6;j++)
    {
      printf("%i \t",matriz1[i][j]);
    }
    if(i==3)
    {
      printf("   %c   ",op);
    }
    else
    {
      printf("       ");
    }
    for(j=0;j<6;j++)
    {
      printf("%i \t",matriz2[i][j]);
    }
    if(i==3)
    {
      printf("   =   ");
    }
    else
    {
      printf("       ");
    }
    for(j=0;j<6;j++)
    {
      printf("%i \t",matrizR[i][j]);
    }
    printf("\n");
  }
}


void ImprimeOp3x3(char op, int matriz1[3][3],int matriz2[3][3],int matrizR[3][3])
{
  int i,j;
  //Imprimiendo matrices
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      printf("%i \t",matriz1[i][j]);
    }
    if(i==1)
    {
      printf("   %c   ",op);
    }
    else
    {
      printf("       ");
    }
    for(j=0;j<3;j++)
    {
      printf("%i \t",matriz2[i][j]);
    }
    if(i==1)
    {
      printf("   =   ");
    }
    else
    {
      printf("       ");
    }
    for(j=0;j<3;j++)
    {
      printf("%i \t",matrizR[i][j]);
    }
    printf("\n");
  }
}

void Mult3x3(int matriz1[3][3],int matriz2[3][3], int matrizR[3][3])
{
  int i,j,sum=0;
  for (i=0;i<3;i++)
  {
    for (j=0;j<3;j++)
    {
      for (int n=0;n<3;n++)
      {
        sum = sum + matriz1[i][n]*matriz2[n][j];
      }
      matrizR[i][j] = sum;
      sum = 0;
    }
  }
}

void Mult6x6(int matriz1[6][6],int matriz2[6][6], int matrizR[6][6])
{
  int i,j,sum=0;
  for (i=0;i<6;i++)
  {
    for (j=0;j<6;j++)
    {
      for (int n=0;n<6;n++)
      {
        sum = sum + matriz1[i][n]*matriz2[n][j];
      }
      matrizR[i][j] = sum;
      sum = 0;
    }
  }
}

void ImprimeMat3x3(int matriz[3][3])
{
  int i,j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      printf("%i \t",matriz[i][j]);
    }
    printf("\n");
  }
}

void ImprimeMat6x6(int matriz[6][6])
{
  int i,j;
  for(i=0;i<6;i++)
  {
    for(j=0;j<6;j++)
    {
      printf("%i \t",matriz[i][j]);
    }
    printf("\n");
  }
}
