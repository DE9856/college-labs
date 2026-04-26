import matplotlib.pyplot as plt
import networkx as nx

def nearest_neighbour_tsp(cost):
    num_nodes = len(cost)
    visited = [False]*num_nodes
    path = [0]
    current = 0
    visited[0] = True
    path_cost = 0

    for _ in range(len(cost)-1):
        next_city = min((j for j in range(num_nodes) if not visited[j]), key = lambda j: cost[current][j])
        path_cost +=cost[current][next_city]
        visited[next_city] = True
        path.append(next_city)
        current = next_city
    
    path_cost +=cost[current][0]
    path.append(0)
    return path_cost, path

def visualize_graph(cost, path):
    G = nx.Graph()
    num_nodes = len(cost)
    pos = nx.circular_layout(range(num_nodes))
    for i in range(num_nodes):
        for j in range(i+1, num_nodes):
            G.add_edge(i,j,weight = cost[i][j])
    
    plt.figure(figsize=(5,5))
    nx.draw(G, pos, with_labels = True, node_color='lightblue', node_size = 1500, font_color='black')
    edge_list = list(zip(path, path[1:]))
    nx.draw_networkx_edges(G, pos, edgelist = edge_list, edge_color='red', width=3)

    plt.title("Travelling Salesman Problem")
    plt.show()

cost = [
    [0,10,15,20],
    [10,0,35,25],
    [15,35,0,30],
    [20,25,30,0]
]

res_cost, res_path = nearest_neighbour_tsp(cost)
print("The resultant cost is: ", res_cost)
print("The path taken is: ", res_path)
visualize_graph(cost, res_path)
    
