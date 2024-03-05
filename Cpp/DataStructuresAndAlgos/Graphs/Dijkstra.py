 # Implement Dijkstra's search algorithm

from typing import Dict, List, Set

adj_list = {
    'a': {'b': 3, 'c': 4},
    'b': {'a': 3, 'c': 1, 'd': 1, 'e': 3},
    'c': {'b': 1, 'a': 4, 'e': 2, 'f': 4},
    'd': {'b': 1, 'g': 3},
    'e': {'b': 3, 'c': 2, 'f': 1},
    'f': {'c': 4, 'e': 1, 'g': 2},
    'g': {'f': 2, 'd': 3},
}

visited, prev, distances = {}, {}, {}
for key in adj_list.keys():
    prev[key]= None
    distances[key] = 1000
    visited[key] = False


print('visited', visited)
print(distances)
print(prev)

start = 'a'
target = 'f'
distances[start] = 0
current = start

while any(v is False for v in visited.values()):

    # Step 1: update values
    visited[current] = True
    nexts = adj_list[current] # Returns dict of connections, each is a dict of key and relative distance
    for next_key, next_val in nexts.items():
        if next_val + distances[current] < distances[next_key]:
            # The new route is faster than the current marked distance, so we update the distance and prev
            distances[next_key] = next_val + distances[current]
            prev[next_key] = current

    print('Prev: ', prev)
    print('Distances:', distances)

    # Step 2: move to closest node to start
    current_min = 1000
    current_min_key = None
    for key in distances:
        if distances[key] < current_min and visited[key] == False:
            current_min = distances[key]
            current_min_key = key

    current = current_min_key
    print('Next step: ', current)

print(f"Shortest distance to {target} from {start} is {distances[target]}")