#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// One flight route (edge in graph)
struct Flight {
    int destination;
    int cost;        // in rupees
    int distance;    // in km
    int duration;    // in minutes
};

// One airport (node in graph)
struct Airport {
    int id;
    string code;   // DEL, BOM, BLR
    string city;   // Delhi, Mumbai, Bangalore
};

// Graph class
class Graph {
private:
    int numAirports;
    vector<Airport> airports;
    vector<vector<Flight>> adjList;

public:
    Graph();
    void addAirport(string code, string city);
    void addFlight(int src, int dest, int cost, int dist, int dur);
    void displayAirports();
    void displayRoutes();
    int getAirportCount();
    vector<vector<Flight>>& getAdjList();
    vector<Airport>& getAirports();
};

// ↓ BOTH FUNCTIONS DECLARED HERE ↓

void dijkstraCost(vector<vector<Flight>>& adjList,
                  vector<Airport>& airports,
                  int src, int dest);

void dijkstraDistance(vector<vector<Flight>>& adjList,
                      vector<Airport>& airports,
                      int src, int dest);
                      
 void bfsLayovers(vector<vector<Flight>>& adjList,
                 vector<Airport>& airports,
                 int src, int dest);                    
                      

#endif