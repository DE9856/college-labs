# To implement the Travelling Salesman Problem using the nearest neighbor heuristic approach to find an approximate minimum cost path that visits all cities exactly once and returns to the starting city.

import networkx as nx
import matplotlib.pyplot as plt


def nearest_neighbor_tsp(cost):
    num_nodes = len(cost)
    visited = [False] * num_nodes

    path = [0]
    visited[0] = True
    total_cost = 0

    current = 0

    for _ in range(num_nodes - 1):
        next_city = min(
            (j for j in range(num_nodes) if not visited[j]),
            key=lambda j: cost[current][j]
        )

        total_cost += cost[current][next_city]
        visited[next_city] = True
        path.append(next_city)
        current = next_city

    # Return to starting city
    total_cost += cost[current][0]
    path.append(0)

    return total_cost, path


def plot_tsp(cost, path):
    G = nx.Graph()
    num_nodes = len(cost)

    pos = nx.circular_layout(range(num_nodes))

    # Add edges with weights
    for i in range(num_nodes):
        for j in range(i + 1, num_nodes):
            G.add_edge(i, j, weight=cost[i][j])

    plt.figure(figsize=(6, 6))

    # Draw full graph
    nx.draw(
        G, pos,
        with_labels=True,
        node_color='lightblue',
        edge_color='gray',
        node_size=1000,
        font_size=12
    )

    # Highlight TSP path
    path_edges = list(zip(path, path[1:]))

    nx.draw_networkx_edges(
        G, pos,
        edgelist=path_edges,
        edge_color='red',
        width=2
    )

    plt.title("TSP Solution using Nearest Neighbor Heuristic")
    plt.show()


if __name__ == "__main__":
    cost = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]

    res_cost, res_path = nearest_neighbor_tsp(cost)

    print(f"Approximate minimum cost: {res_cost}")
    print(f"Path taken: {res_path}")

    plot_tsp(cost, res_path)
