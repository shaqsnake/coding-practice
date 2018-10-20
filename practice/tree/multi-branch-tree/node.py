#!/usr/bin/env python
import uuid

class Node(object):
    def __init__ (self, uid=None, val=None):
        # id must be unique
        self._id = None
        self._set_id(uid)

        # node's parent
        self._parent = None
        # node's children
        self._children = list()

        self.val = val

    def _set_id(self, uid):
        if uid is None:
            self._id = str(uuid.uuid1())
        else:
            self._id = uid

    def __repr__(self):
        name = self.__class__.__name__
        attributes = [
            "uid={}".format(self._id),
            "value={}".format(self.val)
        ]
        return "%s(%s)" % (name, ", ".join(attributes))


if __name__ == '__main__':
    n = Node(None, "A")
    print(n)