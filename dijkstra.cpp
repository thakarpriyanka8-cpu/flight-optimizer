#include "graph.h"
#include <climits>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

// ==========================================
// FUNCTION 1 - Find minimum COST path
// ==========================================
void dijkstraCost(vector<vector<Flight>>& adjList, 
                  vector<Airport>& airports, 
                  int src, int dest) {

    int n = airports.size();
    
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    
    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currCost = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if (currCost > dist[currNode]) continue;

        for (auto flight : adjList[currNode]) {
            int newCost = dist[currNode] + flight.cost;

            if (newCost < dist[flight.destination]) {
                dist[flight.destination] = newCost;
                parent[flight.destination] = currNode;
                pq.push({newCost, flight.destination});
            }
        }
    }

    cout << "\n========================================" << endl;
    if (dist[dest] == INT_MAX) {
        cout << "No route found between " 
             << airports[src].code 
             << " and " 
             << airports[dest].code << endl;
    } else {
        cout << "MINIMUM COST ROUTE FOUND" << endl;
        cout << "========================================" << endl;

        vector<string> path;
        int curr = dest;
        while (curr != -1) {
            path.push_back(airports[curr].city);
            curr = parent[curr];
        }

        cout << "Route     : ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
        cout << "Total Cost: Rs." << dist[dest] << endl;
    }
    cout << "========================================" << endl;
}

// ==========================================
// FUNCTION 2 - Find minimum DISTANCE path
// ==========================================
void dijkstraDistance(vector<vector<Flight>>& adjList,
                      vector<Airport>& airports,
                      int src, int dest) {

    int n = airports.size();

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if (currDist > dist[currNode]) continue;

        for (auto flight : adjList[currNode]) {
            int newDist = dist[currNode] + flight.distance;

            if (newDist < dist[flight.destination]) {
                dist[flight.destination] = newDist;
                parent[flight.destination] = currNode;
                pq.push({newDist, flight.destination});
            }
        }
    }

    cout << "\n========================================" << endl;
    if (dist[dest] == INT_MAX) {
        cout << "No route found between "
             << airports[src].code
             << " and "
             << airports[dest].code << endl;
    } else {
        cout << "SHORTEST DISTANCE ROUTE FOUND" << endl;
        cout << "========================================" << endl;

        vector<string> path;
        int curr = dest;
        while (curr != -1) {
            path.push_back(airports[curr].city);
            curr = parent[curr];
        }

        cout << "Route         : ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
        cout << "Total Distance: " << dist[dest] << "km" << endl;
    }
    cout << "========================================" << endl;
}

// ==========================================
// FUNCTION 3 - Fewest Layovers (BFS)
// ==========================================
void bfsLayovers(vector<vector<Flight>>& adjList,
                 vector<Airport>& airports,
                 int src, int dest) {

    int n = airports.size();

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();

        if (currNode == dest) break;

        for (auto flight : adjList[currNode]) {
            if (!visited[flight.destination]) {
                visited[flight.destination] = true;
                parent[flight.destination] = currNode;
                q.push(flight.destination);
            }
        }
    }

    cout << "\n========================================" << endl;
    if (!visited[dest]) {
        cout << "No route found between "
             << airports[src].code
             << " and "
             << airports[dest].code << endl;
    } else {
        cout << "FEWEST LAYOVERS ROUTE FOUND" << endl;
        cout << "========================================" << endl;

        vector<string> path;
        int curr = dest;
        while (curr != -1) {
            path.push_back(airports[curr].city);
            curr = parent[curr];
        }

        int layovers = path.size() - 2;

        cout << "Route    : ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;

        if (layovers <= 0) {
            cout << "Layovers : Non-stop flight!" << endl;
        } else {
            cout << "Layovers : " << layovers << endl;
        }
    }
    cout << "========================================" << endl;
}
