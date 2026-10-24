#include <iostream>

int main() {
    // Vertices: A, B, C, D
    char vertices[] = {'A', 'B', 'C', 'D'};

    // Adjacency matrix
    int graph[4][4] = {
        {0, 3, 2, 0},  // A -> B = 3, A -> C = 2
        {0, 0, 0, 0},  // B
        {0, 1, 0, 0},  // C -> B = 1
        {4, 0, 0, 0}   // D -> A = 4
    };

    // Display the adjacency matrix
    std::cout << "Graph:\n\n";

    std::cout << "   ";
    for (int i = 0; i < 4; i++) {
        std::cout << vertices[i] << "   ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 4; i++) {
        std::cout << vertices[i] << "  ";

        for (int j = 0; j < 4; j++) {
            std::cout << graph[i][j] << "   ";
        }

        std::cout << std::endl;
    }

    return 0;
}