#ifndef PALABRA_H
#define PALABRA_H


class Palabra
{
public:
    Palabra();

    int getTamanio();
    const char* getPalabra();
    void addChar(char);
    void backsp();

    virtual ~Palabra();

private:
    char *v;
    int tam;
};

#endif // PALABRA_H
