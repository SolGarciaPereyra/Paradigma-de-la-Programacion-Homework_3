#include "../Headers/ejercicio_3_json.hpp"

//Defino los metodos de mi clase "Clase2":

void Clase2::imprimir_contenido_json() const{
    cout << "{"; //Indico el comienzo del json.

    for(auto pair = contenido_para_json.begin(); pair != contenido_para_json.end(); ++pair){
        cout << " \"" << pair->first << "\": ";

        //Chequeo el tipo de dato con el que estoy trabajando, para poder imprimirlo correctamente:
        if(auto contenido_double = dynamic_pointer_cast<Clase1<double>>(pair->second)){
            cout << contenido_double->get_container_formateado();
        }
        else if(auto contenido_string = dynamic_pointer_cast<Clase1<string>>(pair->second)){
            cout << contenido_string->get_container_formateado();
        }
        else{  //Por default, si no era ni double ni string, entonces es int.
            auto contenido_int = dynamic_pointer_cast<Clase1<int>>(pair->second);
            cout << contenido_int->get_container_formateado();
        }
        
        if(next(pair) != contenido_para_json.end()){ //Si no es el ultimo elemento, agrego una coma.
            cout << ", " << endl;
        }
    }

    cout << "\n}" << endl; //Indico el final del json.
}
