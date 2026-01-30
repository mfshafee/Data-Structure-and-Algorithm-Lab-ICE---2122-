#include <iostream>
#include <iomanip>
using namespace std;

class WarshallAlgorithm {
private:
    int vertices;
    int** adjacencyMatrix;
    int** pathMatrix;
    
public:
    WarshallAlgorithm(int n) {
        vertices = n;
        
        // Allocate memory for matrices
        adjacencyMatrix = new int*[vertices];
        pathMatrix = new int*[vertices];
        
        for (int i = 0; i < vertices; i++) {
            adjacencyMatrix[i] = new int[vertices];
            pathMatrix[i] = new int[vertices];
        }
    }
    
    // Destructor to free memory
    ~WarshallAlgorithm() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjacencyMatrix[i];
            delete[] pathMatrix[i];
        }
        delete[] adjacencyMatrix;
        delete[] pathMatrix;
    }
    
    // Input adjacency matrix
    void inputAdjacencyMatrix() {
        cout << "Enter the adjacency matrix (" << vertices << "x" << vertices << "):" << endl;
        cout << "(Enter 1 if there's a direct edge, 0 otherwise)" << endl;
        
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cin >> adjacencyMatrix[i][j];
            }
        }
    }
    
    // Display a matrix
    void displayMatrix(int** matrix, string name) {
        cout << "\n" << name << ":" << endl;
        cout << "     ";
        for (int i = 0; i < vertices; i++) {
            cout << setw(3) << (char)('A' + i);
        }
        cout << endl;
        
        for (int i = 0; i < vertices; i++) {
            cout << (char)('A' + i) << " [ ";
            for (int j = 0; j < vertices; j++) {
                cout << setw(3) << matrix[i][j];
            }
            cout << " ]" << endl;
        }
    }
    
    // Warshall's Algorithm to find path matrix
    void findPathMatrix() {
        // Initialize path matrix with adjacency matrix
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                pathMatrix[i][j] = adjacencyMatrix[i][j];
            }
        }
        
        // Apply Warshall's algorithm
        // For each intermediate vertex k
        for (int k = 0; k < vertices; k++) {
            // For each source vertex i
            for (int i = 0; i < vertices; i++) {
                // For each destination vertex j
                for (int j = 0; j < vertices; j++) {
                    // If there's a path from i to k and k to j,
                    // then there's a path from i to j
                    pathMatrix[i][j] = pathMatrix[i][j] || 
                                      (pathMatrix[i][k] && pathMatrix[k][j]);
                }
            }
            
            // Display intermediate steps (optional)
            cout << "\nAfter considering vertex " << (char)('A' + k) 
                 << " as intermediate:" << endl;
            displayMatrix(pathMatrix, "Path Matrix P^" + to_string(k+1));
        }
    }
    
    // Main function to run Warshall's algorithm
    void solve() {
        inputAdjacencyMatrix();
        displayMatrix(adjacencyMatrix, "Adjacency Matrix");
        
        cout << "\n--- Applying Warshall's Algorithm ---" << endl;
        findPathMatrix();
        
        cout << "\n==================================" << endl;
        displayMatrix(pathMatrix, "Final Path Matrix");
        cout << "==================================" << endl;
        
        // Show what the path matrix means
        cout << "\nInterpretation:" << endl;
        cout << "1 in position (i,j) means there exists a path from vertex i to vertex j" << endl;
        cout << "0 means there is no path from vertex i to vertex j" << endl;
    }
};

int main() {
    int n;
    
    cout << "=== Warshall's Algorithm: Path Matrix ===" << endl;
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    
    WarshallAlgorithm warshall(n);
    warshall.solve();
    
    return 0;
}