/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "empleado.h"


int main(void)
{
    int id;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
    int cant;
    char buffer[5][20];

    Empleado* emp1=new_EmpleadoParam(33344, "Maria", "Garcia", 'f', 1200);
    Empleado* emp2=new_EmpleadoParam(33440, "Manuela","Lopez", 'f', 1400);
    Empleado* emp4=new_EmpleadoParam(21322, "Analia","Blanco", 'f', 1300);
    Empleado* emp5=new_EmpleadoParam(43211, "Raul","Freire", 'm', 1470);
    Empleado* emp3=NULL;
    Empleado* aux=NULL;

    LinkedList* lista = ll_newLinkedList();

    if(lista==NULL)
    {
        printf("No se consiguio memoria\n");
        exit(1);
    }

    printf("cant: %d\n", ll_len(lista));

    ll_add(lista, emp1);
    ll_add(lista, emp2);

    printf("cant: %d\n", ll_len(lista));

    FILE* f = fopen("lista.csv", "r");

    if(f!=NULL)
    {
        cant=fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
        if(cant==4)
        {
            emp3=new_EmpleadoParamString(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            if(emp3==NULL)
            {
                ll_add(lista, emp3);
            }
        }
        fclose(f);
    }

    printf("cant: %d\n", ll_len(lista));

    f=fopen("empleados.bin","wb");
    fwrite(&emp4, sizeof(Empleado), 1,f);
    fclose(f);

    Empleado* emp6=new_Empleado();

    f=fopen("empleada.bin","wb");
    fread(emp5, sizeof(Empleado), 1,f);
    fclose(f);

    ll_add(lista, emp4);
    ll_add(lista, emp5);

    for(int i=0; i<ll_len(lista); i++)
    {
        aux=(Empleado*) ll_get(lista, i);
        mostrarEmpleado(aux);
    }

    //ll_clear(lista);

    ll_sort(lista, empleadoSortNombre, 1);
    printf("-------------------------------------\n");
    printf("Empleados ordenados por Nombre: \n");

    for(int i=0; i<ll_len(lista); i++)
    {
        aux=(Empleado*) ll_get(lista, i);
        mostrarEmpleado(aux);
    }

    if(ll_isEmpty(lista))
    {
        printf("\n");
        printf("Esta vacio\n");
    }
    else
    {
        printf("\n");
        printf("No esta vacio\n");
    }

    ll_push(lista, 4, &aux);

    emp3=(Empleado*)ll_pop(lista,2);

    if(ll_contains(lista, &emp6))
    {
        printf("Si\n");
    }
    else
    {
        printf("No\n");
    }

    LinkedList* arrayClon = ll_clone(lista);



    ll_deleteLinkedList(lista);

    /* startTesting(1);  // ll_newLinkedList
     startTesting(2);  // ll_len
     startTesting(3);  // getNode - test_getNode
     startTesting(4);  // addNode - test_addNode
     startTesting(5);  // ll_add
     startTesting(6);  // ll_get
     startTesting(7);  // ll_set
     startTesting(8);  // ll_remove
     startTesting(9);  // ll_clear
     startTesting(10); // ll_deleteLinkedList
     startTesting(11); // ll_indexOf
     startTesting(12); // ll_isEmpty
     startTesting(13); // ll_push
     startTesting(14); // ll_pop
     startTesting(15); // ll_contains
     startTesting(16); // ll_containsAll
     startTesting(17); // ll_subList
     startTesting(18); // ll_clone
     startTesting(19); // ll_sort*/

    return 0;
}























