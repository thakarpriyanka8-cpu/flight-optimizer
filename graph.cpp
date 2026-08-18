#include "graph.h"

Graph::Graph() {
    numAirports = 0;
}

void Graph::addAirport(string code, string city) {
    Airport a;
    a.id = numAirports;
    a.code = code;
    a.city = city;
    airports.push_back(a);
    adjList.push_back({});  // empty list for this airport
    numAirports++;
}

void Graph::addFlight(int src, int dest, int cost, int dist, int dur) {
    Flight f;
    f.destination = dest;
    f.cost = cost;
    f.distance = dist;
    f.duration = dur;
    adjList[src].push_back(f);
}

void Graph::displayAirports() {
    cout << "\n--- AIRPORTS ---" << endl;
    for (auto a : airports) {
        cout << "[" << a.id << "] " << a.code << " - " << a.city << endl;
    }
}

void Graph::displayRoutes() {
    cout << "\n--- ALL ROUTES ---" << endl;
    for (int i = 0; i < numAirports; i++) {
        for (auto f : adjList[i]) {
            cout << airports[i].code << " -> " << airports[f.destination].code
                 << "  Cost: Rs." << f.cost
                 << "  Distance: " << f.distance << "km"
                 << "  Time: " << f.duration << "min" << endl;
        }
    }
}

int Graph::getAirportCount() {
    return numAirports;
}

vector<vector<Flight>>& Graph::getAdjList() {
    return adjList;
}

vector<Airport>& Graph::getAirports() {
    return airports;
}