#include "video.h"
//#include "serie.h"
#ifndef episodio_h
#define episodio_h
#include <iostream>
#include <stdio.h>
#include <string> 

using namespace std; 

class episodio: public video{
    public: 
        string titulo; 
        double calificacion; 

        episodio(); 
        episodio(string , double);

        void setTitulo(string nombre ) {titulo = nombre; }; 
        void setCalificacion(double calif) {calificacion = calif; };
        string getTitulo(){ return titulo; }; 
        double getCalificacion(){ return calificacion; };
};

episodio::episodio(){
    titulo = " "; 
    calificacion = 0; 
};

episodio::episodio(string nombre, double calif){
    titulo =  nombre;
    calificacion = calif;
};

#endif