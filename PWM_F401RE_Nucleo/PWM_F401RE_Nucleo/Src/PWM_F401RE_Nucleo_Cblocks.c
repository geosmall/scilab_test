#include "machine.h"
#include "scicos_block4.h"

void compteur(scicos_block *block,int flag)
{
   #define PI 3.1415927

    int *outMatPtr;
    int m, n, Npos;
    static int NposMyCompteur;
    int i,j;

    /* outMatPtr : pointeur sur la matrice a transmettre */
    outMatPtr = Getint32OutPortPtrs(block,1);
    m = GetOutPortRows(block,1);
    n = GetOutPortCols(block,1); 
    Npos = NposMyCompteur;
   
    /* init */
    if (flag == 4)
    {
        /* Init du buffer de sortie */
            for(i =0; i < m*n; i++) 
            {
            outMatPtr[i] = 0;
            }
        Npos = 0;
    }
    else if(flag == 1) 
    {
            for (i=0; i < (m*n) ; i++)
        {
                        outMatPtr[m*(Npos%n)+(Npos%(m*n)/n)] = (Npos%100);
                        Npos++;
        }
    }
    NposMyCompteur = Npos;
    /* ending */
}
