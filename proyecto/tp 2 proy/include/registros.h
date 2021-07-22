#ifndef REGISTROS_H_INCLUDED
#define REGISTROS_H_INCLUDED

class registros {

private:
    char player1[16];
    char player2[16];
    char ganador [16];

    int casas1;
    int ciudades1;
    int caminos1;

    int casas2;
    int ciudades2;
    int caminos2;

public:

    const char* getPlayer1();
    const char* getPlayer2();
    const char* getGanador();

    int getCasas1();
    int getCiudades1();
    int getCaminos1();
    int getCasas2();
    int getCiudades2();
    int getCaminos2();


    void setPlayer1(const char*);
    void setPlayer2(const char*);
    void setGanador(const char*);

    void setCasas1(int);
    void setCiudades1(int);
    void setCaminos1(int);
    void setCasas2(int);
    void setCiudades2(int);
    void setCaminos2(int);

        //METODOS:
    //LEER EN DISCO
    bool leerDeDisco(int);
    //BUSCAR EN DISCO

    //GRABAR EN DISCO
    bool grabarEnDisco();

    //MODIFICAR EN DISCO
    bool ModificarEnDisco(int);





};


#endif // REGISTROS_H_INCLUDED
