#include "../Headers/ejercicio_3_json.hpp"

//Defino los emtodos de mi clase "Clase1":
Clase1::Clase1() = default; 

void Clase1::agregar_double(double double_a_agregar){ vector_de_doubles.push_back(double_a_agregar);}

void Clase1::agregar_string(string string_a_agregar){ vector_de_strings.push_back(string_a_agregar);}

vector<double> Clase1::get_vector_de_doubles() {return vector_de_doubles;}

vector<string> Clase1::get_vector_de_strings() {return vector_de_strings;}

