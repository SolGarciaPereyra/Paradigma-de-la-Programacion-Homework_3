#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <iomanip>
using namespace std;

/*Aclaracion: no agrego destructores a mis clases porque no me hacen falta. Estoy tabajando con smart pointers, los cuales manejan su
uso de memoria de forma independiente. Es decir, no necesito liberar la memoria manualmente, ya que ellos mismo lo hacen cuando se deja
de usarlos.*/

//Declaro mi interfaz "IMediciones":
class IMediciones{
    public:
        virtual void serializar(ofstream& out) const = 0;
        /*Para deserializar no uso "const" porque este metodo va a leer el archivo y asignar los 
        valores a los atributos de la clase (o, mejor dicho, del objeto, cuando se instancie la 
        clase en el main).*/
        virtual void deserializar(ifstream& in) = 0;
};

//Declaro mi clase abstracta "MedicionBase":
class MedicionBase: public IMediciones{
    protected:
        unique_ptr<float> tiempoMedicion;

    public:
        float getTiempo();
        virtual void imprimir() const = 0; 
        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in) override;
};

//Declaro mi clase derivada "Presion":
class Presion: public MedicionBase{
    public:
        float presionEstatica;  //p
        float presionDinamica;  //q

        Presion(float p, float q, float t); //Declaro el constructor.
        Presion(const Presion& q); //Declaro el constructor de copia. 
        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in) override;
        void imprimir() const override; 
};

//Declaro mi clase derivada "Posicion":
class Posicion: public MedicionBase{
    public: 
        float latitud;
        float longitud;
        float altitud;

        Posicion(float lat, float lon, float alt, float t); //Declaro el constructor.
        Posicion(const Posicion& p); //Declaro el constructor de copia. 
        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in) override;
        void imprimir() const override;
};

//Declaro mi clase "SaveFlightData":
class SaveFlightData{
    public:
        Posicion posicion; 
        Presion presion;

        SaveFlightData(const Posicion& p, const Presion& q);
        void serializar(ofstream& out);
        void deserializar(ifstream& in);
        void imprimir();
};