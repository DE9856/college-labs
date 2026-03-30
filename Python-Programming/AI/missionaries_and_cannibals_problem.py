# To solve the Missionaries and Cannibals problem using Best-First Search by exploring valid state transitions and ensuring that missionaries are never outnumbered by cannibals on either side.

import networkx as nx
import matplotlib.pyplot as plt
import heapq

def is_valid_state(missionaries_left, cannibals_left, boat_left):
    """Check if a state is valid: missionaries should never be outnumbered."""
    missionaries_right = 3 - missionaries_left
    cannibals_right = 3 - cannibals_left


    if missionaries_left < 0 or missionaries_right < 0 or \
cannibals_left < 0 or cannibals_right < 0:
        return False


    if (missionaries_left > 0 and missionaries_left < cannibals_left) or \
       (missionaries_right > 0 and missionaries_right < cannibals_right):
        return False


    return True
def get_successors(state):
    """Generate all possible successor states from the given state."""
    missionaries, cannibals, boat = state
    possible_moves = [(1, 0), (2, 0), (0, 1), (0, 2), (1, 1)]
    successors = []


    for m, c in possible_moves:
        if boat:  # Boat is on the left side
            new_state = (missionaries - m, cannibals - c, 0)
        else:  # Boat is on the right side
            new_state = (missionaries + m, cannibals + c, 1)
        if is_valid_state(*new_state):
            successors.append(new_state)
    return successors


def heuristic(state):
    """Heuristic function that estimates the distance to the goal."""
    missionaries_left, cannibals_left, _ = state
    return missionaries_left + cannibals_left  # Manhattan distance on the left side


def best_first_search():
    """Solve the problem using Best-First Search and return the path."""
    initial_state = (3, 3, 1)
    goal_state = (0, 0, 0)
   
    # Priority queue with the heuristic value as the priority (lowest first)
    priority_queue = []
    heapq.heappush(priority_queue, (heuristic(initial_state), initial_state, []))
    visited = set()

    while priority_queue:
        _, state, path = heapq.heappop(priority_queue)
        if state in visited:
            continue

        visited.add(state)
        new_path = path + [state]

        if state == goal_state:
            return new_path

        for successor in get_successors(state):
            heapq.heappush(priority_queue, (heuristic(successor), successor, new_path))


    return None


# Get solution path using Best-First Search
solution_path = best_first_search()


print("Solution Path:")
for step in solution_path:
    print(step)


# Create graph for visualization
G = nx.DiGraph()
edges = [(solution_path[i], solution_path[i + 1]) for i in range(len(solution_path) - 1)]
G.add_edges_from(edges)


# Draw the graph
plt.figure(figsize=(10, 6))
pos = nx.spring_layout(G)  # Positioning of nodes
nx.draw(G, pos, with_labels=True, node_size=3000, node_color="lightblue", edge_color="gray", font_size=10)
plt.title("Missionaries and Cannibals Problem Solution Path (Best-First Search)")
plt.show()
