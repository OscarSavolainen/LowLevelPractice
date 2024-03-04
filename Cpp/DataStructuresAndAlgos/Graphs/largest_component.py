
from typing import Dict, List, Set

edges = [
    ['i', 'j'],
    ['k', 'i'],
    ['k', 'j'],
    ['m', 'k'],
    ['l', 'k'],
    ['o', 'n'],
    ['t', 'a'],
]

adjacency_list = {}

for pair in edges:
    if pair[0] not in adjacency_list:
        adjacency_list[pair[0]] = [pair[1]]
    else:
        adjacency_list[pair[0]].append(pair[1])
    
    if pair[1] not in adjacency_list:
        adjacency_list[pair[1]] = [pair[0]]
    else:
        adjacency_list[pair[1]].append(pair[0])

print(adjacency_list)


def traverse(start, adj_list):
    stack = []
    visited = set()

    stack.append(start)
    while (len(stack) > 0):
        current = stack.pop()
        visited.add(current)

        for next in adj_list[current]:
            if next not in visited:
                stack.append(next)

    return visited
                


def largest_component(adjacency_list):
    global_visited = set()
    count = {}
    for i in adjacency_list.keys():
        visited = traverse(i, adjacency_list)
        if not any(v in global_visited for v in visited):
            count[i] = len(visited)
            for v in visited:
                global_visited.add(v)

    print(count)

largest_component(adjacency_list)
        


