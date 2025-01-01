#ifndef GRAPH_H
#define GRAPH_H

typedef char infoGraph;

// Struktur untuk elemen Edge (sisi)
struct ElmEdge {
    struct ElmNode* node;
    ElmEdge* nextEdge;
};

// Struktur untuk elemen Node (simpul)
struct ElmNode {
    infoGraph info;
    int visited;
    ElmEdge* firstEdge;
    ElmNode* nextNode;
};

// Struktur untuk Graph
struct Graph {
    ElmNode* firstNode;
};

// Prototipe fungsi
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
ElmNode* FindNode(Graph G, infoGraph X);
void ConnectNode(ElmNode* N1, ElmNode* N2);
void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, ElmNode* N);
void PrintBFS(Graph G, ElmNode* N);

#endif
