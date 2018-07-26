from DoublyLinkedBase import _DoublyLinkedBase

class PositionalList(_DoublyListBase):
    """A sequential container of elements allowing positional access.
    """
    #------- nested Position class ---------
    class Position:
        """An abstraction representing the location of a single element.
        """
        def __init__(self, container, node):
            self._container = container
            self._node = node

        def element(self):
            return self._node._element

        def __eq__(self, other):
            return type(other) is type(self) and other._node is self._node

        def __ne__(self, other):
            return not (self == other) 

    #------- utility method ---------
    def _validate(self, p):
        if not isinstance(p, self.Position):
            raise TypeError('p must be proper Position type')
        if p._container is not self:
            raise ValueError('p does not belong to this container')
        if p._node._next is None:
            raise ValueError('p is no longer valid')
        return p._node

    def _make_position(self, node):
        if node is self._header or node is self._tailer:
            return None
        else:
            return self.Position(self, node)
    
    def first(self):
        return self._make_position(self._header._next)
    
    def last(self):
        return self._make_position(self._tailer._prev)

    def before(self, p):
        node = self._validate(p)
        return self._make_position(node._prev)

    def after(self, p):
        node = self._validate(p)
        return self._make_position(node._next)

    def __iter__(self):
        """Generate a forward iteration of the elements of the list.
        """
        cursor = self.first()
        while cursor is not None:
            yield cursor.element()
            cursor = self.after(cursor)

    #------- mutators ---------
    def _insert_between(self, e, predecessor, successor):
        node = super()._insert_between(e, predecessor, successor)
        return self._make_position(node)

    def add_first(self, e):
        return self._insert_between(e, self._header, self._header._next)

    def add_last(self, e):
        return self._insert_between(e, self._tailer._prev, self._tailer)

    def add_before(self, p, e):
        target = self._validate(p)
        return self._insert_between(e, target._prev, target)

    def add_after(self, p, e):
        target = self._validate(p)
        return self._insert_between(e, target, target._next)

    def delete(self, p):
        target = self._validate(p)
        return self._delete_node(target)

    def replace(self, p, e):
        target = self._validate(p)
        old_value = target._element
        target._element = e
        return old_value
