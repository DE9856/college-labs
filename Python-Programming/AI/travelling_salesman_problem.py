import matplotlib.pyplot as plt
import networkx as nx

def nearest_neighbour_tsp(cost):
    num_nodes = len(cost)
    visited = [False]*num_nodes
    path = [0]
    visited[0] = True
    total_cost = 0
    current = 0

    for _ in range(num_nodes-1):
        next_city = min((j for j in range(num_nodes) if not visited[j]), key = lambda j: cost[current][j])
        total_cost+=cost[current][next_city]
        visited[next_city] = True
        path.append(next_city)
        current = next_city
    
    total_cost+=cost[current][0]
    path.append(0)

    return total_cost, path

def plot_tsp(cost, path):
    G = nx.Graph()
    num_nodes = len(cost)
    pos = nx.circular_layout(range(num_nodes))
    for i in range(num_nodes):
        for j in range(i+1, num_nodes):
            G.add_edge(i,j,weight = cost[i][j])

    plt.figure(figsize = (10,10))
    nx.draw(G, pos, with_labels = True, node_color = 'lightblue', node_size = 1200, font_size = 12)
    path_edges = list(zip(path, path[1:]))
    nx.draw_networkx_edges(G, pos, edgelist = path_edges, edge_color='black', width = 2)
    plt.title("Travelling Salesman Problem")
    plt.show()

if __name__ == "__main__":
    cost = [
        [0,10,15,20],
        [10,0,35,25],
        [15,35,0,30],
        [20,25,30,0],
    ]
    res_cost, res_path = nearest_neighbour_tsp(cost)
    print("Approximate Minimum Cost: ", res_cost)
    print("Path Taken: ")
    print(*res_path, sep = '\n')
    plot_tsp(cost, res_path)
