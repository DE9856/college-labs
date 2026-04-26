import matplotlib.pyplot as plt
import networkx as nx
import heapq

def is_valid_state(missionaries_left, cannibals_left, boat_left):
    missionaries_right = 3 - missionaries_left
    cannibals_right = 3 - cannibals_left
    if missionaries_left<0 or missionaries_right<0 or cannibals_left<0 or cannibals_right<0:
        return False
    if(missionaries_left>0 and missionaries_left<cannibals_left) or (missionaries_right>0 and missionaries_right<cannibals_right):
        return False
    return True

def get_successors(state):
    missionaries, cannibals, boat = state
    possible_moves = [(1,0), (2,0), (0,1), (0,2), (1,1)]
    successors = []

    for m,c in possible_moves:
        if boat:
            new_state = (missionaries-m, cannibals-c,0)
        else:
            new_state = (missionaries+m, cannibals+c,1)
        if is_valid_state(*new_state):
            successors.append(new_state)
    
    return successors

def heuristic(state):
    missionaries_left, cannibals_left, _=state
    return missionaries_left+cannibals_left

def bfs():
    initial_state = (3,3,1)
    goal_state = (0,0,0)

    priority_queue = []
    heapq.heappush(priority_queue, (heuristic(initial_state), initial_state, []))
    visited = set()

    while priority_queue:
        _, state, path = heapq.heappop(priority_queue)
        if state in visited:
            continue
        visited.add(state)
        new_path = path+[state]

        if state==goal_state:
            return new_path

        for successor in get_successors(state):
            heapq.heappush(priority_queue, (heuristic(successor), successor, new_path))

    return None

solution_path = bfs()

print("Solution Path: ")
for step in solution_path:
    print(step)

G = nx.DiGraph()
for i in range(len(solution_path)-1):
    G.add_edge(solution_path[i], solution_path[i+1])

pos = nx.spring_layout(G)
plt.figure(figsize=(8,6))

nx.draw(G, pos, with_labels = True, node_color='lightblue', node_size=1200,font_size=8)
nx.draw_networkx_edges(G, pos, edgelist = list(G.edges()), edge_color='red', width=2)

plt.title("Missionaries-Cannibals Problem")
plt.show()

