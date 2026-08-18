#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "   FLIGHT ROUTE OPTIMIZATION SYSTEM     " << endl;
    cout << "========================================" << endl;

    // Build graph
    Graph g;
    g.addAirport("DEL", "Delhi");       // 0
    g.addAirport("BOM", "Mumbai");      // 1
    g.addAirport("BLR", "Bangalore");   // 2
    g.addAirport("CCU", "Kolkata");     // 3
    g.addAirport("HYD", "Hyderabad");   // 4

    g.addFlight(0, 1, 5000, 1400, 120); // DEL → BOM
    g.addFlight(0, 2, 6000, 2150, 150); // DEL → BLR
    g.addFlight(0, 3, 8000, 1500, 140); // DEL → CCU
    g.addFlight(1, 3, 7000, 1900, 130); // BOM → CCU
    g.addFlight(1, 2, 3000, 980,  90);  // BOM → BLR
    g.addFlight(2, 3, 4000, 1700, 110); // BLR → CCU
    g.addFlight(0, 4, 4500, 1250, 110); // DEL → HYD
    g.addFlight(4, 3, 5500, 1400, 120); // HYD → CCU

    int choice;

    // Keep showing menu until user exits
    while (true) {

        // Show menu
        cout << "\n========================================" << endl;
        cout << "            MAIN MENU                   " << endl;
        cout << "========================================" << endl;
        cout << "1. Show All Airports" << endl;
        cout << "2. Show All Routes" << endl;
        cout << "3. Find Minimum COST Route" << endl;
        cout << "4. Find Shortest DISTANCE Route" << endl;
        cout << "5. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Option 1 - Show airports
        if (choice == 1) {
            g.displayAirports();
        }

        // Option 2 - Show all routes
        else if (choice == 2) {
            g.displayRoutes();
        }

        // Option 3 - Minimum cost
        else if (choice == 3) {
            int src, dest;
            cout << "\n--- Available Airports ---" << endl;
            g.displayAirports();
            cout << "\nEnter Source Airport ID      : ";
            cin >> src;
            cout << "Enter Destination Airport ID : ";
            cin >> dest;
            dijkstraCost(g.getAdjList(), g.getAirports(), src, dest);
        }

        // Option 4 - Shortest distance
        else if (choice == 4) {
            int src, dest;
            cout << "\n--- Available Airports ---" << endl;
            g.displayAirports();
            cout << "\nEnter Source Airport ID      : ";
            cin >> src;
            cout << "Enter Destination Airport ID : ";
            cin >> dest;
            dijkstraDistance(g.getAdjList(), g.getAirports(), src, dest);
        }

        // Option 5 - Exit
        else if (choice == 5) {
            cout << "\nThank you for using Flight Optimizer!" << endl;
            cout << "Goodbye!" << endl;
            break;
        }

        // Wrong input
        else {
            cout << "\nInvalid choice! Please enter 1-5." << endl;
        }
    }

    return 0;
}