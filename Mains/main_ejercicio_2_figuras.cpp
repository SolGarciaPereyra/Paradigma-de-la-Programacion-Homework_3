#include "../Headers/ejercicio_2_figuras.hpp"

int main(){
    //Comienzo por crear un objeto por cada una de las figuras:
    Punto punto(1.0f, 2.5f);
    Circulo circulo(3.0f, 4.0f, 9.0f);
    Elipse elipse(6.3f, 2.0f, 8.9f, 5.0f);
    Rectangulo rectangulo(2.4f, 3.0f, 12.0f, 7.5f);

    //Calculo el area para cada una de las figuras creadas anteriormente:
    ProcesadorFigura<Punto> calculador_punto;
    ProcesadorFigura<Circulo> calculador_circulo;
    ProcesadorFigura<Elipse> calculador_elipse;
    ProcesadorFigura<Rectangulo> calculador_rectangulo;

    float area_punto = calculador_punto.calcular_area_figura(punto);
    float area_circulo = calculador_circulo.calcular_area_figura(circulo);
    float area_elipse = calculador_elipse.calcular_area_figura(elipse);
    float area_rectangulo = calculador_rectangulo.calcular_area_figura(rectangulo);

    //Imprimo el area de cada figura:
    cout << "Area del punto es: " << area_punto << endl;
    cout << "Area del circulo es: " << area_circulo << endl;
    cout << "Area de la elipse es: " << area_elipse << endl;
    cout << "Area del rectangulo es: " << area_rectangulo << endl;

    return 0;
}