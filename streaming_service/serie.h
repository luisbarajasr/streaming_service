#include "video.h"
#include "episodio.h"
#include <vector>
#ifndef serie_h
#define serie_H

class serie: public video{
    public:
        vector<episodio> ep; 
        int cantEp; 

        serie(int, string, string);
        void setTitulo(string nom ){ titulo = nom; };
        void setGenero(string gen){ genero = gen; };
        void setId(int idserie){ id = idserie;};
        void setEpisodio(episodio, int);
        void adEpisodio(episodio);
        void mostrarEpisodio( ) const ; 

}; 

serie::serie(int idd, string nom, string gen): video(nom, idd, gen, 0, 0){};

void serie:: adEpisodio(episodio epi){
    ep.push_back(epi);
}

void serie:: mostrarEpisodio ( ) const{

    for(auto epi: ep){
    cout<<epi.getTitulo()<<" ";
    cout<<epi.getCalificacion()<<endl;
    }

}

#endif