# Just to test I cna impelement this in Python
import ipdb
from typing import List

class Node:
    def __init__(self, value):
        self.value = value
        self.prev = None
        self.next : List = []

class Tree:
    def __init__(self):
        self.root: Node = None

    def addNode(self, value, parent: Node = None):
        new_node = Node(value)
        if not self.root:
            self.root = new_node
        
        else:
            assert parent, "Parent node should be provided"
            parent.next.append(new_node)
            new_node.prev = parent

    def search(self, value) -> Node:
        return searchSubTree(self.root, value)


    def traverse(self):
        traverseSubTree(self.root)

        
def searchSubTree(current: Node, target) -> Node:

    # Base case 1:
    # We have reached a null Node, so we return False
    if not current:
        return None
    
    # Base case 2:
    # We have reached the target node, so we return that Node
    if current.value == target:
        return current
    
    for next in current.next:
        result = searchSubTree(next, target)
        if result:
            return result


def traverseSubTree(current: Node):

    # Base case 1:
    # We have reached a null Node, so we return False
    if not current:
        return
    
    # We have not reached a null Node, we print the value and keep recursing
    print(f"Printing current value: {current.value}")

    for next in current.next:
        traverseSubTree(next)


tree = Tree()
tree.addNode(0)
tree.addNode(1, parent=tree.search(0))
tree.addNode(2, parent=tree.search(0))
tree.addNode(3, parent=tree.search(2))
tree.addNode(4, parent=tree.search(1))
tree.traverse()

ipdb.set_trace()


    