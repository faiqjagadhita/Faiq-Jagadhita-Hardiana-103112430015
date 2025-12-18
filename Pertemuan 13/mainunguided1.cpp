#include "graph_unguided.h"

int main() {
    Graph G;
    CreateGraph(G);

    // Insert node A sampai H
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // Hubungan sesuai ilustrasi graph
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H');

    cout << "Isi Graph Tidak Berarah:" << endl;
    PrintInfoGraph(G);

    cout << "DFS dari node A: ";
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));
    cout << endl;

    cout << "BFS dari node A: ";
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));
    cout << endl;

    return 0;
}
