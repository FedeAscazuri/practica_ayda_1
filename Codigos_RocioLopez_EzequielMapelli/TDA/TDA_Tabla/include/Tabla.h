#ifndef TABLA_H
#define TABLA_H

class Tabla
{
    public:
        Tabla(int cantFilas, int cantColumnas);
        void agregar(int valor, int fila, int columna);
        bool vaciaCelda(int fila, int columna) const;
        int valorCelda(int fila, int columna) const;
        int mayorEntero() const;
        int sumaColum(int columna) const;
        ~Tabla();
    private:
        int **tabla; //con los dos asteriscos quiero decir que necesito "meterme" dos veces
        //en profundidad para acceder al valor final, ya que hay dos punteros,
        //un puntero tabla que apunta a un arreglo de punteros, y estos últimos que son
        //con los cuales llego a los arreglos finales, y por ende puedo acceder a algún valor determinado.
        int filas;
        int columnas;
};

#endif // TABLA_H
