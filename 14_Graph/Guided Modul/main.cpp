#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    // Tambahkan node
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');

    // Hubungkan node
    ElmNode* A = FindNode(G, 'A');
    ElmNode* B = FindNode(G, 'B');
    ElmNode* C = FindNode(G, 'C');
    ElmNode* D = FindNode(G, 'D');
    ElmNode* E = FindNode(G, 'E');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(C, E);
    ConnectNode(D, E);

    // Cetak graph
    PrintInfoGraph(G);

    // Penelusuran DFS
    PrintDFS(G, A);

    // Penelusuran BFS
    PrintBFS(G, A);

    return 0;
}
