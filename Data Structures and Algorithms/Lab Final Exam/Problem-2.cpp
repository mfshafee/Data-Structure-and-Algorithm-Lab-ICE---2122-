#include<bits/stdc++.h>
using namespace std;
class WarshallAlgorithm {
private:
int vertices;
int** adjacencyMatrix;
int** pathMatrix;
    
    
public:
    WarshallAlgorithm(int n) {
        vertices = n;
        
       
        adjacencyMatrix = new int*[vertices];
        pathMatrix = new int*[vertices];
        
        for (int i = 0; i < vertices; i++) {
            adjacencyMatrix[i] = new int[vertices];
            pathMatrix[i] = new int[vertices];
        }
    }
    
    
    ~WarshallAlgorithm() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjacencyMatrix[i];
            delete[] pathMatrix[i];
        }
        delete[] adjacencyMatrix;
        delete[] pathMatrix;
    }
    
    
    void inputAdjacencyMatrix() {
        cout << "Enter the adjacency matrix (" << vertices << "x" << vertices << "):" << '\n';
        cout << "(Enter 1 if there's a direct link, 0 otherwise)" << '\n';
        
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cin >> adjacencyMatrix[i][j];
            }
        }
        
    }
    
    
    void displayMatrix(int** matrix, string name) {
        cout << "\n" << name << ":" << endl;
        cout << "     ";
        for (int i = 0; i < vertices; i++) {
            cout << setw(3) << (char)('1' + i);
        }
        cout << endl;
        
        for (int i = 0; i < vertices; i++) {
            cout << (char)('1' + i) << " [ ";
            for (int j = 0; j < vertices; j++) {
                cout << setw(3) << matrix[i][j];
            }
            cout << " ]" << endl;
        }
    }
    
    
    void findPathMatrix() {
        
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                pathMatrix[i][j] = adjacencyMatrix[i][j];
            }
        }
        
       
        for (int k = 0; k < vertices; k++) {
            
            for (int i = 0; i < vertices; i++) {
                
                for (int j = 0; j < vertices; j++) {
                    
                    pathMatrix[i][j] = pathMatrix[i][j] || 
                    (pathMatrix[i][k] && pathMatrix[k][j]);
                }
            }
            
           
            cout << "\nAfter considering Station- " << (char)('1' + k) 
                 << " as intermediate:" << endl;
            displayMatrix(pathMatrix, "Path Matrix P^" + to_string(k+1));
        }
    }
    
    
    
    void solve() {
        inputAdjacencyMatrix();
        displayMatrix(adjacencyMatrix, "Adjacency Matrix");
        
        
        findPathMatrix();
        
        
        displayMatrix(pathMatrix, "Final Path Matrix");
        
        
        cout << "\nInterpretation:" << '\n';
        cout << "1 in position (i,j) means there exists a path from vertex i to vertex j" << '\n';
        cout << "0 means there is no path from vertex i to vertex j" << '\n';
        
        
        
    }
    
    
    void checkReachability(int source, int destination) {
        
        int src = source - 1;
        int dest = destination - 1;
        
        
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            cout << "\nError: Invalid station numbers!" << endl;
            cout << "Please enter station numbers between 1 and " << vertices << '\n';
            return;
        }
        
        
        cout << "Reachability Query: S" << source << " -> S" << destination << '\n';
        
        
        if (pathMatrix[src][dest] == 1) {
            cout << "Result: YES" << '\n';
            cout << "Station S" << source << " CAN send a message to Station S" 
                 << destination << '\n';
            cout << "There exists a communication path between these stations." << '\n';
        } else {
            cout << "Result: NO" << '\n';
            cout << "Station S" << source << " CANNOT send a message to Station S" 
                 << destination << '\n';
            cout << "There is no communication path between these stations." << '\n';
        }
        
    }
};

int main() {
    int n;
    
    
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    WarshallAlgorithm warshall(n);
    warshall.solve();
    
    int x, y;
    cout << "\nEnter source and destination station: ";
    cin >> x >> y;

    warshall.checkReachability(x, y);
    
    return 0;
}