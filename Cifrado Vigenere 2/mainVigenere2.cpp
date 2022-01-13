
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char oracion[100];
    char codificado[100];
    int i, desp;
    for(i = 0; i < 100; i++)
        codificado[i] = '\0';
    printf("Ingrese una oracion para cifrar:\n");
    fgets(oracion, 100, stdin);
    do{
        printf("Ingrese el numero de desplazamientos en el abecedario: ");
        scanf("%d", &desp);
        if(desp > 27)
            printf("El desplazamiento no puede ser mayor a 27\n\n");
    }
    while(desp > 27);
    for(i = 0; i < strlen(oracion); i++){
        if(oracion[i] >= 65 && oracion[i] <= 90){
            if(oracion[i] + desp > 90)
                codificado[i] = (oracion[i] - 90) + desp + 64;
            else
                codificado[i] = oracion[i] + desp;
        }
        else{
            if(oracion[i] >= 97 && oracion[i] <=122){
                if(oracion[i] + desp > 122)
                    codificado[i] = (oracion[i] - 122) + desp + 96;
                else
                    codificado[i] = oracion[i] + desp;
            }
            else
                codificado[i] = oracion[i];
        }
    }
    printf("La oracion codificada es: %s", codificado);
    getchar();
    return 0;
}
