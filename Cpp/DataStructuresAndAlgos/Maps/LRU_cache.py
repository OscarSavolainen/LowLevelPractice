
# So, we want a linked list, and and a hash that looks to it.

class Node:
    def __init__(self, value=None, key=None):
        self.prev = None
        self.next = None
        self.value = value
        self.key = key

class LRUCache:
    def __init__(self, capacity: int) :
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.cache = {}
        self.capacity = capacity
    
    def _add_node(self, node: Node):
        if len(self.cache) >= self.capacity:
            self._remove_tail()
        self._move_to_head(node)
        # Store node in cache
        self.cache[node.key] = node

    def _remove_tail(self):
        # We delete the tail node
        temp = self.tail
        self.tail = self.tail.prev 
        # We remove it from the cache
        self.cache.pop(temp.key)
        del temp

    def _move_to_head(self, node: Node):
        # Detach node from current spot
        temp = node
        if node.prev is not None:
            node.prev.next = temp.next
        if node.next is not None:
            node.next.prev = temp.prev

        # Add node to head
        node.next = self.head
        self.head.prev = node
        self.head = node
        del node

    def get(self, key):
        if key in self.cache:
            # Get node from cache
            node: Node = self.cache[key]

            # Move node to head
            self._move_to_head(node)

            return node.value

        else:
            print("Not in cache")
        

    def put(self, value, key):
        # Either new node, or in cache (in which case moved to front)
        ## If we exceed capacity, make some space by deleting from the back
        if key in self.cache:
            node: Node = self.cache[key]
            node.value = value
            self._move_to_head(node)
        else:
            # New node
            node = Node(value=value, key=key)
            self._add_node(node)
        
cache = LRUCache(4)

for i in range(4):
    cache.put(i, str(i))

for key, value in cache.cache.items():
    print(key, value.value)

print(cache.get('1'))

print(f"Cache head {cache.head.value}")
print(cache.get('2'))
print(f"Cache head {cache.head.value}")