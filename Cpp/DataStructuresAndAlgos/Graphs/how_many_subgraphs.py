"""
A list of edges to an adjacency list.
"""

from typing import Dict, List, Set

edges = [
    ['i', 'j'],
    ['k', 'i'],
    ['k', 'j'],
    ['m', 'k'],
    ['l', 'k'],
    ['o', 'n'],
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


def traverse(current: str, adjacency_list: Dict) -> List:
    stack = [current]
    visited = set()

    while (len(stack) > 0):
        current = stack.pop()
        #print(f"At node {current}")
        visited.add(current)
        nexts = adjacency_list[current]

        for next in nexts:
            if next not in visited:
                stack.append(next)

    return visited

#traverse('i', adjacency_list)


def count_subgraphs(adjacency_list: Dict) -> Set:
    global_visited = set()
    count = 0
    for element in adjacency_list.keys():
        visited = traverse(element, adjacency_list)
        count += int(not any(v in global_visited for v in visited))
        for v in visited:
            global_visited.add(v)

    #import ipdb
    #ipdb.set_trace()
    return count

print(f"Subgraphs in graph: {count_subgraphs(adjacency_list)}")