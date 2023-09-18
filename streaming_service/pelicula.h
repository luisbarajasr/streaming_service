#include "video.h"
#ifndef pelicula_h
#define pelicula_h

class pelicula: public video{
    public: 
        pelicula(int id, string titulo, string genero, int duracion,double calificacion);

};

pelicula::pelicula(int id, string titulo,  string genero, int duracion, double calificacion) : video(titulo, id, genero, duracion, calificacion){}; 

#endif