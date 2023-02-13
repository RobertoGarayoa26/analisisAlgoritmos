#include <iostream>
#include <list>
using namespace std;

//Clase que representa un grafo sin dirección
class Grafo{
    int numVertices;
    list<int> *adj;     //Arreglo dinámico de listas adyacentes

public:
    //Constructor y Destructor
    Grafo(int numVertices)  {this->numVertices = numVertices; adj = new list<int>[numVertices];}
    ~Grafo()                {delete [] adj;}

    //Función para agregar un lado al grafo
    void addEdge(int vert, int wide);

    //Impresión de los colores de los vértices
    void Coloreado();
};

void Grafo::addEdge(int vert, int wide){
    adj[vert].push_back(wide);
    adj[wide].push_back(vert);      //El grafo es indirecto
}

//Asignación de colores(iniciando en 0) para todos los vertices e impresión de los colores asignados
    //Clases::Métodos
void Grafo::Coloreado(){
    int resultado[numVertices];

    //Asignacion del primer color al primer vértice
    resultado[0] = 0;

    //Inicializando el resto de los números de Vertices como "unassigned"
    for (int unssignedVert = 1; unssignedVert < numVertices; unssignedVert++)
        resultado[unssignedVert] = -1;  //Ningun color es asignado a "unssignedVert"

    //Arreglo temporal para almacenar los colores disponibles.
    //El valor verdadero de "disponible[color]" significaría que el color
    //"color", se asigna a uno de sus vértices adyacentes.
    bool disponible[numVertices];
    for(int color = 0; color < numVertices; color++)
        disponible[color] = false;

    //Asignación de colores al resto de vertices
    for(int unssignedVert = 1; unssignedVert < numVertices; unssignedVert++){

        //Procesamiento de todos los vértices adyacentes y marcar los colores como "no disponible"
        list<int>::iterator i;
        for (i = adj[unssignedVert].begin(); i != adj[unssignedVert].end(); ++i)
            if(resultado[*i] != -1)
                disponible[resultado[*i]] = true;

        //Encontrar el primer color disponible
        int color;
        for (color = 0; color < numVertices; color++)
            if(disponible[color] == false)
                break;

        resultado[unssignedVert] = color;   //Asignar el color encontrado

        //Restaurar los valores de vuelta a "falso" para la siguiente iteración
        for (i = adj[unssignedVert].begin(); i  != adj[unssignedVert].end(); ++i)
            if(resultado[*i] != -1)
                disponible[resultado[*i]] = false;
    }

    //Impresión del resultado
    for(int unssignedVert = 0; unssignedVert < numVertices; unssignedVert++)
    cout << "Vertice " << unssignedVert << " ---> Color"
         << resultado[unssignedVert]   << endl;
}

//Main
int main(){
    Grafo g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Coloreando grafo 1\n";
    g1.Coloreado();

    Grafo g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "Coloreado grafo 2\n";
    g2.Coloreado();

    return 0;
}
