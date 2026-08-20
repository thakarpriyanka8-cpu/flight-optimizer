#  Flight Route Optimization System

A C++ project that models an airport network as a weighted directed graph 
and finds optimal flight routes using DSA algorithms.

---

## About The Project

This system helps users find the best flight route between two airports 
based on three different criteria:

- **Minimum Cost** → Cheapest route (Dijkstra's Algorithm)
- **Shortest Distance** → Least km route (Dijkstra's Algorithm)
- **Fewest Layovers** → Minimum stops route (BFS Algorithm)

---

##  Data Structures & Algorithms Used

| Concept | Usage |
|---|---|
| Weighted Directed Graph | Airport network representation |
| Adjacency List | Space efficient graph storage |
| Dijkstra's Algorithm | Minimum cost & shortest distance |
| BFS | Fewest layovers/stops |
| Min-Heap Priority Queue | Efficient node selection in Dijkstra |
| Parent Array | Path tracing |

---

##  Airport Network