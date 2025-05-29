#include "../Headers/ejercicio_2_figuras.hpp"

//Defino los metodos de la clase "Punto":
Punto::Punto(float coordenada_x, float coordenada_y) : x(coordenada_x), y(coordenada_y){}

void Punto::set_x(float coordenada_x){ x = coordenada_x;}

void Punto::set_y(float coordenada_y){ y = coordenada_y;}

float Punto::get_x() const { return x;}

float Punto::get_y() const { return y;}

//Defino los metodos de la clase "Circulo":
Circulo::Circulo(float coordenada_x, float coordenada_y, float r) : centro(coordenada_x, coordenada_y), radio(r){};

void Circulo::set_radio(float r){ radio = r;}

float Circulo::get_radio() const { return radio;}

Punto Circulo::get_centro(){ return centro;}

//Defino los metodos de la clase "Elipse":
Elipse::Elipse(float coordenada_x, float coordenada_y, float a, float b): centro(coordenada_x, coordenada_y), semieje_mayor(a), semieje_menor(b){}

void Elipse::set_semieje_mayor(float a){ semieje_mayor = a;}

void Elipse::set_semieje_menor(float b){ semieje_menor = b;}

float Elipse::get_semieje_mayor() const { return semieje_mayor;}

float Elipse::get_semieje_menor() const { return semieje_menor;}

Punto Elipse::get_centro(){ return centro;}

//Defino los metodos de la clase "Rectangulo":
Rectangulo::Rectangulo(float coordenada_x, float coordenada_y, float a, float b): vertice_inferior_izquierdo(coordenada_x, coordenada_y), ancho(a), largo(b) {};

void Rectangulo::set_ancho(float a){ ancho = a;}

void Rectangulo::set_largo(float b){ largo = b;}

float Rectangulo::get_ancho() const { return ancho;}

float Rectangulo::get_largo() const { return largo;}

Punto Rectangulo::get_vertice_inferior_izquierdo(){ return vertice_inferior_izquierdo;}

