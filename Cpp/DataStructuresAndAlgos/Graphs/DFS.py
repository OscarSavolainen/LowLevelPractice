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
def DFS(current: str, graph: Dict):
    print(f"Current node: {current}")
    next_nodes = graph[current]
    # Base case 1: we have reached the end of this path and there are no "next nodes"
    if next_nodes == []:
        return
    
    # Base case 2: there are more nodes to traverse from this node
    for next in next_nodes:
        DFS(next, graph)


DFS(start, graph) 

def DFS_with_stack(current: str, graph: Dict):
    """
    Whiel stack has elements, keep going. Just add values to the stack.
    Same for BFS, in BFS one uses a queue. Otherwise completely the same!
    """

    stack = []
    stack.append(current)
    while (len(stack) > 0):
        current = stack.pop()
        print(f"{current}")

        for next in graph[current]:
            stack.append(next)

print("\n\nDFS with stack")
DFS_with_stack(start, graph)
