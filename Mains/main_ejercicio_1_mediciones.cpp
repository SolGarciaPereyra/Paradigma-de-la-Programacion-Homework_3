#include "ejercicio_1_mediciones.hpp"

int main(){
    //Comienzo a realizar la prueba simple propuesta por la consigna:
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3);
    Presion presion(101.3f, 5.8f, 6.1f);

    //Creo un objeto de la clase "SaveFlightData" con los objetos "posicion" y "presion":
    SaveFlightData saveFlightData(posicion, presion);

    /*Creo un archivo bianrio llamado "mediciones.data.binario" para serializar 
    lso objetos "posicion" y "presion":*/
    ofstream out("mediciones.data.binario", ios::binary);
    if(out.is_open()){
        saveFlightData.serializar(out);
        out.close();
    } else {
        cerr << "Error al abrir el archivo para escritura." << endl;
    }

    /*Ahora, deserializo los datos del archivo y los guardo en un nuevo objeto de la clase 
    "SaveFlightData":
    Inicializo el objeto antes de abrir el archivo, para que el scope de "saveFlightData" 
    incluya todo el main y no solo el bloque donde abro el archivo.*/
    SaveFlightData saveFlightDataCopia(Posicion(0, 0, 0, 0), Presion(0, 0, 0)); // Inicializo con valores default
    //Abro el archivo binario creado anteriormente para deserializar los datos de "saveFlightData":
    ifstream in("mediciones.data.binario", ios::binary);
    if(in.is_open()){
        saveFlightDataCopia.deserializar(in);
        in.close();
    } else {
        cerr << "Error al abrir el archivo para lectura." << endl;
    }

    //Imprimo los datos de "saveFlightDataCopia" para verificar que se hayan deserializado correctamente:
    saveFlightDataCopia.imprimir();

    return 0;
}