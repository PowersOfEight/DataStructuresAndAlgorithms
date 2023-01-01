from ListNode import ListNode

class LinkedList:
    head: ListNode
    tail: ListNode
    length: int
    
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0
        
    def push(self, val):
        if self.head == None:
            self.head = ListNode(val)
            self.tail = self.head
        else:
            self.tail.setNext(ListNode(val))
            self.tail = self.tail.next
        self.length += 1
        
    def pop(self):
        if self.tail == None: raise LookupError
        current = self.tail
        if self.tail == self.head:
            self.head = None
            self.tail = None
            self.length = 0
        else:
            newTail = self.head
            while newTail.next != current:
                newTail = newTail.next
            newTail.setNext(None)
            self.tail = newTail
            self.length -= 1
        return current.value
            
    
    # get the item using square brackets
    def __getitem__(self, index: int):
        if index < 0 or index >= self.length: raise IndexError
        current = self.head
        for x in range(0, index):
            current = current.next
        return current.value
    
    def __setitem__(self, index: int, val):
        if index < 0 or index >= self.length: raise IndexError
        current = self.head
        for x in range(0, index):
            current = current.next
        current.value = val