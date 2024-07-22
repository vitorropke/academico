class Node:
    def __init__(self, label: str):
        self.label: str = label
        self.adjacent_nodes: list = []
        self.accumulated_weight: float = float('inf')
        self.previous_node: Node = self
        self.explored: bool = False

    def __repr__(self):
        return (f"Node(label={self.label}, "
                f"adjacent_nodes={[f'({c[0].label}, {c[1]})' for c in self.adjacent_nodes]}), "
                f"accumulated_weight={self.accumulated_weight}, "
                f"previous_node={self.previous_node.label}, "
                f"explored={self.explored}\n")

    def set_adjacent_nodes(self, adjacent_nodes: list):
        self.adjacent_nodes = adjacent_nodes

    def set_accumulated_weight(self, accumulated_weight: float):
        self.accumulated_weight = accumulated_weight

    def set_previous_node(self, previous_node):
        self.previous_node = previous_node

    def set_explored(self, explored: bool):
        self.explored = explored
