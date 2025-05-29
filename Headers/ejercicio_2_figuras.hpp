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
        Punto(float x, float y); 
        void set_x(float coordenada_x);
        void set_y(float coordenada_y);
        float get_x() const;
        float get_y() const;

        friend class Circulo;
};

//Declaro mi clase "Circulo":
/*Hago que "Circulo" herede de "Punto" para poder reutilizar sus atributos (los cuales 
me van a servir para describir el centro del ciruclo) y sus metodos.*/
class Circulo: public Punto{
    private:
        float radio;

    public:
        Circulo(float x, float y, float r);
        void set_radio(float r);
        float get_radio() const;
};

//Declaro mi clase "Elipse":
/*Hago que "Elipse" herede de "Punto" para poder reutilizar sus atributos (los cuales 
me van a servir para describir el centro del elipse) y sus metodos.*/
class Elipse: public Punto{
    private:
        float semieje_mayor;
        float semieje_menor;
    
    public:
        Elipse(float x, float y, float a, float b);
        void set_semieje_mayor(float a);
        void set_semieje_menor(float b);
        float get_semieje_mayor() const;
        float get_semieje_menor() const;
};

//Declaro mi clase "Rectangulo":
/*Hago que "Rectangulo" herede de "Elipse" para poder reutilizar sus atributos y metodos:
como "Elipse" hereda de "Punto", las coordenadas (atributos) de "Punto" pueden representar
las coordenadas del vértice izquierdo inferior del rectangulo; el atributo "semieje_mayor"
puede representar su ancho y "semieje_menor" su largo.*/
class Rectangulo: public Elipse{
    public:
        Rectangulo(float x, float y, float a, float b);
};

//Declaro mi clase "ProcesadorFigura", utilizando template specialization:
//Primero tengo que definir "ProcesadorFigura" como una plantilla.
template<typename T>
class ProcesadorFigura{
    /*Voy a usar esta para calcular el area de figuras que no conozco (con esto me refiero a que
    estas no pertenecen a la lista de 4 figuras provista por la consigna: punto, circulo, elipse
    y rectangulo).*/
    public:
        float calcular_area_figura(const T& figura){ return 0;}
};

template<>
class ProcesadorFigura<Punto>{  //Especializo la planntilla para objetos del tipo exacto "Punto".
    public:
        float calcular_area_figura(const Punto& punto){
            //Supongo que el area de un punto es 0.
            return 0;
        }
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
            return rectangulo.get_semieje_mayor() * rectangulo.get_semieje_menor();
        }
};

