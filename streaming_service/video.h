#include <string> 
#ifndef video_h
#define video_h
using namespace std; 

class video{
    public:
    string titulo, genero;
    int id; 
    int duracion ; 
    double calificacion; 

    video();
    video(string nombre, int idvideo, string gen, int dura, double calif);

    void setId(int idvideo){ id=idvideo; };
    void setTitulo(string nombre){ titulo = nombre; }; 
    void setDuracion(int dura){ duracion = dura; };
    void setGenero(string gen){ genero = gen; }; 
    void setCalificacion(double calif) { calificacion = calif; }; 

    int getId() const { return id; }; 
    string getTitulo() const{ return titulo; }; 
    int getDuracion() const { return duracion; }; 
    string getGenero() const { return genero; }; 
    double getCalificacion() const { return calificacion; }; 
};

video:: video(){
    id = 0; 
    titulo = " "; 
    genero= " "; 
    duracion = 0; 
    calificacion = 0; 
}

video ::  video(string nombre, int idvideo, string gen, int dura , double calif){
    titulo = nombre; 
    id = idvideo; 
    genero = gen; 
    duracion = dura; 
    calificacion = calif; 
}
#endif
