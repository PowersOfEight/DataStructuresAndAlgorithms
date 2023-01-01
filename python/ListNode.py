from Node import Node

class ListNode(Node):
    next: 'ListNode'
    
    def setNext(self, nxt: 'ListNode'):
        self.next = nxt
        