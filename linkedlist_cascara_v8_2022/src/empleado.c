#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

Empleado* new_Empleado()
{
    Empleado* nuevoEmpleado = (Empleado*) calloc(1,sizeof(Empleado));
    return nuevoEmpleado;
}

void empleadoDestroy(Empleado* e)
{
    free(e);
}

Empleado* new_EmpleadoParam(int legajo, char* nombre, char* apellido, char sexo, float sueldo)
{
    Empleado* nuevoEmpleado = new_Empleado();
    if(nuevoEmpleado != NULL)
    {
        if(!(empleadoSetLegajo(nuevoEmpleado, legajo) &&
             empleadoSetNombre(nuevoEmpleado, nombre) &&
             empleadoSetApellido(nuevoEmpleado, apellido) &&
             empleadoSetSexo(nuevoEmpleado, sexo) &&
             empleadoSetSueldo(nuevoEmpleado, sueldo)))
        {
            empleadoDestroy(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}

int mostrarEmpleado(Empleado* e)
{
    int todoOk = 0;
    if(e != NULL)
    {
        printf("%d %s %s %c %.2f\n", e->legajo, e->nombre, e->apellido, e->sexo, e->sueldo);
        todoOk = 1;
    }
    return todoOk;
}

Empleado* new_EmpleadoParamString(char* legajo, char* nombre, char* apellido, char* sexo, char* sueldo)
{
    Empleado* nuevoEmpleado = new_Empleado();
    if(nuevoEmpleado != NULL)
    {
        if(!(empleadoSetLegajo(nuevoEmpleado, atoi(legajo)) &&
             empleadoSetNombre(nuevoEmpleado, nombre) &&
             empleadoSetApellido(nuevoEmpleado, apellido) &&
             empleadoSetSexo(nuevoEmpleado, sexo[0]) &&
             empleadoSetSueldo(nuevoEmpleado, atof(sueldo))))
        {
            empleadoDestroy(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}


int empleadoSetLegajo(Empleado* e, int legajo)
{
    int todoOk = 0;
    if(e != NULL && legajo >= 20000)
    {
        e->legajo = legajo;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoSetNombre(Empleado* e, char* nombre)
{
    int todoOk = 0;
    if(e != NULL && nombre != NULL && strlen(nombre) < 20 && strlen(nombre) > 2)
    {
        strcpy(e->nombre, nombre);
        strlwr(e->nombre);
        (e->nombre)[0] = toupper((e->nombre)[0]);

        todoOk = 1;
    }
    return todoOk;
}
int empleadoSetApellido(Empleado* e, char* apellido)
{
    int todoOk = 0;
    if(e != NULL && apellido != NULL && strlen(apellido) < 20 && strlen(apellido) > 1)
    {
        strcpy(e->apellido, apellido);
        strlwr(e->apellido);
        (e->apellido)[0] = toupper((e->apellido[0]));
        todoOk = 1;
    }
    return todoOk;
}
int empleadoSetSexo(Empleado* e, char sexo)
{
    int todoOk = 0;
    sexo = tolower(sexo);
    if(e != NULL && (sexo == 'm' || sexo == 'f'))
    {
        e->sexo = sexo;
        todoOk = 1;
    }
    return todoOk;

}
int empleadoSetSueldo(Empleado* e, float sueldo)
{
    int todoOk = 0;
    if(e != NULL && sueldo > 0 && sueldo <= 1000000)
    {
        e->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}


int empleadoGetLegajo(Empleado* e, int* pLegajo)
{
    int todoOk = 0;
    if(e != NULL && pLegajo != NULL )
    {
        *pLegajo = e->legajo;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetNombre(Empleado* e, char* nombre)
{
    int todoOk = 0;
    if(e != NULL && nombre != NULL )
    {
        strcpy(nombre, e->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetApellido(Empleado* e, char* apellido)
{
    int todoOk = 0;
    if(e != NULL && apellido != NULL )
    {
        strcpy(apellido, e->apellido);
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetSexo(Empleado* e, char* sexo){
    int todoOk = 0;
    if(e != NULL && sexo != NULL )
    {
        *sexo = e->sexo;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetSueldo(Empleado* e, float* sueldo){
 int todoOk = 0;
    if(e != NULL && sueldo != NULL )
    {
        *sueldo = e->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoSortNombre(void* a, void* b)
{
    int retorno=0;
    Empleado* x;
    Empleado* y;

    if(a!=NULL && b!=NULL)
    {
        x=(Empleado*)a;
        y=(Empleado*)b;
        retorno=strcmp(x->nombre, y->nombre);
    }
    return retorno;
}
