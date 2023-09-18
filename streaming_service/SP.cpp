//SITUACION PROBLEMA C++
//LUIS BARAJAS
//A01235598
//15 de Junio 2022

#include <iostream> 
#include <istream>
#include <string> 
#include <algorithm>
#include <vector>

#include "video.h"
#include "pelicula.h"
#include "serie.h"

using namespace std; 

void cargaPeliculas(std::vector<pelicula> &peliculas, int cantPeliculas){ //funcion para cargar el arreglo de las peliculas.
    string nombre, genero; 
    int duracion, id; 
    double calificacion;

    for(int i=0 ; i<cantPeliculas; i++){

        cout<<"ID: "; 
        cin>>id;

        cout<<"Nombre de la pelicula: ";
        cin>>nombre; 

        cout<<"Calificacion: "; 
        cin>>calificacion;
        
        cout<<"Duracion: "; 
        cin>>duracion; 
        
        cout<<"Genero: "; 
        cin>>genero;

        peliculas.emplace_back(id, nombre, genero, duracion, calificacion);

    }
    
    cout<<endl;

}

void mostrarPeliculas(std::vector<pelicula> const & peliculas){ //funcion para imprimir las peliculas con sus calificaciones 
    cout<<"PELICULAS"<<endl; 
    cout<<endl;
    /*   
    std::string nombre_gen = "Accion";

    std::vector<pelicula> found;

    std::copy_if(peliculas.begin(), peliculas.end(), std::back_inserter(found), [&nombre_gen] (pelicula const& peli) {
         return peli.getGenero() == nombre_gen;
    });
    */

    for(auto it = peliculas.begin(); it<peliculas.end(); it++){
        cout<<it->getId()<<" "<<it->getTitulo()<<" "<<it -> getCalificacion()<<endl;
    }
}

void cargarSeries(vector<serie>& series, int cantSe){ //funcion para cargar las series
    string nombre, genero;
    int id; 

    for(int i=0; i<cantSe; i++){
        cout<<"ID de la serie: "; 
        cin>>id; 

        cout<<"Nombre de la serie: "; 
        cin>>nombre; 

        cout<<"Genero de la serie: "; 
        cin>>genero; 

        series.emplace_back(id, nombre, genero);
    }

    cout<<endl; 

}

void cargarEp( vector<serie>& serie ){ //funcion para cargar los episodios de cada serie en el vector
    
    for(auto i=serie.begin(); i<serie.end(); i++){ //ciclo para obtener una serie y agregarle sus episodios

        int cantEp; 
        cout<<"Cantidad de episodios: "; 
        cin>>cantEp;

        for(int j=0; j<cantEp ; j++){ //ciclo para agregar los episodios de la serie actual 

            episodio ep; 
            string nom;
            double calificacion; 

            cout<<"nombre del episodio: "; 
            cin>>nom; 
            ep.setTitulo(nom); 

            cout<<"Calificacion para este episodio: ";
            cin>>calificacion;
            ep.setCalificacion(calificacion);

            i->adEpisodio(ep); //agregamos el episodio al vector de tipo episodio en clase serie 
        }
    }
    cout<<endl;
}

void mostrarSerie(vector<serie>& series){ //mostrar las series con sus episodios 

    cout<<"SERIES"<<endl; 
    cout<<endl; 

    for(auto const& i:series){
       cout<<i.getTitulo()<<" "<<i.getGenero()<<endl; 
       i.mostrarEpisodio(); 
       cout<<endl;
    }
    cout<<endl;
}

void mostrarSerieEspecifica(vector<serie>& serie, int idBsucar){ //Mostrar una serie en especifico por su ID

    for(auto const& i:serie){
        if( i.getId() == idBsucar){
            cout<<i.getTitulo()<<endl;
            i.mostrarEpisodio();
        }
        else{
            continue;
        }
    }

    cout<<endl; 
}

int main(){

    int cantPeliculas,cantSeries, decision;
    vector<pelicula> peliculas; //vector que contiene todas las peliculas 
    vector<serie> series; //vector que contiene todas las series 
    
    do{

        cout<<"1. Carga archivo de datos "<< endl;
        cout<<"2. Mostrar los videos en general"<< endl;
        cout<<" "<< endl;
        cout<<"4. Mostrar las peliculas con una cierta calificacion "<< endl;
        cout<<"5. Calificar un video "<< endl;
        cout<<"0. Salir "<<endl;

        cin>>decision;
        cout<<endl; 

        if(decision == 1){ //cargar las peliculas y las series con sus episodios LISTO

            cout<<"PELICULAS"<<endl;
            cout<<endl;
            cout<<"Cantidad de peliculas: ";
            cin>>cantPeliculas;
            
            cargaPeliculas(peliculas, cantPeliculas);
            cout<<endl; 

            cout<<"SERIES"<<endl; 
            cout<<endl; 
            cout<<"Cantidad de series: ";
            cin>>cantSeries;

            cargarSeries(series, cantSeries);
            cargarEp(series);

        }
        else if(decision == 2){ //mostrar peliculas por genero FALTA TERMINAR 
            
            mostrarPeliculas(peliculas); 
            cout<<endl;
            mostrarSerie(series);
            
        }
        else if(decision == 3){//Mostrar los episodios de una serie seleccionada con una calificacion LISTO 

            int idQuiero; 
            cout<<"ID de la serie que buscas: "<<endl; 
            cin>>idQuiero; 

            mostrarSerieEspecifica(series, idQuiero);
        
        }
        else if(decision == 4){ //Mostrar las peliculas con su calificacion LISTO 
            
            mostrarPeliculas(peliculas);
            cout<<endl;

        }
        else if (decision == 5)//calificar
        {
            
            int idBsucar;
            double nuevaCali;

            cout<<"ID de pelicula a calificar: "; 
            cin>>idBsucar; 
            
            cout<<"Nueva Calificacion: "; 
            cin>>nuevaCali;

            for(auto & i:peliculas){
                if( i.getId() == idBsucar){
                    i.setCalificacion(nuevaCali); 
                }
                else{
                    continue;
                }
            }
            cout<<"Calificacion cambio"<<endl;
            cout<<endl;
        }
        else if(decision == 0){ //Salir
            break;
            
        }
        
    }
    while (decision != 0);

    cout<<endl; 
    cout<<"FIN, GRACIAS "<<endl; 

    return 0;
}