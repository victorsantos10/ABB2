#include<iostream>
#include<conio.h>
#include <iostream>
#include <windows.h>


using namespace std;


struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;

};
// Propototipos
void menu();
Nodo* crearNodo(int, Nodo*);
void InsertarNodo(Nodo*&, int, Nodo*);
void mostrarArbol(Nodo*, int);
bool buscarNodo(Nodo*, int);
void recorrerArbol(Nodo*);
void EliminarNodo(Nodo*, int);
void eliminar(Nodo*);
Nodo* minimo(Nodo*);
void reemplazar(Nodo*, Nodo*);
Nodo* arbol = NULL;

int main()
{
    menu();
}


Nodo* crearNodo(int n, Nodo* padre) { // Crea los Nodos 
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;
    nuevoNodo->padre = padre; 
    return nuevoNodo;
}

void InsertarNodo(Nodo*& arbol, int n, Nodo* padre) { // Inserta los Nodos 
    if (arbol == NULL) {
        Nodo* nuevoNodo = crearNodo(n, padre); 
        arbol = nuevoNodo;
    } 
    else {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz) {
            InsertarNodo(arbol->izq, n, arbol);
        }
        else {
            InsertarNodo(arbol->der, n, arbol);
        }
    }

}

void mostrarArbol(Nodo* arbol, int contador) {
    if (arbol == NULL) {

        return;
    }
    else {
        mostrarArbol(arbol->der, contador + 1);
        for (int i = 0; i < contador; i++) {
            cout <<"   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, contador + 1);
    }
}

bool buscarNodo(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return false;
    }
    else if (arbol->dato == n){
        return true;
    }
    else if (n < arbol->dato) {
        return buscarNodo(arbol->izq, n); 
    }
    else {
        return buscarNodo(arbol->der, n);
    }
}

void recorrerArbol(Nodo* arbol) { //recorrido en preorden
    if (arbol == NULL) {
        return;
      
    }
    else {
        cout << arbol->dato << "-";
        recorrerArbol(arbol->izq);
        recorrerArbol(arbol->der);
    }
} 

void EliminarNodo(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return;
    }
    else if (n < arbol->dato) {
        EliminarNodo(arbol->izq, n);

    }
    else if (n > arbol->dato) {
        EliminarNodo(arbol->der, n);
    }
    else {
        eliminar(arbol);
    }


}

void reemplazar(Nodo* arbol, Nodo* nuevoNodo) {
    if (arbol->padre) { //arbol->padre hay que asigarle un nuevo hijo
        if (arbol->dato = arbol->padre->izq->dato) {
            arbol->padre->izq = nuevoNodo;
       }
    }
    if (nuevoNodo) {

    }
}

void eliminar(Nodo* nodoeliminado) { // para eliminar el nodo encontrado 
    if (nodoeliminado->izq && nodoeliminado->der) {
        Nodo* menor = minimo(nodoeliminado->der); 
        nodoeliminado->dato = menor->dato;
        eliminar(menor);
     } 
    else if (nodoeliminado->izq) {

    }
}
Nodo* minimo(Nodo* arbol) { // para determinar el nodo mas izquierdo
    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->izq) {
        return minimo(arbol->izq);
    }
    else {
        return arbol;
    }
}
void menu() {
    int opcion, dato, contador = 0, n;
    do {
        cout << "\tArboles Binarios: ." << endl;
        cout << "\t1.- Insertar un nodo" << endl;
        cout << "\t2.- Mostrar el arbol" << endl;
        cout << "\t3.- Buscar un nodo" << endl;
        cout << "\t4.- Recorrer el arbol" << endl;
        cout << "\t5.- Borrar un nodo" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Coloque un numero: ";
            cin >> dato;
            InsertarNodo(arbol, dato, NULL);
            cout << "\n";
            system("pause");
            break;
        case 2:
            cout << "\nMostrando el arbol completo:\n\n";
            mostrarArbol(arbol, contador);
            cout << "\n";
            system("pause");
            break;
        case 3:
            cout << "\nIngresar elemento a buscar: ";
            cin >> dato;
            if (buscarNodo(arbol, dato) == true) {
                cout << "\nElemento " << dato << " esta en el arbol\n";
            }
            else {
                cout << "\n El elemento no esta en el arbol";
            }
            cout << "\n";
            system("pause");
            break;
        case 4: 
            cout << "\n Mostrando recorrido del arbol:\n\n";
            recorrerArbol(arbol);
            cout << "\n\n";
            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 5);
} 

