#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

class ShortestPath {
private:
    int vertices;
    int** weightMatrix;
    
    // Find vertex with minimum distance that hasn't been visited
    int findMinDistance(int dist[], bool visited[]) {
        int minDist = INT_MAX;
        int minIndex = -1;
        
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
    
    // Print the path from source to destination
    void printPath(int parent[], int dest, vector<char>& path) {
        if (parent[dest] == -1) {
            path.push_back('A' + dest);
            return;
        }
        printPath(parent, parent[dest], path);
        path.push_back('A' + dest);
    }
    
public:
    ShortestPath(int n) {
        vertices = n;
        
        // Allocate memory for weight matrix
        weightMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            weightMatrix[i] = new int[vertices];
        }
    }
    
    // Destructor
    ~ShortestPath() {
        for (int i = 0; i < vertices; i++) {
            delete[] weightMatrix[i];
        }
        delete[] weightMatrix;
    }
    
    // Input weight matrix
    void inputWeightMatrix() {
        cout << "Enter the weight matrix (" << vertices << "x" << vertices << "):" << endl;
        cout << "(Enter weight for edge, 0 for no edge or same vertex, -1 for infinity)" << endl;
        
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                int weight;
                cin >> weight;
                if (weight == -1) {
                    weightMatrix[i][j] = INT_MAX;
                } else {
                    weightMatrix[i][j] = weight;
                }
            }
        }
    }
    
    // Display weight matrix
    void displayWeightMatrix() {
        cout << "\nWeight Matrix:" << endl;
        cout << "     ";
        for (int i = 0; i < vertices; i++) {
            cout << setw(6) << (char)('A' + i);
        }
        cout << endl;
        
        for (int i = 0; i < vertices; i++) {
            cout << (char)('A' + i) << " [ ";
            for (int j = 0; j < vertices; j++) {
                if (weightMatrix[i][j] == INT_MAX)
                    cout << setw(6) << "INF";
                else
                    cout << setw(6) << weightMatrix[i][j];
            }
            cout << " ]" << endl;
        }
    }
    
    // Dijkstra's Algorithm
    void dijkstra(int source, int destination) {
        int* dist = new int[vertices];      // Shortest distance from source
        bool* visited = new bool[vertices];  // Visited vertices
        int* parent = new int[vertices];     // To store the path
        
        // Initialize
        for (int i = 0; i < vertices; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
            parent[i] = -1;
        }
        
        dist[source] = 0;
        
        // Find shortest path for all vertices
        for (int count = 0; count < vertices - 1; count++) {
            int u = findMinDistance(dist, visited);
            
            if (u == -1) break;  // All remaining vertices are unreachable
            
            visited[u] = true;
            
            // Update distances of adjacent vertices
            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && weightMatrix[u][v] != INT_MAX && 
                    dist[u] != INT_MAX && 
                    dist[u] + weightMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + weightMatrix[u][v];
                    parent[v] = u;
                }
            }
        }
        
        // Display results
        cout << "\n=== Shortest Path Results ===" << endl;
        cout << "From vertex " << (char)('A' + source) 
             << " to vertex " << (char)('A' + destination) << endl;
        
        if (dist[destination] == INT_MAX) {
            cout << "No path exists!" << endl;
        } else {
            cout << "\nShortest distance: " << dist[destination] << endl;
            
            vector<char> path;
            printPath(parent, destination, path);
            
            cout << "Shortest path: ";
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) cout << " -> ";
            }
            cout << endl;
        }
        
        // Display all shortest paths from source
        cout << "\n=== All Shortest Paths from " << (char)('A' + source) << " ===" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "To " << (char)('A' + i) << ": ";
            if (dist[i] == INT_MAX) {
                cout << "No path" << endl;
            } else {
                cout << "Distance = " << dist[i] << ", Path: ";
                vector<char> path;
                printPath(parent, i, path);
                for (int j = 0; j < path.size(); j++) {
                    cout << path[j];
                    if (j < path.size() - 1) cout << " -> ";
                }
                cout << endl;
            }
        }
        
        // Clean up
        delete[] dist;
        delete[] visited;
        delete[] parent;
    }
    
    // Main solve function
    void solve() {
        inputWeightMatrix();
        displayWeightMatrix();
        
        char sourceChar, destChar;
        cout << "\nEnter source vertex (e.g., A): ";
        cin >> sourceChar;
        cout << "Enter destination vertex (e.g., D): ";
        cin >> destChar;
        
        int source = sourceChar - 'A';
        int destination = destChar - 'A';
        
        if (source < 0 || source >= vertices || destination < 0 || destination >= vertices) {
            cout << "Invalid vertices!" << endl;
            return;
        }
        
        dijkstra(source, destination);
    }
};

int main() {
    int n;
    
    cout << "=== Shortest Path using Dijkstra's Algorithm ===" << endl;
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    
    ShortestPath sp(n);
    sp.solve();
    
    return 0;
}