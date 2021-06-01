#ifndef JUGADOR_H
#define JUGADOR_H


class Jugador{
public:
    //gets
    char* getUsuario();
    char* getPassword(); //--> Ver si hace falta colocar en pivate
    int getPartidasGanadas();

    int getNumeroJugador();
    int getMadera();
    int getPiedra();
    int getLana();
    int getLadrillo();
    int getTrigo();
    int getPuntosVictoria();
    int setCasasConstruidas();
    int setCaminosConstruidos();
    int setCiudadesConstruidas();

    //sets
    void setUsuario(char*);
    void setPassword(char*);
    void setPartidasGanadas(int);

    void setNumeroJugador(int);
    void setMadera(int);
    void setPiedra(int);
    void setLana(int);
    void setLadrillo(int);
    void setTrigo(int);
    void setPuntosVictoria(int);
    void setCasasConstruidas(int);
    void setCaminosConstruidos(int);
    void setCiudadesConstruidas(int);

    //METODOS (A FUTURO):
    //LEER EN DISCO
    //BUSCAR EN DISCO
    //GRABAR EN DISCO
    //MODIFICAR EN DISCO
    //ELIMINAR EN DISCO --> Ver si agregar estado en disco (bool)

private:
    char usuario[20];
    char password[20];
    int partidasGanadas;

    int numeroJugador;
    int madera;
    int piedra;
    int lana;
    int ladrillo;
    int trigo;
    int puntosVictoria;
    int casasConstruidas;
    int caminosConstruidos;
    int ciudadesConstruidas;
};

#endif // JUGADOR_H
