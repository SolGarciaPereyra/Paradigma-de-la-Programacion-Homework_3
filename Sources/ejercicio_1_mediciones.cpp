#include "../Headers/ejercicio_1_mediciones.hpp"

//Defino los metodos de la clase abstracta "MedicionBase":
float MedicionBase::getTiempo(){ return *tiempoMedicion;}

void MedicionBase::serializar(ofstream& out) const{
    /*Este metodo sirve para serializar el atributo "tiempoMedicion". Para poder escribir 
    su valor en el archivo binario (al cual podemos acceder gracias a la referencia recibida
    como parametro de entrada), obtenemos el raw pointer "float*" del atributo mediante el 
    uso de get(). Luego, usamos "reinterpret_cast<char*>" para convertir el "float*" en un
    "char*". Esto ultimo es necesario para que "out.write()" puede escribir los bytes en el 
    archivo. Por ultimo, "sizeof(float)" sirve para decirle a "out.write()" cual es el 
    tamaño de lo que debe escribir.*/

    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
}

void MedicionBase::deserializar(ifstream& in){
    /*Este metodo sirve para deserializar el atributo "tiempoMedicion". Para poder leer 
    su valor del archivo binario (al cual podemos acceder gracias a la referencia recibida
    como parametro de entrada), obtenemos el raw pointer "float*" del atributo mediante el 
    uso de get(). Luego, usamos "reinterpret_cast<char*>" para convertir el "float*" en un
    "char*". Esto ultimo es necesario para que "in.read()" pueda leer los bytes del archivo. 
    Por ultimo, "sizeof(float)" sirve para decirle a "in.read()" cual es el tamaño de lo que 
    debe leer.*/

    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
}

//Defino los metodos de la subclase "Presion":
Presion::Presion(float p, float q, float t){
    presionEstatica = p;
    presionDinamica = q;
    tiempoMedicion = make_unique<float>(t);
}

Presion::Presion(const Presion& q){
    //Este constructor de copia me va a ser util para el constructor "SaveFlightData".
    presionEstatica = q.presionEstatica;
    presionDinamica = q.presionDinamica;
    //Me creo un nuevo unique_ptr con el valor del atributo "tiempoMedicion" del objeto "q". 
    tiempoMedicion = make_unique<float>(*q.tiempoMedicion); 
}

void Presion::serializar(ofstream& out) const{
    //Primero hay que serializar el atributo "tiempoMedicion" de la clase abstracta "MedicionBase":
    MedicionBase::serializar(out);
    /*Ahora, aplico el mismo razonamiento explicado en el metodo "serializar()" de la clase
    abstracta "MedicionBase" para serializar los atributos "presionEstatica" y
    "presionDinamica":
    Le agrego const a <char*> porque estoy sobreescribiendo un metodo const, por lo que no puedo
    modificar el valor de los atributos de la clase. Y al hacer "reinterpret_cast<char*>", me tira 
    un error ya que esto implicaria la posibilidad de modificar un valor que deberia ser inmutable.
    Entonces, <const char*> permite hacer la reinterpretacion de la direccion del valor, asegurandole
    que no se va a modificar.*/
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(float));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(float));
}

void Presion::deserializar(ifstream& in){
    //Primero hay que deserializar el atributo "tiempoMedicion" de la clase abstracta "MedicionBase":
    MedicionBase::deserializar(in);
    /*Ahora, aplico el mismo razonamiento explicado en el metodo "deserializar()", de la clase
    abstracta "MedicionBase", para deserializar los atributos "presionEstatica" y "presionDinamica":
    A diferencia del metodo "serializar", en este caso no vamos a necesitar "const" para <char*>, ya que
    "in.read" necesita un puntero modificable para poder ir guardando ahi lo que va leyendo.*/
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
}

void Presion::imprimir() const{
    //Uso fixed en setpreicision() para mostrar solo 1 (eleccion arbitraria) decimal de los valores float.
    cout << fixed << setprecision(1);
    cout << "Tiempo tardado en medir la presion: " << *tiempoMedicion << endl;
    cout << "Presion Estatica: " << presionEstatica << endl;
    cout << "Presion Dinamica: " << presionDinamica << endl;
}

//Defino los metodos de la subclase "Posicion":
Posicion::Posicion(float lat, float lon, float alt, float t) {
    latitud = lat;
    longitud = lon;
    altitud = alt;
    tiempoMedicion = make_unique<float>(t);
}

Posicion::Posicion(const Posicion& p){
    //Este constructor de copia me va a ser util para el constructor "SaveFlightData".
    latitud = p.latitud;
    longitud = p.longitud;
    altitud = p.altitud;
    //Me creo un nuevo unique_ptr con el valor del atributo "tiempoMedicion" del objeto "p". 
    tiempoMedicion = make_unique<float>(*p.tiempoMedicion); 
}

void Posicion::serializar(ofstream& out) const{
    //Primero hay que serializar el atributo "tiempoMedicion" de la clase abstracta "MedicionBase":
    MedicionBase::serializar(out);
    /*Ahora, aplico el mismo razonamiento explicado en el metodo "serializar()" de la clase
    abstracta "MedicionBase" para serializar los atributos "latitud", "longitud" y
    "altitud":*/
    /*Le agrego const a <char*> porque estoy sobreescribiendo un metodo const, por lo que no puedo
    modificar el valor de los atributos de la clase. Y al hacer "reinterpret_cast<char*>", me tira 
    un error ya que esto implicaria la posibilidad de modificar un valor que deberia ser inmutable.
    Entonces, <const char*> permite hacer la reinterpretacion de la direccion del valor, asegurandole
    que no se va a modificar.*/
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(float));
}

void Posicion::deserializar(ifstream& in){
    //Primero hay que deserializar el atributo "tiempoMedicion" de la clase abstracta "MedicionBase":
    MedicionBase::deserializar(in);
    /*Ahora, aplico el mismo razonamiento explicado en el metodo "deserializar()", de la clase
    abstracta "MedicionBase", para deserializar los atributos "latitud", "longitud" y
    "altitud":
    A diferencia del metodo "serializar", en este caso no vamos a necesitar "const" para <char*>, ya que
    "in.read" necesita un puntero modificable para poder ir guardando ahi lo que va leyendo.*/
    in.read(reinterpret_cast<char*>(&latitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(float));
}

void Posicion::imprimir() const{
    //Uso fixed en setpreicision() para mostrar solo 1 (eleccion arbitraria) decimal de los valores float.
    cout << fixed << setprecision(1);
    cout << "Tiempo tardado en medir la posicion: " << *tiempoMedicion << endl;
    cout << "Latitud: " << latitud << endl;
    cout << "Longitud: " << longitud << endl;
    cout << "Altitud: " << altitud << endl;
}

//Defino los metodos de la clase "SaveFlightData":
SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q): posicion(p), presion(q) {
    /*El problema con este constructor, como explica la consigna, es que no se pueden
    copiar directamente las clases "Posicion" y "Presion" porque, debido al unique_ptr,
    no se pueden copiar los atributos "tiempoMedicion" de las subclases "Posicion" y "Presion". 
    Por lo tanto, pense en declarar y usar constructores de copias para ambas subclases, para
    intentar hacer algo similar a "copiar" sus atributos (me quiero guardar en una variable
    el valor del atributo "tiempoMedicion" de cada subclase, para poder usarlo en el constructor).*/
}

void SaveFlightData::serializar(ofstream& out){
    /*Este metodo sirve para serializar los atributos "posicion" y "presion". Para poder escribir 
    los valores de sus atributos en el archivo binario (al cual podemos acceder gracias a la 
    referencia recibida como parametro de entrada), llamo a los metodos "serializar()" de cada 
    subclase.*/
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(ifstream& in){
    /*Este metodo sirve para deserializar los atributos "posicion" y "presion". Para poder leer 
    los valores de sus atributos del archivo binario (al cual podemos acceder gracias a la 
    referencia recibida como parametro de entrada), llamo a los metodos "deserializar()" de cada 
    subclase.*/
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir(){
    /*Este metodo sirve para imprimir los atributos "posicion" y "presion". Para poder imprimir 
    los valores de sus atributos, llamo a los metodos "imprimir()" de cada subclase.*/
    posicion.imprimir();
    presion.imprimir();
}

