

int ordenaTareasConDeadline(int cantTareas, int arregloSolucion[], int arregloDeadlines[]){
  arregloSolucion[0] = 0;
  //Arreglo de deadlines esta ordenado por beneficio, el numero de la tarea es el indice y lo que contiene es el plazo(deadline).
  arregloDeadlines[0] = 0;
  arregloSolucion[1] = 1; //Agrego la primer tarea a la solucion, porque se que es la que mas beneficio da.
  int cantTareasSolucion = 1; //Guarda la cantidad de tareas que agregue a mi arreglo solucion
  //Como ya agregue la primera, ahora itero desde la segunda hasta el final
  for (int tareaActual = 2; tareaActual <= cantTareas; tareaActual++) {
    int ultimaPosicion = cantTareasSolucion;
    //Mientras el deadline de la ultima tarea que agregue, sea menor al deadline de la tarea actual
    //Y ademas, el deadline de la ultima tarea que agregue sea distinto a la posicion de dicha tarea
    //Lo que hace esto es darme la ultima posicion en la que puedo agregar la tarea
    //La primer condicion del while se fija si el deadline de la tareaActual es menor al deadline de las tareas ya agregadas en solucion (comenzando desde la ultima agregada).
    //La segunda condicion se fija que las tareas agregadas previamente a solucion (comenzando desde la ultima agregada) no estén en su maximo deadline.
    while ((arregloDeadlines[arregloSolucion[ultimaPosicion]] > arregloDeadlines[tareaActual]) && (arregloDeadlines[arregloSolucion[ultimaPosicion]] != ultimaPosicion)) {
      ultimaPosicion--;
    }
    //Si el deadline de la ultima tarea que agregue, es menor al deadline de la tarea actual
    //Y ademas, el deadline de la tarea actual es mayor a ala ultima ultimaPosicion
    //La segunda condicion del if se fija (en caso de que la tareaActual posea un deadline mayor o igual al de la ultimaPosicion) si hay espacio en el arreglo solucion para agregar la tareaActual respetando el maximo deadline de la misma.
    if ((arregloDeadlines[arregloSolucion[ultimaPosicion]] <= arregloDeadlines[tareaActual]) && (arregloDeadlines[tareaActual] > ultimaPosicion)) {
      for (int i = cantTareasSolucion; i >= (ultimaPosicion + 1); i--) {
        //Realizo un corrimiento desde la ultima tarea que agregue, hasta la posicion en donde puedo agreagar la tarea actual
        arregloSolucion[i + 1] = arregloSolucion[i];
      }
      //Agrego la tarea
      arregloSolucion[ultimaPosicion + 1] = tareaActual;
      cantTareasSolucion++;
    }
  }
  return cantTareasSolucion;
}
