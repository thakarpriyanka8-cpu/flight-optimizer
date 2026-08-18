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
    
    // Step 1: Set all distances to infinity
    vector<int> dist(n, INT_MAX);
    
    // Step 2: Track which airport we came from
    vector<int> parent(n, -1);
    
    // Step 3: Min heap priority queue {cost, airportId}
    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;

    // Step 4: Start from source
    dist[src] = 0;
    pq.push({0, src});

    // Step 5: Keep exploring until queue empty
    while (!pq.empty()) {
        
        // Pick airport with minimum cost
        int currCost = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        // Skip if already processed
        if (currCost > dist[currNode]) continue;

        // Explore all flights from current airport
        for (auto flight : adjList[currNode]) {
            int newCost = dist[currNode] + flight.cost;

            // If cheaper path found → update
            if (newCost < dist[flight.destination]) {
                dist[flight.destination] = newCost;
                parent[flight.destination] = currNode;
                pq.push({newCost, flight.destination});
            }
        }
    }

    // Step 6: Print result
    cout << "\n========================================" << endl;
    if (dist[dest] == INT_MAX) {
        cout << "No route found between " 
             << airports[src].code 
             << " and " 
             << airports[dest].code << endl;
    } else {
        cout << "MINIMUM COST ROUTE FOUND" << endl;
        cout << "========================================" << endl;

        // Trace back the path using parent array
        vector<string> path;
        int curr = dest;
        while (curr != -1) {
            path.push_back(airports[curr].city);
            curr = parent[curr];
        }

        // Path is reversed so print backwards
        cout << "Route    : ";
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

    // All distances start as infinity
    vector<int> dist(n, INT_MAX);

    // Track path
    vector<int> parent(n, -1);

    // Min heap priority queue
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    // Start from source
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        // Skip outdated entries
        if (currDist > dist[currNode]) continue;

        // Explore all flights from current airport
        for (auto flight : adjList[currNode]) {

            // ONLY DIFFERENCE FROM FUNCTION 1
            // Using flight.distance instead of flight.cost
            int newDist = dist[currNode] + flight.distance;

            if (newDist < dist[flight.destination]) {
                dist[flight.destination] = newDist;
                parent[flight.destination] = currNode;
                pq.push({newDist, flight.destination});
            }
        }
    }

    // Print result
    cout << "\n========================================" << endl;
    if (dist[dest] == INT_MAX) {
        cout << "No route found between "
             << airports[src].code
             << " and "
             << airports[dest].code << endl;
    } else {
        cout << "SHORTEST DISTANCE ROUTE FOUND" << endl;
        cout << "========================================" << endl;

        // Trace path backwards using parent array
        vector<string> path;
        int curr = dest;
        while (curr != -1) {
            path.push_back(airports[curr].city);
            curr = parent[curr];
        }

        // Print path in correct order
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