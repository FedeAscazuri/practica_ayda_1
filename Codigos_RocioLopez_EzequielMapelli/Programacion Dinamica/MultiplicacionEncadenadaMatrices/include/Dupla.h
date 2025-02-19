#ifndef DUPLA_H
#define DUPLA_H


class Dupla
{
    public:
        Dupla(int elem1, int elem2);
        int accederPrimero() const;
        int accederSegundo() const;
        void modificarPrimero(int nuevoElem);
        void modificarSegundo(int nuevoElem);
        void multiplicar(int valor);
        void sumar(Dupla otraDupla);
        void restar(Dupla otraDupla);

    private:
        int primerElem;
        int segundoElem;
};

#endif // DUPLA_H
