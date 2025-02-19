//Tamaño de los arrays = n (cant de tareas, van de la tarea 0 a la n-1)
//Los arreglos tiempos y ganancias vinene ordenados por ganancias, 
// los índices de los mismos indican la tarea (i).
//Los índices del arreglo solución me dicen en que unidad de tiempo se ejecuta la tarea que 
// se encuentra en dicha posición.

bool factible(array & solucion[], int ganancia, int tiempo, int cantTareasSol){
    bool entra = false;
    int unidadTiempo = 0; //Indices de solución.
    while ((!entra) && (unidadTiempo < tiempo)){
        if(solucion[unidadTiempo] = -1){
            entra = true;
        }
        unidadTiempo ++;
    }
    if (unidadTiempo = tiempo){
        entra = false;
    }
    return entra;
}

//solucion viene inicializado con valor distinguible -1.
//cantTareasSol me devuelve la cant de tareas en solucion y viene inicializada en 0.
void tareasGreedy(array ganancias[], array tiempos[], array & solucion[], int n, int cantTareasSol){ 
    int ganActual;
    int tiempoActual;
    for (int tarea = 0; tarea < n; tarea++){
        ganActual = ganancias[tarea];
        tiempoActual = tiempos[tarea];
        if factible(solucion, ganActual, tiempoActual, cantTareasSol){
            //Agregar a la solución este elemento.
        }
    }
}