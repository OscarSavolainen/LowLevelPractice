
from typing import Dict

graph = {
    'a': ['b', 'c'],
    'b': ['d'],
    'c': ['e'],
    'd': ['f'],
    'e': [],
    'f': [],
}

start = 'a'
def BFS_with_queue(current: str, graph: Dict):
    """
    While queue has elements, keep going. Just add values to the queue.
    """

    queue = []
    queue.append(current)
    while (len(queue) > 0):
        current = queue.pop(0)
        print(f"{current}")

        for next in graph[current]:
            queue.append(next)

print("\n\nDFS with queue")
BFS_with_queue(start, graph)
