#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define DIM 30

#define N 0

#define S 1

#define E 2

#define O 3

 

int main()

{

    char laberintox[DIM][DIM];

    int direcc;

    int movimiento=0;

    int x=0;

    int y=0;

    srand(time(NULL));

 

    for(y=0;y<DIM;y++)

    {

        for(x=0;x<DIM;x++)

        {

            if((( y>0 && y<(DIM-1) && x>0 && x<(DIM-1) ) && (rand()%5<3))  ||  (x==(DIM-2)&&y==(DIM-1)))

            {

                laberintox[y][x]=' ';

            }

            else

            {

                laberintox[y][x]='Û';

            }

        }

    }

    x=0;

    y=0;

    for(y=0;y<DIM;y++)

    {

        for(x=0;x<DIM;x++)printf("%c", laberintox[y][x]);

        {

            printf("\n");

        }

    }

    x=1;

    y=1;

    direcc=1;

    laberintox[1][1]='Ï';

    for(movimiento=0;(!(x==(DIM-2)&&y==(DIM-1)))&&movimiento<=((DIM-1)*(DIM-1))&&x<DIM&&y<DIM;movimiento++)

    {

        switch(direcc)

        {

            case 0:

            {

                if(laberintox[y][x+1]==' '||laberintox[y][x+1]=='Ï')

                {

                    x=x+1;//ESTE

                    direcc=E;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y-1][x]==' '||laberintox[y-1][x]=='Ï')

                {

                    y=y-1;//NORTE

                    direcc=N;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y][x-1]==' '||laberintox[y][x-1]=='Ï')

                {

                    x=x-1;//OESTE

                    direcc=O;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y+1][x]==' '||laberintox[y+1][x]=='Ï')

                {

                    y=y+1;//SUR

                    direcc=S;

                    laberintox[y][x]='Ï';

                    break;

                }

            }

            case 1:

            {

                if(laberintox[y][x-1]==' '||laberintox[y][x-1]=='Ï')

                {

                    x=x-1;//OESTE

                    direcc=O;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y+1][x]==' '||laberintox[y+1][x]=='Ï')

                {

                    y=y+1;//SUR

                    direcc=S;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y][x+1]==' '||laberintox[y][x+1]=='Ï')

                {

                    x=x+1;//ESTE

                    direcc=E;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y-1][x]==' '||laberintox[y-1][x]=='Ï')

                {

                    y=y-1;//NORTE

                    direcc=N;

                    laberintox[y][x]='Ï';

                    break;

                }

            }

            case 2:

            {

                if(laberintox[y+1][x]==' '||laberintox[y+1][x]=='Ï')

                {

                    y=y+1;//SUR

                    direcc=S;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y][x+1]==' '||laberintox[y][x+1]=='Ï')

                {

                    x=x+1;//ESTE

                    direcc=E;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y-1][x]==' '||laberintox[y-1][x]=='Ï')

                {

                    y=y-1;//NORTE

                    direcc=N;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y][x-1]==' '||laberintox[y][x-1]=='Ï')

                {

                    x=x-1;//OESTE

                    direcc=O;

                    laberintox[y][x]='Ï';

                    break;

                }

            }

            case 3:

            {

                if(laberintox[y-1][x]==' '||laberintox[y-1][x]=='Ï')

                {

                    y=y-1;//NORTE

                    direcc=N;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y][x-1]==' '||laberintox[y][x-1]=='Ï')

                {

                    x=x-1;//OESTE

                    direcc=O;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y+1][x]==' '||laberintox[y+1][x]=='Ï')

                {

                    y=y+1;//SUR

                    direcc=S;

                    laberintox[y][x]='Ï';

                    break;

                }

                else if(laberintox[y][x+1]==' '||laberintox[y][x+1]=='Ï')

                {

                    x=x+1;//ESTE

                    direcc=E;

                    laberintox[y][x]='Ï';

                    break;

                }

            }

        }

    }

    if (!(x==(DIM-2)&&y==(DIM-1)))

    {

        printf("\n\n\n  No tiene salida :c");

    }

    else

    {

        printf("\n\n\n  Encontre la salida!!");

    }

    printf("\n\n");

    for(y=0;y<DIM;y++)

    {

        for(x=0;x<DIM;x++)

        {

            printf("%c", laberintox[y][x]);

        }

        printf("\n");

    }

    return 0;

}

