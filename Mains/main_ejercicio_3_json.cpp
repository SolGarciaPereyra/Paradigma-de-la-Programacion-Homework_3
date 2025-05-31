#include "../Headers/ejercicio_3_json.hpp"

int main(){
    //Verifico el funcionamiento de mi coidgo, utlizando el ejemplo provisto por la consigna:
    //Comienzo por crear objetos de clase "Clase1" para cada tipo de dato que necesito manejar:
    shared_ptr<Clase1<double>> clase1_double = make_shared<Clase1<double>>();
    clase1_double->agregar_elemento(1.3);
    clase1_double->agregar_elemento(2.1);
    clase1_double->agregar_elemento(3.2);

    shared_ptr<Clase1<string>> clase1_string = make_shared<Clase1<string>>();
    clase1_string->agregar_elemento("Hola");
    clase1_string->agregar_elemento("Mundo");

    shared_ptr<Clase1<int>> clase1_int = make_shared<Clase1<int>>();
    vector<int> priemra_fila = {1, 2};
    vector<int> segunda_fila = {3, 4};
    clase1_int->agregar_elemento(priemra_fila);
    clase1_int->agregar_elemento(segunda_fila);

    //Ahora creo un objeto de clase "Clase2" y le agrego los objetos creados anteriormente:
    Clase2 nuevo_json;
    nuevo_json.agregar_contenido_al_json<double>(string("vec_doubles"), clase1_double);
    nuevo_json.agregar_contenido_al_json<string>(string("palabras"), clase1_string);
    nuevo_json.agregar_contenido_al_json<int>(string("listas"), clase1_int);
    //Imprimo el json:
    nuevo_json.imprimir_contenido_json();

    return 0;
}


