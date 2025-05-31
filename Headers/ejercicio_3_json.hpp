#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <iomanip>
#include <vector>
#include <type_traits>
#include <utility> 

using namespace std;
//ACLARACIONES:
/*1. La mayoria de los metodos (los que estan relacionados con templates) los defini en este archivo y no
en el .cpp, porque cuando compilaba el ejercicio me tiraba un error sobre que no encontraba el linker. 
Por lo tanto, decidi mover de lugar todas las definiciones de los metodos, para solucionar ese problema.*/

/*2. Declaro esta clase extra ya que, en un principio, mi clase "Clase2" contaba con el atributo 
"contenido_para_json", el cual contenia dentro del "pair" un "shared_ptr<void>". Por lo tanto, cuando 
estaba intentando implementar mi metodo "imprimir_contenido_json()", me encontraba con el problema de 
que no podia acceder a los metodos de mis objetos de clase "Clase1", ya que no podia hacer un cast
de un "shared_ptr<void>" a un "shared_ptr<Clase1<T>>" (trate con "dynamic_pointer_cast" y 
"static_pointer_cast", pero no me funcionaron) (habia tratado tambien con una version en la que inclui un
enum, para saber con que tipo de "Clase1<T>" estaba tratando cuando manejaba los "shared_ptr<void>", pero
terminaba en el mismo inconveniente de tener que castear el puntero). Entonces, decidi crear esta clase 
base para poder hacer un cast de "shared_ptr<ContenidoJson>" a "shared_ptr<Clase1<T>>" y poder acceder a 
los metodos de la clase "Clase1" (lo que implico cambiar "shared_ptr<void" por "shared_ptr<ContenidoJson>",
dentro de mi atributo "contenido_para_json").*/
class ContenidoJson{
    public:
        virtual ~ContenidoJson() = default; 
};

template<typename T>
//Declaro mi clase plantilla "Clase1" general (para doubles y strings):
class Clase1: public ContenidoJson{
    protected:
        //Atributo que me servira para guardar datos de tipo "T" (puede ser, por ejemplo, double o string):
        vector<T> vector_con_data;  
        
    public:
        void agregar_elemento(const T& elemento){ vector_con_data.push_back(elemento);}

        string get_container_formateado() const{
            /*Primero tengo que declarar una variable que me permita ir guardando cada elemento
            del vector, para poder construir el texto con la estatica que yo quiero:*/
            ostringstream datos_a_string;
            /*Ahora, uso "if constexpr" para chequear el tipo de dato que es T y, en base a eso,
            formatear el contenido del vector:*/
            if constexpr(is_same<T, double>::value){
                datos_a_string << "["; //Indico en el string el comienzo del vector. 

                //Recorro el vector de doubles, para ir agregando cada numero en "datos_a_string":
                for(int index = 0; index < int(vector_con_data.size()); index++){
                    datos_a_string << vector_con_data[index];

                    /*Me fijo si accedi o no al ultimo elemento del vector, para ver si continuo agregando
                    comas, ya que no quiero que el string quede: [... ,]*/
                    if(index != (int(vector_con_data.size()) - 1)){
                        datos_a_string << ", ";
                    }
                }

                datos_a_string << "]"; //Cierro el vector en el string.
            }
            else if constexpr(is_same<T, string>::value){
                datos_a_string << "["; //Indico en el string el comienzo del vector.

                //Recorro el vector de strings, para ir agregando cada string en "datos_a_string":
                for(int index = 0; index < int(vector_con_data.size()); index++){
                    datos_a_string << "\"" << vector_con_data[index] << "\""; //Estoy tabulando las comillas para que se vean dentro del string.

                    /*Me fijo si accedi o no al ultimo elemento del vector, para ver si continuo agregando
                    comas, ya que no quiero que el string quede: [... ,]*/
                    if(index != (int(vector_con_data.size()) - 1)){
                        datos_a_string << ", ";
                    }
                }

                datos_a_string << "]"; //Cierro el vector en el string.
            }

            return datos_a_string.str(); //Convierto la variable "datos_a_string" a string y la retorno.
        }
};

/*Declaro mi clase plantilla "Clase1" especializada para int:
Hago una especializacion para este tipo de dato, ya que necesito poder agregar un vector de enteros
y no una variable primitiva como en el caso general. Y la plantilla general no me permite hacer eso
porque el tipo "T" es primitvo, por lo que no puedo usar un vector de "T" como atributo.*/
template<>
class Clase1<int>: public ContenidoJson{
    protected:
        //Atributo que me servira para generar la matriz de ints
        vector<vector<int>> matriz_de_enteros;

    public:
        void agregar_elemento(const vector<int>& elemento){ matriz_de_enteros.push_back(elemento);}

        string get_container_formateado() const{
            /*Primero tengo que declarar una variable que me permita ir guardando cada elemento
            de la matriz, para poder construir el texto con la estatica que yo quiero:*/
            ostringstream datos_a_string;

            datos_a_string << "[\n"; //Indico en el string el comienzo de la matriz.

            //Recorro la matriz de enteros, para ir agregando cada entero en "datos_a_string":
            //Primero accedo a cada fila:
            for(int i = 0; i < int(matriz_de_enteros.size()); i++){
                datos_a_string << "\t["; //Indico en el string el comienzo de la fila.

                //Recorro cada elemento de la fila seleccioanda:
                for(int j = 0; j < int(matriz_de_enteros[i].size()); j++){
                    datos_a_string << matriz_de_enteros[i][j];

                    /*Me fijo si accedi o no al ultimo elemento de la fila, para ver si continuo agregando
                    comas, ya que no quiero que el string quede: [... ,]:*/
                    if(j != (int(matriz_de_enteros[i].size()) - 1)){
                        datos_a_string << ", ";
                    }
                }

                datos_a_string << "]"; //Cierro la fila en el string.

                /*Me fijo si accedi o no a la ultima fila de la matriz, para ver si continuo agregando
                comas, ya que no quiero que el string quede: [... ,]:*/
                if(i != (int(matriz_de_enteros.size()) - 1)){
                    datos_a_string << ",\n";
                }
                else{
                    datos_a_string << "\n";
                }
            }

            datos_a_string << "\t]"; //Cierro la matriz en el string.
    
            return datos_a_string.str(); //Convierto la variable "datos_a_string" a string y la retorno.
        }
};

//Declaro mi clase "Clase2":
class Clase2{
    protected:
        vector<pair<string, shared_ptr<ContenidoJson>>> contenido_para_json;

    public:
        template<typename T>
        void agregar_contenido_al_json(const string& etiqueta, const shared_ptr<Clase1<T>>& contenido_nuevo){ 
            shared_ptr<ContenidoJson> contenido_base = contenido_nuevo;
            contenido_para_json.push_back(make_pair(etiqueta, contenido_base));
        }
        void imprimir_contenido_json() const;  
};
