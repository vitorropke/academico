import graphviz

from dijkstra import dijkstra
from node import Node

# Create the nodes.
nodes = []
for i in range(23):
    nodes.append(Node(str(i + 1)))

# Create edges.
nodes[0].set_adjacent_nodes([(nodes[1], 55), (nodes[5], 70)])
nodes[1].set_adjacent_nodes([(nodes[0], 55), (nodes[2], 28)])
nodes[2].set_adjacent_nodes([(nodes[1], 28), (nodes[3], 16)])
nodes[3].set_adjacent_nodes([(nodes[2], 16), (nodes[4], 16), (nodes[9], 30)])
nodes[4].set_adjacent_nodes([(nodes[3], 16), (nodes[5], 33)])
nodes[5].set_adjacent_nodes([(nodes[0], 70), (nodes[4], 33), (nodes[6], 11)])
nodes[6].set_adjacent_nodes([(nodes[5], 11), (nodes[7], 33), (nodes[8], 31)])
nodes[7].set_adjacent_nodes([(nodes[6], 33), (nodes[9], 44), (nodes[10], 50)])
nodes[8].set_adjacent_nodes([(nodes[6], 31), (nodes[10], 61)])
nodes[9].set_adjacent_nodes([(nodes[3], 30), (nodes[7], 44), (nodes[10], 50), (nodes[11], 28), (nodes[17], 54)])
nodes[10].set_adjacent_nodes([(nodes[7], 50), (nodes[8], 61), (nodes[9], 50), (nodes[14], 34)])
nodes[11].set_adjacent_nodes([(nodes[9], 28), (nodes[12], 13), (nodes[13], 21), (nodes[18], 48), (nodes[19], 43)])
nodes[12].set_adjacent_nodes([(nodes[11], 13), (nodes[16], 32)])
nodes[13].set_adjacent_nodes([(nodes[11], 21), (nodes[21], 23)])
nodes[14].set_adjacent_nodes([(nodes[10], 34), (nodes[15], 12)])
nodes[15].set_adjacent_nodes([(nodes[14], 12), (nodes[16], 19), (nodes[21], 39)])
nodes[16].set_adjacent_nodes([(nodes[12], 32), (nodes[15], 19), (nodes[21], 28)])
nodes[17].set_adjacent_nodes([(nodes[9], 54), (nodes[18], 28)])
nodes[18].set_adjacent_nodes([(nodes[11], 48), (nodes[17], 28), (nodes[19], 12)])
nodes[19].set_adjacent_nodes([(nodes[11], 43), (nodes[18], 12), (nodes[20], 18)])
nodes[20].set_adjacent_nodes([(nodes[19], 18), (nodes[21], 29), (nodes[22], 29)])
nodes[21].set_adjacent_nodes([(nodes[13], 23), (nodes[15], 39), (nodes[16], 28), (nodes[20], 29), (nodes[22], 11)])
nodes[22].set_adjacent_nodes([(nodes[20], 29), (nodes[21], 11)])

print(nodes)

# Create the graph.
graph = graphviz.Graph(name='mossoro-canions-dos-apertados', filename='mossoro_canions_dos_apertados_',
                       directory='outputs/dijkstra/mossoro_canions_dos_apertados', format='png', engine='neato',
                       graph_attr={'overlap': 'scalexy'}, strict=True)

graph.node(name='1', _attributes={'pos': '-37.3568, -5.1938!'})
graph.node(name='2', _attributes={'pos': '-37.2601, -5.6417!'})
graph.node(name='3', _attributes={'pos': '-37.3100, -5.8638!'})
graph.node(name='4', _attributes={'pos': '-37.1837, -5.8669!'})
graph.node(name='5', _attributes={'pos': '-37.1016, -5.7770!'})
graph.node(name='6', _attributes={'pos': '-36.9179, -5.5719!'})
graph.node(name='7', _attributes={'pos': '-36.8698, -5.6435!'})
graph.node(name='8', _attributes={'pos': '-36.8903, -5.8009!'})
graph.node(name='9', _attributes={'pos': '-36.6054, -5.6603!'})
graph.node(name='10', _attributes={'pos': '-37.0202, -6.0334!'})
graph.node(name='11', _attributes={'pos': '-36.6541, -5.9577!'})
graph.node(name='12', _attributes={'pos': '-36.8140, -6.1269!'})
graph.node(name='13', _attributes={'pos': '-36.7206, -6.1472!'})
graph.node(name='14', _attributes={'pos': '-36.6886, -6.2149!'})
graph.node(name='15', _attributes={'pos': '-36.4138, -5.9880!'})
graph.node(name='16', _attributes={'pos': '-36.3457, -6.0348!'})
graph.node(name='17', _attributes={'pos': '-36.4589, -6.0976!'})
graph.node(name='18', _attributes={'pos': '-37.0964, -6.4591!'})
graph.node(name='19', _attributes={'pos': '-36.8832, -6.4487!'})
graph.node(name='20', _attributes={'pos': '-36.7917, -6.4131!'})
graph.node(name='21', _attributes={'pos': '-36.6437, -6.4420!'})
graph.node(name='22', _attributes={'pos': '-36.5162, -6.2646!'})
graph.node(name='23', _attributes={'pos': '-36.4880, -6.3355!'})

print(dijkstra(nodes=nodes, source=nodes[0], target=nodes[22], graph=graph))
