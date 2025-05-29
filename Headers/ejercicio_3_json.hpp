#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

//Declaro mi clase "Clase1":
class Clase1{
    protected:
        vector<double> vector_de_doubles;
        vector<string> vector_de_strings;


    public:
        Clase1(); //Defino mi constructor para inicializar los vectores por default. 
        void agregar_double(double double_a_agregar);
        void agregar_string(string string_a_agregar);
        vector<double> get_vector_de_doubles();
        vector<string> get_vector_de_strings();


};

//Declaro mi clase "Clase2":
class Clase2{

};
