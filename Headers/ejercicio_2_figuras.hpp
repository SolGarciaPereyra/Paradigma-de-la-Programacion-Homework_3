#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <iomanip>
using namespace std;

/*Aclaracion: no agrego destructores a mis clases porque no me hacen falta (no estoy trabajando con memoria 
dinamica)*/

//Declaro mi clase "Punto":
class Punto{
    private:
        float x;
        float y;
    public:
        Punto(float coordenada_x, float coordenada_y); 
        void set_x(float coordenada_x);
        void set_y(float coordenada_y);
        float get_x() const;
        float get_y() const;

        friend class Circulo;
};

//Declaro mi clase "Circulo":
class Circulo{
    private:
        Punto centro;  //Existe una relacion de composicion entre "Circulo" y "Punto". 
        float radio;

    public:
        Circulo(float coordenada_x, float coordenada_y, float r);
        void set_radio(float r);
        float get_radio() const;
        Punto get_centro(); //Este metodo me va a servir para poder acceder al atributo "centro" desde fuera de la clase. 
};

//Declaro mi clase "Elipse":
class Elipse{
    private:
        Punto centro; //Existe una relacion de composicion entre "Elipse" y "Punto". 
        float semieje_mayor;
        float semieje_menor;
    
    public:
        Elipse(float coordenada_x, float coordenada_y, float a, float b);
        void set_semieje_mayor(float a);
        void set_semieje_menor(float b);
        float get_semieje_mayor() const;
        float get_semieje_menor() const;
        Punto get_centro();
};

//Declaro mi clase "Rectangulo":
class Rectangulo{
    private:
        Punto vertice_inferior_izquierdo; //Existe una relacion de composicion entre "Rectangulo" y "Punto". 
        float ancho; 
        float largo;

    public:
        Rectangulo(float coordenada_x, float coordenada_y, float a, float b);
        void set_ancho(float a);
        void set_largo(float b);
        float get_ancho() const;
        float get_largo() const;
        Punto get_vertice_inferior_izquierdo();
};

//Declaro mi clase "ProcesadorFigura", utilizando template specialization:
//Primero tengo que definir "ProcesadorFigura" como una plantilla.
template<typename T>
class ProcesadorFigura{
    /*Voy a usar esta para calcular el area de figuras que no conozco o para objetos que no son figuras (como
    es el caso del punto).*/
    public:
        float calcular_area_figura(const T& figura){ return 0;}
}; 

template<>
class ProcesadorFigura<Circulo>{  //Especializo la plantilla para objetos del tipo exacto "Circulo".
    public:
        float calcular_area_figura(const Circulo& circulo){
            //Utilizo la formula matematica del area de un circulo: pi * radio^2.
            //Uso pi como 3.14 (cantidad de decimales arbitraria).
            return 3.14 * circulo.get_radio() * circulo.get_radio();
        }
};

template<>
class ProcesadorFigura<Elipse>{  //Especializo la plantilla para objetos del tipo exacto "Elipse".
    public:
        float calcular_area_figura(const Elipse& elipse){
            //Utilizo la formula matematica del area de un elipse: pi * semieje_mayor * semieje_menor.
            //Uso pi como 3.14 (cantidad de decimales arbitraria).
            return 3.14 * elipse.get_semieje_mayor() * elipse.get_semieje_menor();
        }
};

template<>
class ProcesadorFigura<Rectangulo>{  //Especializo la plantilla para objetos del tipo exacto "Rectangulo".
    public:
        float calcular_area_figura(const Rectangulo& rectangulo){
            //Utilizo la formula matematica del area de un rectangulo: semieje_mayor * semieje_menor.
            return rectangulo.get_ancho() * rectangulo.get_largo();
        }
};

