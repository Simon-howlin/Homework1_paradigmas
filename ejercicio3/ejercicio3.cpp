#include <iostream>
#include <memory>

using namespace std;

struct  Node{
    int data;
    shared_ptr<Node> next;
};

struct list{
    shared_ptr<Node> head;
    size_t size;
};

// crea un nuevo nodo
shared_ptr<Node> create_node(int value){
    shared_ptr<Node> node = make_shared<Node>();
    node->data = value;
    node->next = nullptr;

    return node;
}

// inserta un nuevo nodo al principio de la lista
void push_front(shared_ptr<list>& list, int value){
    shared_ptr<Node> new_node = create_node(value);
    new_node->next = list->head;
    list->head = new_node;
    list->size ++;
}

// inserta un nuevo nodo al final de la lista
void push_back(shared_ptr<list>& list, int value){
    if (!(list->size)) push_front(list, value);

    shared_ptr<Node> curr = list->head;
    while (curr->next){
        curr = curr->next;
    }

    shared_ptr<Node> new_node = create_node(value);
    curr->next = new_node;
    list->size ++;
}

// inserta un nuevo nodo en la posicion deseada
void insert(shared_ptr<list>& list, int value, int pos){
    // si se decea insertar fuera de rango inserta al final de la lista
    if (pos > list->size){
        cout << "La posicion " << pos << " esta fuera de rango"<<endl;
        push_back(list, value);
    }else{
        shared_ptr<Node> curr = list->head;
        for (int i = 0; i < pos-2; i++){ 
            curr = curr->next;
        }

        shared_ptr<Node> new_node = create_node(value);
        new_node->next = curr->next;
        curr->next = new_node;
        list->size ++;
    }
}

// elimina el nodo de la posicion deseada
void erase(shared_ptr<list>& list, int pos){
    // si se decea insertar fuera de rango inserta al final de la lista
    if (pos > list->size){
        cout << "La posicion " << pos << " esta fuera de rango"<<endl;

        shared_ptr<Node> curr = list->head;
        while (curr->next->next){ // frena en el anterior al que se desea eliminar para reacomodar
            curr = curr->next;
        }

        curr->next->data = NULL;
        curr->next = nullptr;
        list->size --;
    }
    // caso base: que pos sea = 1
    else if (pos == 1){
        shared_ptr<Node> curr = list->head;
        list->head = curr->next;
        curr->data = NULL;
        curr->next = nullptr;
        list->size --;
    }
    else{
        shared_ptr<Node> curr = list->head;
        for (int i = 0; i < pos-2; i++){ // Freno 1 antes para no tener que volver a recorrer la lista al reacomodar
            curr = curr->next;
        }

        shared_ptr<Node>node_erase = curr->next; // Conservo el nodo a borrar para poder hacer que apunte a null
        curr->next = node_erase->next;
        node_erase->data = NULL;
        node_erase->next = nullptr;
        list->size --;
    }
}

// imprime la lista en secuencialmente desde {lista[0],..., lista[n]}
void print_list(shared_ptr<list>& list){
    shared_ptr<Node> curr = list->head;
    while (curr) {
        cout << curr->data;
        if (curr->next) {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    shared_ptr<list> myList = make_shared<list>();

    cout << "Prueba: Insertar al frente" << endl;
    push_front(myList, 10);
    push_front(myList, 5);
    push_front(myList, 1);
    print_list(myList); // Esperado: 1 -> 5 -> 10

    cout << "\nPrueba: Insertar al final" << endl;
    push_back(myList, 15);
    push_back(myList, 20);
    print_list(myList); // Esperado: 1 -> 5 -> 10 -> 15 -> 20

    cout << "\nPrueba: Insertar en posición específica" << endl;
    insert(myList, 7, 2);
    print_list(myList); // Esperado: 1 -> 7 -> 5 -> 10 -> 15 -> 20

    cout << "\nPrueba: Eliminar primer nodo" << endl;
    erase(myList, 1);
    print_list(myList); // Esperado: 7 -> 5 -> 10 -> 15 -> 20

    cout << "\nPrueba: Eliminar nodo en posición intermedia" << endl;
    erase(myList, 3);
    print_list(myList); // Esperado: 7 -> 5 -> 15 -> 20

    cout << "\nPrueba: Eliminar último nodo" << endl;
    erase(myList, myList->size);
    print_list(myList); // Esperado: 7 -> 5 -> 15

    cout << "\nPrueba: Intentar eliminar fuera de rango" << endl;
    erase(myList, 10); // Esperado: Mensaje de error
    print_list(myList); // Esperado: 7 -> 5

    return 0;
}