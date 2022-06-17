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

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;                 //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;         //puntero al prox nodo
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;                       //cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);                                  //crea una nueva lista
int ll_len(LinkedList* this);                                        //devuelve el valor del campo int size
Node* test_getNode(LinkedList* this, int nodeIndex);             
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);                        //añado un elemento a la lista
void* ll_get(LinkedList* this, int index);                           //devuelve el elemento del indice seleccionado
int ll_set(LinkedList* this, int index,void* pElement);              //remplaza un elemento en el indice elegido
int ll_remove(LinkedList* this,int index);                           //elimina un elemento de la lista
int ll_clear(LinkedList* this);                                      //eliminan todos los elementos de la lista
int ll_deleteLinkedList(LinkedList* this);                           //elimina la lista
int ll_indexOf(LinkedList* this, void* pElement);                    //devuelve el indice de la primera ocurrencia del elemento elemento == elemento2
int ll_isEmpty(LinkedList* this);                                    //indica si la lista esta vacia o no
int ll_push(LinkedList* this, int index, void* pElement);            //inserta un elemento en el indice elegido de la lista
void* ll_pop(LinkedList* this,int index);                            //elimina un elemento y devuelve un puntero a ese elemento
int ll_contains(LinkedList* this, void* pElement);                   //Determina si la lista contiene o no el elemento pasado como parametro
int ll_containsAll(LinkedList* this,LinkedList* this2);              //Determina si todos los elementos de la lista (this2)estan contenidos en la lista (this)
LinkedList* ll_subList(LinkedList* this,int from,int to);            //Crea y retorna una nueva lista con los elementos indicados
LinkedList* ll_clone(LinkedList* this);                              //Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
