/******************************************************************************
Autor:
omar alejandro alcaraz renteria

Fecha: 21 de abril del 2025

programa en c++ que realiza el calculo del RFC  de acuerdo con las reglas del SAT
*******************************************************************************/
#include <iostream> //Biblioteca estandar para entradas y salidas en C++
#include <stdio.h> //Biblioteca para manipulacion de cadenas (std::string)

//Funcion para obtener la primera vocal interna del apellido paterno
char obtenerPrimeraVocalInterna(const std::string& str) {
    //Recorremos para obtener la primera vocal interna del apellido paterno
    for (size_t i=1; i < str.length(); ++i) {
        char c = str[i]; //Se obtiene el caracter actual de la cadenas
        
        //Se verifica si el caracter es una vocal mayuscula
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
             return c; //Regresa la primera vocal interna encontrada
    }
    return 'X'; //Si no se encuentra ninguna vocal interna, se devuelve una X
}

//Funcion para calcular el RFC con base en los datos personales
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string&apellidoMaterno, const std::string& fechaNacimiento){
    std::string rfc; //Variable para almacenar el RFC resultante
    
    //Se obtiene la primera letral del apellido paterno
    char letrainicial = apellidoPaterno[0];
    
    //Se obtiene la primera vocal interna del apellido paterno 
    char PrimeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);
    
    //Se obtiene la inicial del apellido materno, si no existe se usa una X
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';
    
    //Se obtiene la inicial del nombre
    char inicialNombre = nombre[0];
    
    //Se obtiene los ultimos dos digitos del año de nacimiento (posicion 2 y 3)
    std:: string anio = fechaNacimiento.substr(2,2);
    
    //Se obtiene el mes de nacimiento (posicion 5 6)
    std::string mes = fechaNacimiento.substr(5,2);
    
    //Se obtiene  el dia de nacimiento(posiciones 8 y 9)
    std::string dia = fechaNacimiento.substr(8,2);
    
    //Se construye el RFC concatenando los valores obtenidos
    rfc = letrainicial;
    rfc += PrimeraVocalInterna;
    rfc += inicialApellidoMaterno;
    rfc += inicialNombre;
    rfc += anio;
    rfc += mes;
    rfc += dia;
    
    return rfc; //Se retorna el RFC generado
}  

int main(){
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
    
    //Solicita el nombre del usuario
    std::cout <<"Ingrese el nombre: ";
    std::getline(std::cin, nombre); //Captura toda la linea del nombre
    
    //Solicita el apellido paterno
    std::cout << "Ingrese el apellido paterno: ";
    std::getline(std::cin, apellidoPaterno);
    
    //Solicita el apellido materno, permitiendo que el usuario deje vacio 
    std::cout << "Ingrese el apellido materno (Si no tiene, presione Enter: ";
    std::getline(std::cin, apellidoMaterno);
    
    //Solicita la fecha de nacimiento en formato de YYYY-MM-DD
    std::cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
    std::getline(std::cin, fechaNacimiento);
    
    // Se calcula el RFC utilizando la funcion calcularRFC
    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
    
    //Se muestra el RFC generado
    std::cout << "RFC:"  << rfc << std::endl;
    
    return 0;
    //Finaliza el programa
}