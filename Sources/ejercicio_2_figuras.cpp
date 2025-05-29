#include "../Headers/ejercicio_2_figuras.hpp"

//Defino los metodos de la clase "Punto":
Punto::Punto(float x, float y) : x(x), y(y){}

void Punto::set_x(float coordenada_x){ x = coordenada_x;}

void Punto::set_y(float coordenada_y){ y = coordenada_y;}

float Punto::get_x() const { return x;}

float Punto::get_y() const { return y;}

//Defino los metodos de la clase "Circulo":
Circulo::Circulo(float x, float y, float r) : Punto(x, y), radio(r){};

void Circulo::set_radio(float r){ radio = r;}

float Circulo::get_radio() const { return radio;}

//Defino los metodos de la clase "Elipse":
Elipse::Elipse(float x, float y, float a, float b): Punto(x, y), semieje_mayor(a), semieje_menor(b){}

void Elipse::set_semieje_mayor(float a){ semieje_mayor = a;}

void Elipse::set_semieje_menor(float b){ semieje_menor = b;}

float Elipse::get_semieje_mayor() const { return semieje_mayor;}

float Elipse::get_semieje_menor() const { return semieje_menor;}

//Defino los metodos de la clase "Rectangulo":
Rectangulo::Rectangulo(float x, float y, float a, float b): Elipse(x, y, a, b) {};

//Defino los metodos de la plantilla "ProcesadorFigura" y sus especializaciones:

