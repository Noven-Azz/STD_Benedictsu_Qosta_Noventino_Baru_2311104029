#include <iostream>
#include <queue>
#include "graph.h"

using namespace std;

// Membuat graph kosong
void CreateGraph(Graph &G) {
    G.firstNode = nullptr;
}

// Menambahkan node baru ke graph
void InsertNode(Graph &G, infoGraph X) {
    ElmNode* newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = nullptr;
    newNode->nextNode = G.firstNode;
    G.firstNode = newNode;
}

// Mencari node berdasarkan informasi
ElmNode* FindNode(Graph G, infoGraph X) {
    ElmNode* current = G.firstNode;
    while (current != nullptr) {
        if (current->info == X) {
            return current;
        }
        current = current->nextNode;
    }
    return nullptr; // Node tidak ditemukan
}

// Menyambungkan dua node dengan edge
void ConnectNode(ElmNode* N1, ElmNode* N2) {
    if (N1 != nullptr && N2 != nullptr) {
        // Menambahkan edge dari N1 ke N2
        ElmEdge* newEdge1 = new ElmEdge;
        newEdge1->node = N2;
        newEdge1->nextEdge = N1->firstEdge;
        N1->firstEdge = newEdge1;

        // Menambahkan edge dari N2 ke N1 (karena graph tak berarah)
        ElmEdge* newEdge2 = new ElmEdge;
        newEdge2->node = N1;
        newEdge2->nextEdge = N2->firstEdge;
        N2->firstEdge = newEdge2;
    }
}

// Mencetak informasi graph
void PrintInfoGraph(Graph G) {
    ElmNode* currentNode = G.firstNode;
    while (currentNode != nullptr) {
        cout << "Node " << currentNode->info << ": ";
        ElmEdge* currentEdge = currentNode->firstEdge;
        while (currentEdge != nullptr) {
            cout << currentEdge->node->info << " ";
            currentEdge = currentEdge->nextEdge;
        }
        cout << endl;
        currentNode = currentNode->nextNode;
    }
}

// Fungsi rekursif untuk DFS
void DFS(ElmNode* N) {
    if (N == nullptr || N->visited == 1) {
        return;
    }

    // Tandai node sebagai telah dikunjungi
    N->visited = 1;

    // Cetak informasi node
    cout << N->info << " ";

    // Rekursi untuk setiap edge yang terhubung
    ElmEdge* currentEdge = N->firstEdge;
    while (currentEdge != nullptr) {
        DFS(currentEdge->node);
        currentEdge = currentEdge->nextEdge;
    }
}

// Prosedur untuk memulai DFS dari node tertentu
void PrintDFS(Graph G, ElmNode* N) {
    // Reset status "visited" pada semua node
    ElmNode* currentNode = G.firstNode;
    while (currentNode != nullptr) {
        currentNode->visited = 0;
        currentNode = currentNode->nextNode;
    }

    // Panggil fungsi DFS mulai dari node N
    cout << "Hasil penelusuran DFS: ";
    DFS(N);
    cout << endl;
}

// Prosedur untuk memulai BFS dari node tertentu
void PrintBFS(Graph G, ElmNode* N) {
    if (N == nullptr) {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }

    // Reset status "visited" pada semua node
    ElmNode* currentNode = G.firstNode;
    while (currentNode != nullptr) {
        currentNode->visited = 0;
        currentNode = currentNode->nextNode;
    }

    // Inisialisasi queue untuk BFS
    queue<ElmNode*> Q;

    // Tandai node awal sebagai "visited" dan masukkan ke queue
    N->visited = 1;
    Q.push(N);

    cout << "Hasil penelusuran BFS: ";

    while (!Q.empty()) {
        // Ambil node dari depan queue
        ElmNode* current = Q.front();
        Q.pop();

        // Cetak informasi node
        cout << current->info << " ";

        // Masukkan semua node yang terhubung ke queue jika belum dikunjungi
        ElmEdge* currentEdge = current->firstEdge;
        while (currentEdge != nullptr) {
            if (currentEdge->node->visited == 0) {
                currentEdge->node->visited = 1;
                Q.push(currentEdge->node);
            }
            currentEdge = currentEdge->nextEdge;
        }
    }

    cout << endl;
}
