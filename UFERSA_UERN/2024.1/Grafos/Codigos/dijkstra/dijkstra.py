import graphviz
from node import Node


def dijkstra(nodes: list[Node], source: Node, target: Node, graph: graphviz.Graph) -> tuple[float, list]:
    """
    The Dijkstra algorithm works with the following steps:
        1. Set all nodes weight to infinity.
        2. Set the source node with accumulated weight to zero and explored.
        3. Start exploring the nodes until the target is explored.
        4. Set the last explored node as current node.
        5. Iterate over the adjacent nodes of the current node.
        6. Update the accumulated weight of the current adjacent node with the sum of the current node plus the weight
            from the current node to the current adjacent node. Also update the previous node of the current adjacent
            node to the current node.
        7. Find the node with the smallest accumulated weight in the entire graph and set it as explored.
        8. If the target was explored, go to step 10.
        9. Go to step 3.
        10. Create the best path following the previous nodes from target to source. Then reverse the best path list.

    :param nodes: list[Node]
    :param source: Node
    :param target: Node
    :param graph: graphviz.Graph

    :return: tuple[float, list]
    """

    graph_copy: graphviz.Graph = graph.copy()

    # Draw the initial graph.
    output_filename: str = graph.filename
    loop_counter_for_graph_render: int = 0
    graph.render(filename=output_filename + str(loop_counter_for_graph_render), cleanup=True)

    # Set the initial configuration for source: accumulated weight to 0 and explored.
    current_node: Node = source
    source.set_accumulated_weight(0)
    source.set_explored(True)

    # Set the source node color to green and draw the graph.
    graph.node(name=current_node.label, _attributes={'color': 'green'})
    loop_counter_for_graph_render += 1
    graph.render(filename=output_filename + str(loop_counter_for_graph_render), cleanup=True)

    # Explore the nodes until the target is explored.
    while not target.explored:
        # Iterate over all the adjacent nodes of the current node.
        for adjacent_node in current_node.adjacent_nodes:
            current_accumulated_weight = current_node.accumulated_weight + adjacent_node[1]
            if not adjacent_node[0].explored:
                # Update the values of the adjacent node if a lower accumulated weight value was found.
                if current_accumulated_weight < adjacent_node[0].accumulated_weight:
                    adjacent_node[0].set_accumulated_weight(current_accumulated_weight)
                    adjacent_node[0].set_previous_node(current_node)

                # Draw a blue edge between the current node and current adjacent node and draw the graph.
                graph.edge(tail_name=current_node.label, head_name=adjacent_node[0].label,
                           _attributes={'color': 'blue'})
                loop_counter_for_graph_render += 1
                graph.render(filename=output_filename + str(loop_counter_for_graph_render), cleanup=True)

        # Find the node with the smallest accumulated weight in the entire graph.
        minimum_weight: float = float('inf')
        for node in nodes:
            if not node.explored and (node.accumulated_weight < minimum_weight):
                current_node = node
                minimum_weight = node.accumulated_weight

        # The node with the smallest accumulated weight is set to 'explored'.
        current_node.set_explored(True)

        # Set the current node color to green and draw the graph.
        graph.node(name=current_node.label, _attributes={'color': 'green'})
        loop_counter_for_graph_render += 1
        graph.render(filename=output_filename + str(loop_counter_for_graph_render), cleanup=True)

    # Follow the path back to the source, defining the best path.
    best_path: list = []
    while current_node != source:
        # Draw the edge between the current node and its previous node with a green color.
        graph_copy.edge(tail_name=current_node.label, head_name=current_node.previous_node.label,
                        _attributes={'color': 'green'})
        # Draw the edge between the current node and its previous node with a green color and draw the graph.
        graph.edge(tail_name=current_node.label, head_name=current_node.previous_node.label,
                   _attributes={'color': 'green'})
        loop_counter_for_graph_render += 1
        graph.render(filename=output_filename + str(loop_counter_for_graph_render), cleanup=True)

        best_path.insert(0, current_node.label)
        current_node = current_node.previous_node
    best_path.insert(0, source.label)
    # Draw the final graph with no edges other than those that are in the best path.
    graph_copy.render(filename=output_filename + 'best_path', cleanup=True)

    return target.accumulated_weight, best_path
