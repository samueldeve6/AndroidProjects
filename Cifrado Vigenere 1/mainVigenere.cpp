    #include <stdio.h>
    #include <iostream>
    int main (void)
    {
        int i,n=0,k=0;
        char frase [256];
     
        while (1)
        {
            n=0;
            puts ("\nIntroduce una frase: ");
            fgets (frase,255,stdin);
            do
            {
                printf ("\nIndica el desplazamiento: ");
                scanf ("%d",&n);
                while (getchar()!='\n');
            }while (n<0 || n>25);
     
            for (i=0;frase[i];i++)
            {
                if ((frase [i]>('z'-n) && frase [i]<='z') || (frase [i]>('Z'-n) && frase [i]<='Z' ))
                    frase [i]=frase [i]-26+n;
                else if (frase [i]>='a' && frase [i]<=('z'-n) || (frase [i]>='A' && frase [i]<=('Z'-n) ))
                    frase [i]+=n;
            }
            printf("\nCodificada con desplazamiento %d \n",n);
            printf ("%s\n",frase);
            puts("\nY ahora descodificada: ");
            for (k=0;k<26;k++)
            {
                for (i=0;frase[i];i++)
                {
                    if ((frase [i]<('a'+k) && frase [i]>=('a')) || (frase [i]<('A'+k) && frase [i]>=('A') ))
                    frase [i] =frase [i]+26-k;
                    else if ((frase [i]>=('a'+k) && frase [i]<=('z') )|| (frase [i]>=('A'+k) && frase [i]<=('Z') ))
                        frase [i]-=k;
                }
                printf ("%s\n\n",frase);
                system ("pause");
            }
        }
        return 0;
    }
     
