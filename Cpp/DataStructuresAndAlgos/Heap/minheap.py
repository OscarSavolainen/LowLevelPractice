# Python implementation, just to practice algos in both languages
import pdb
import numpy as np
from ipdb_hook import ipdb_sys_excepthook
ipdb_sys_excepthook()

class MinHeap:

    def __init__(self, array):
        assert len(array.shape), "Array should be 1D"
        self.heap = array

    def print(self):
        print(f"Heap: {self.heap}")

    def getParent(self, index):
        return int(np.floor((index+1)/2) -1)

    def getLeftChild(self, index):
        return 2*index +1
    
    def getRightChild(self, index):
        return 2*index +2
    
    def getMinChildIndex(self, index: int) -> int:
        """
        Returns the index of the smaller of the two children of a value given by an index.
        """

        left_child = self.heap[self.getLeftChild(index)]
        right_child = self.heap[self.getRightChild(index)]
        if left_child <= right_child:
            return self.getLeftChild(index)
        else:
            return self.getRightChild(index)

    def validIndex (self, index):
        return index < len(self.heap)-1

    def heapifyUp(self, value: int, index: int) -> int:
        """
        Moves a value up until the heap is correct (all parents are smaller or equal to children).
        Returns the index the value should be inserted at.
        """
        parent_index = self.getParent(index)
        if value < self.heap[parent_index]:
            index = self.heapifyUp(value, parent_index)
        
        return index

    def heapifyDown(self, value, index):
        """
        Moves a value down until the heap is correct. This takes `value` at `index`,
        and moves it down by comparing it to the smaller of its two children. If it is 
        smaller, then it swaps places with that child.

        Return None.
        """

        print(f"Dealing with value {value} at index {index}")

        # If we don't have valid children, we stop
        if not self.validIndex(self.getRightChild(index)):
            # Zeroes below, NaNs?
            print(f"No place, creating a new entry in heap")
            extra = np.ones((1, self.getRightChild(index)+2 - len(self.heap))) *100
            self.heap = np.append(self.heap,extra)
            self.heap[self.getRightChild(index)] = value
            # I may have to push to the array here (append, at a specific index)
            return

        down_index = self.getMinChildIndex(index)
        down_val = self.heap[down_index]
        # This logic shouldn't be conditional, it should force the swap.
        # Value will awlays be smaller than down_val, by the nature of a minheap.
        self.heap[down_index] = value
        print(f"{value} took the spot of {down_val}: \n{self.heap}")
        self.heapifyDown(down_val, down_index)


    def insert(self, value):
        # Add to the bottom, at any value is fine, and then heapify up.
        # Once we've inserted it, the "replaced" value, will heapify down.

        insertion_index = len(self.heap)
        print(f"Length: {len(self.heap)}")
        insertion_index = self.heapifyUp(value, insertion_index)

        print(f"We will insert {value} at index {insertion_index}")

        # We insert the new value
        temp = self.heap[insertion_index] 
        self.heap[insertion_index] = value

        # We heapify the replaced value down
        self.heapifyDown(temp, insertion_index)


    def pop(self):
        # Delete (from top of heap), and then heapify down.
        index = 0

        # Current value we are replacing
        value = self.heap[index]

        while True:
            # We get the smaller child of the current value, which will replace it.
            # We check the child is valid, if not, the current value is already at the bottom
            if not self.validIndex(self.getRightChild(index)):
                self.heap[index] = 100
                break
            
            down_index = self.getMinChildIndex(index)

            # If the child is valid, we move it up
            print(f"Moving {self.heap[down_index]} to the spot formerly occupied by {self.heap[index]}")
            down_val = self.heap[down_index]
            self.heap[index] = down_val
            self.print()
            index = down_index

        #self.length -=1
        return value



array = np.arange(15)
minheap = MinHeap(array) 
#import pdb
#pdb.set_trace()
print(minheap.heap)


popped = minheap.pop()
print(f"Popped value: {popped}; Heap: {minheap.heap}")



value = 6
minheap.insert(value)
print(f"Inserted {value}; Heap: {minheap.heap}")

value = 2
minheap.insert(value)
print(f"Inserted {value}; Heap: {minheap.heap}")