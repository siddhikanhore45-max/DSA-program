#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

const int N = 6;

class Graph {
private:
    char city[N][20];
    int adj[N][N];

public:
    Graph () {
        strcpy(city[0], "Sangamner");
        strcpy(city[1], "Nashik");
        strcpy(city[2], "Pune");
        strcpy(city[3], "Shirdi");
        strcpy(city[4], "Ahmednagar");
        strcpy(city[5], "Mumbai");

        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                adj[i][j] = 0;
            }
        }

        
        addRoad(0, 1, 70);   
        addRoad(0, 2, 160);  
        addRoad(0, 3, 40);   
        addRoad(0, 4, 70);   
        addRoad(1, 5, 170);  
        addRoad(2, 5, 150);  
        addRoad(3, 4, 80); 
        addRoad(4, 2, 120);  
    }

    
    void addRoad(int u, int v, int distance) {
        adj[u][v] = distance;
        adj[v][u] = distance;
    }

    
    void displayCities() {
        cout << "\nAvailable Cities:\n";
        for (int i = 0; i < N; i++) {
            cout << i + 1 << ". " << city[i] << '\n';
        }
    }

    
    void displayRoads() {
        cout << "\nRoad Connections (sample distance in km):\n";
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (adj[i][j] > 0) {
                    cout << city[i] << " - " << city[j]
                         << " : " << adj[i][j] << " km\n";
                }
            }
        }
    }

    
    void printPath(int parent[], int vertex) {
        if (parent[vertex] == -1) {
            cout << city[vertex];
            return;
        }
        printPath(parent, parent[vertex]);
        cout << " -> " << city[vertex];
    }

    
    void shortestPath(int source, int destination) {
        int dist[N];
        int parent[N];
        bool visited[N];

        
        for (int i = 0; i < N; i++) {
            dist[i] = INT_MAX;
            parent[i] = -1;
            visited[i] = false;
        }

        dist[source] = 0;

        
        for (int count = 0; count < N - 1; count++) {
            int u = -1;
            int minDist = INT_MAX;

            for (int i = 0; i < N; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            
            if (u == -1) {
                break;
            }

            visited[u] = true;

            
            for (int v = 0; v < N; v++) {
                if (adj[u][v] > 0 && !visited[v] &&
                    dist[u] != INT_MAX &&
                    dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                }
            }
        }

        if (dist[destination] == INT_MAX) {
            cout << "\nNo route available between these cities.\n";
        } else {
            cout << "\nShortest Route: ";
            printPath(parent, destination);
            cout << "\nMinimum Distance: " << dist[destination] << " km\n";
        }
    }
};

int main() {
    Graph g;
    int choice;
    int source, destination;

    do {
        cout << "\n===== SHORTEST PATH FINDER =====\n";
        cout << "1. Display Cities\n";
        cout << "2. Display Road Connections\n";
        cout << "3. Find Shortest Path\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.displayCities();
                break;

            case 2:
                g.displayRoads();
                break;

            case 3:
                g.displayCities();

                cout << "\nEnter source city number: ";
                cin >> source;
                cout << "Enter destination city number: ";
                cin >> destination;

                if (source < 1 || source > N ||
                    destination < 1 || destination > N) {
                    cout << "Invalid city number! Please choose 1 to "
                         << N << ".\n";
                } else if (source == destination) {
                    cout << "\nShortest Route: ";
                    cout << "Same city (" << source << ")\n";
                    cout << "Minimum Distance: 0 km\n";
                } else {
                    g.shortestPath(source - 1, destination - 1);
                }
                break;

            case 4:
                cout << "Thank you for using the application!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}/*
===== SHORTEST PATH FINDER =====
1. Display Cities
2. Display Road Connections
3. Find Shortest Path
4. Exit
Enter your choice: 1

Available Cities:
1. Sangamner
2. Nashik
3. Pune
4. Shirdi
5. Ahmednagar
6. Mumbai

===== SHORTEST PATH FINDER =====
1. Display Cities
2. Display Road Connections
3. Find Shortest Path
4. Exit
Enter your choice: 2

Road Connections (sample distance in km):
Sangamner - Nashik : 70 km
Sangamner - Pune : 160 km
Sangamner - Shirdi : 40 km
Sangamner - Ahmednagar : 70 km
Nashik - Mumbai : 170 km
Pune - Ahmednagar : 120 km
Pune - Mumbai : 150 km
Shirdi - Ahmednagar : 80 km

===== SHORTEST PATH FINDER =====
1. Display Cities
2. Display Road Connections
3. Find Shortest Path
4. Exit
Enter your choice: 3

Available Cities:
1. Sangamner
2. Nashik
3. Pune
4. Shirdi
5. Ahmednagar
6. Mumbai

Enter source city number: 1
Enter destination city number: 6

Shortest Route: Sangamner -> Nashik -> Mumbai
Minimum Distance: 240 km

===== SHORTEST PATH FINDER =====
1. Display Cities
2. Display Road Connections
3. Find Shortest Path
4. Exit
Enter your choice: 3

Available Cities:
1. Sangamner
2. Nashik
3. Pune
4. Shirdi
5. Ahmednagar
6. Mumbai

Enter source city number: 4
Enter destination city number: 3

Shortest Route: Shirdi -> Sangamner -> Pune
Minimum Distance: 200 km

===== SHORTEST PATH FINDER =====
1. Display Cities
2. Display Road Connections
3. Find Shortest Path
4. Exit
Enter your choice: 3

Available Cities:
1. Sangamner
2. Nashik
3. Pune
4. Shirdi
5. Ahmednagar
6. Mumbai

Enter source city number: 2
Enter destination city number: 4

Shortest Route: Nashik -> Sangamner -> Shirdi
Minimum Distance: 110 km

===== SHORTEST PATH FINDER =====
1. Display Cities
2. Display Road Connections
3. Find Shortest Path
4. Exit
Enter your choice: 3

Available Cities:
1. Sangamner
2. Nashik
3. Pune
4. Shirdi
5. Ahmednagar
6. Mumbai

Enter source city number: 5
Enter destination city number: 5

Shortest Route: Same city (5)
Minimum Distance: 0 km

===== SHORTEST PATH FINDER =====
1. Display Cities
2. Display Road Connections
3. Find Shortest Path
4. Exit
Enter your choice: 3

Available Cities:
1. Sangamner
2. Nashik
3. Pune
4. Shirdi
5. Ahmednagar
6. Mumbai

Enter source city number: 1
Enter destination city number: 7
Invalid city number! Please choose 1 to 6.

===== SHORTEST PATH FINDER =====
1. Display Cities
2. Display Road Connections
3. Find Shortest Path
4. Exit
Enter your choice: 4
Thank you for using the application!

--------------------------------






*/

