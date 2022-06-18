#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
}Empleado;

#endif // EMPLEADO_H_INCLUDED

Empleado* new_Empleado();
Empleado* new_EmpleadoParam(int legajo, char* nombre, char* apellido, char sexo, float sueldo);
Empleado* new_EmpleadoParamString(char* legajo, char* nombre, char* apellido, char* sexo, char* sueldo);
void empleadoDestroy(Empleado* e);

int empleadoSetLegajo(Empleado* e, int legajo);
int empleadoSetNombre(Empleado* e, char* nombre);
int empleadoSetApellido(Empleado* e, char* apellido);
int empleadoSetSexo(Empleado* e, char sexo);
int empleadoSetSueldo(Empleado* e, float sueldo);

int empleadoGetLegajo(Empleado* e, int* legajo);
int empleadoGetNombre(Empleado* e, char* nombre);
int empleadoGetApellido(Empleado* e, char* apellido);
int empleadoGetNombreCompleto(Empleado* e, char* nombreCompleto);
int empleadoGetSexo(Empleado* e, char* sexo);
int empleadoGetSexoString(Empleado* e, char* sexo);
int empleadoGetSueldo(Empleado* e, float* sueldo);

int empleadoSortNombre(void* a, void* b);
