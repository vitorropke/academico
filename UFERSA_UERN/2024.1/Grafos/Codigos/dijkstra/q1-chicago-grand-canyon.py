import graphviz
from node import Node
from dijkstra import dijkstra

# Create the nodes.
nodes = []
for i in range(40):
    nodes.append(Node(str(i + 1)))

# Create edges.
nodes[0].set_adjacent_nodes([(nodes[1], 220), (nodes[2], 255), (nodes[9], 460)])
nodes[1].set_adjacent_nodes([(nodes[0], 220), (nodes[2], 105), (nodes[5], 240), (nodes[9], 360), (nodes[15], 510)])
nodes[2].set_adjacent_nodes([(nodes[0], 255), (nodes[1], 105), (nodes[3], 130), (nodes[5], 165)])
nodes[3].set_adjacent_nodes(
    [(nodes[2], 130), (nodes[4], 240), (nodes[5], 180), (nodes[6], 195), (nodes[8], 315), (nodes[11], 340)])
nodes[4].set_adjacent_nodes([(nodes[3], 240), (nodes[7], 300), (nodes[8], 310)])
nodes[5].set_adjacent_nodes(
    [(nodes[1], 240), (nodes[2], 165), (nodes[3], 180), (nodes[6], 165), (nodes[9], 360), (nodes[11], 285),
     (nodes[13], 285)])
nodes[6].set_adjacent_nodes([(nodes[3], 195), (nodes[5], 165), (nodes[8], 225), (nodes[12], 255)])
nodes[7].set_adjacent_nodes([(nodes[4], 300), (nodes[8], 330), (nodes[10], 225)])
nodes[8].set_adjacent_nodes(
    [(nodes[3], 315), (nodes[4], 310), (nodes[6], 225), (nodes[7], 330), (nodes[9], 505), (nodes[11], 255),
     (nodes[14], 220), (nodes[17], 360)])
nodes[9].set_adjacent_nodes(
    [(nodes[0], 460), (nodes[1], 360), (nodes[5], 360), (nodes[8], 505), (nodes[11], 280), (nodes[15], 200)])
nodes[10].set_adjacent_nodes([(nodes[7], 225), (nodes[12], 330), (nodes[14], 210), (nodes[18], 270)])
nodes[11].set_adjacent_nodes(
    [(nodes[3], 340), (nodes[5], 285), (nodes[8], 255), (nodes[9], 280), (nodes[12], 150), (nodes[13], 70),
     (nodes[17], 200), (nodes[19], 270), (nodes[26], 585)])
nodes[12].set_adjacent_nodes([(nodes[6], 255), (nodes[10], 330), (nodes[11], 150), (nodes[14], 195), (nodes[17], 210)])
nodes[13].set_adjacent_nodes([(nodes[5], 285), (nodes[11], 70), (nodes[15], 255), (nodes[16], 195), (nodes[20], 300)])
nodes[14].set_adjacent_nodes(
    [(nodes[8], 220), (nodes[10], 210), (nodes[12], 195), (nodes[15], 590), (nodes[17], 230), (nodes[18], 105)])
nodes[15].set_adjacent_nodes(
    [(nodes[1], 510), (nodes[9], 220), (nodes[13], 255), (nodes[14], 590), (nodes[16], 110), (nodes[21], 190)])
nodes[16].set_adjacent_nodes([(nodes[13], 195), (nodes[15], 110), (nodes[17], 275), (nodes[21], 170)])
nodes[17].set_adjacent_nodes(
    [(nodes[8], 360), (nodes[11], 200), (nodes[12], 210), (nodes[14], 230), (nodes[16], 275), (nodes[18], 195),
     (nodes[19], 170), (nodes[22], 210), (nodes[23], 345)])
nodes[18].set_adjacent_nodes([(nodes[10], 270), (nodes[14], 105), (nodes[17], 195), (nodes[22], 360), (nodes[25], 345)])
nodes[19].set_adjacent_nodes([(nodes[11], 270), (nodes[17], 170), (nodes[20], 165), (nodes[22], 120), (nodes[29], 465)])
nodes[20].set_adjacent_nodes([(nodes[13], 300), (nodes[19], 165), (nodes[21], 160), (nodes[30], 390)])
nodes[21].set_adjacent_nodes([(nodes[15], 190), (nodes[16], 170), (nodes[20], 160), (nodes[22], 375), (nodes[24], 190)])
nodes[22].set_adjacent_nodes(
    [(nodes[17], 210), (nodes[18], 360), (nodes[19], 120), (nodes[21], 375), (nodes[23], 150), (nodes[24], 340),
     (nodes[29], 360)])
nodes[23].set_adjacent_nodes([(nodes[17], 345), (nodes[22], 150), (nodes[25], 150), (nodes[27], 260), (nodes[28], 255)])
nodes[24].set_adjacent_nodes([(nodes[21], 190), (nodes[22], 340), (nodes[30], 360)])
nodes[25].set_adjacent_nodes([(nodes[18], 345), (nodes[23], 150), (nodes[26], 360), (nodes[27], 175), (nodes[28], 285)])
# The edge {27 -- 12} was weighted as 585 to match {12 -- 27}.
nodes[26].set_adjacent_nodes([(nodes[11], 585), (nodes[25], 360), (nodes[30], 210)])
nodes[27].set_adjacent_nodes([(nodes[23], 260), (nodes[25], 175), (nodes[31], 260), (nodes[32], 230)])
nodes[28].set_adjacent_nodes([(nodes[23], 255), (nodes[25], 285), (nodes[29], 150), (nodes[31], 255), (nodes[33], 435)])
nodes[29].set_adjacent_nodes(
    [(nodes[19], 465), (nodes[22], 360), (nodes[28], 150), (nodes[30], 180), (nodes[33], 435), (nodes[34], 480)])
nodes[30].set_adjacent_nodes(
    [(nodes[20], 390), (nodes[24], 360), (nodes[26], 210), (nodes[29], 180), (nodes[33], 580), (nodes[34], 420)])
nodes[31].set_adjacent_nodes([(nodes[27], 260), (nodes[28], 255), (nodes[32], 75), (nodes[33], 330)])
nodes[32].set_adjacent_nodes([(nodes[27], 230), (nodes[31], 75), (nodes[33], 300), (nodes[35], 185)])
nodes[33].set_adjacent_nodes(
    [(nodes[28], 435), (nodes[29], 435), (nodes[30], 580), (nodes[31], 330), (nodes[32], 300), (nodes[34], 300),
     (nodes[35], 260), (nodes[36], 320)])
nodes[34].set_adjacent_nodes([(nodes[29], 480), (nodes[30], 420), (nodes[33], 300), (nodes[36], 180)])
nodes[35].set_adjacent_nodes([(nodes[32], 185), (nodes[33], 260), (nodes[36], 450), (nodes[37], 260)])
nodes[36].set_adjacent_nodes([(nodes[33], 320), (nodes[34], 180), (nodes[35], 450), (nodes[38], 480)])
nodes[37].set_adjacent_nodes([(nodes[35], 260), (nodes[38], 330), (nodes[39], 110)])
nodes[38].set_adjacent_nodes([(nodes[36], 480), (nodes[37], 330), (nodes[39], 150)])
nodes[39].set_adjacent_nodes([(nodes[37], 110), (nodes[38], 150)])

print(nodes)

# Create the graph.
graph = graphviz.Graph(name='chicago-grand-canyon', filename='chicago_grand_canyon_',
                       directory='outputs/dijkstra/chicago_grand_canyon', format='png', engine='neato', strict=True)

graph.node(name='1', _attributes={'pos': '-87.6866, 41.8375!'})
graph.node(name='2', _attributes={'pos': '-89.6154, 40.7520!'})
graph.node(name='3', _attributes={'pos': '-89.6540, 39.7709!'})
graph.node(name='4', _attributes={'pos': '-90.2451, 38.6359!'})
graph.node(name='5', _attributes={'pos': '-90.4135, 36.7632!'})
graph.node(name='6', _attributes={'pos': '-91.3939, 39.7098!'})
graph.node(name='7', _attributes={'pos': '-92.1759, 38.5676!'})
graph.node(name='8', _attributes={'pos': '-92.3577, 34.7256!'})
graph.node(name='9', _attributes={'pos': '-93.2916, 37.1943!'})
graph.node(name='10', _attributes={'pos': '-93.6105, 41.5725!'})
graph.node(name='11', _attributes={'pos': '-94.3695, 35.3495!'})
graph.node(name='12', _attributes={'pos': '-94.7443, 39.1235!'})
graph.node(name='13', _attributes={'pos': '-94.7038, 37.8283!'})
graph.node(name='14', _attributes={'pos': '-94.8210, 39.7598!'})
graph.node(name='15', _attributes={'pos': '-95.9042, 36.1283!'})
graph.node(name='16', _attributes={'pos': '-96.0529, 41.2627!'})
graph.node(name='17', _attributes={'pos': '-96.7455, 40.2736!'})
graph.node(name='18', _attributes={'pos': '-97.3443, 37.6895!'})
graph.node(name='19', _attributes={'pos': '-97.5136, 35.4676!'})
graph.node(name='20', _attributes={'pos': '-98.8015, 38.3593!'})
graph.node(name='21', _attributes={'pos': '-99.3210, 39.7512!'})
graph.node(name='22', _attributes={'pos': '-98.3586, 40.9218!'})
graph.node(name='23', _attributes={'pos': '-100.0182, 37.7611!'})
graph.node(name='24', _attributes={'pos': '-101.4774, 36.6903!'})
graph.node(name='25', _attributes={'pos': '-100.7641, 41.1263!'})
graph.node(name='26', _attributes={'pos': '-101.8316, 35.1984!'})
graph.node(name='27', _attributes={'pos': '-102.7954, 38.7628!'})
graph.node(name='28', _attributes={'pos': '-103.7046, 35.1700!'})
graph.node(name='29', _attributes={'pos': '-104.4396, 36.8849!'})
graph.node(name='30', _attributes={'pos': '-104.7246, 38.3465!'})
graph.node(name='31', _attributes={'pos': '-104.8758, 39.7620!'})
graph.node(name='32', _attributes={'pos': '-105.9819, 35.6619!'})
graph.node(name='33', _attributes={'pos': '-106.6465, 35.1054!'})
graph.node(name='34', _attributes={'pos': '-107.8781, 37.2659!'})
graph.node(name='35', _attributes={'pos': '-108.5673, 39.0877!'})
graph.node(name='36', _attributes={'pos': '-108.7431, 35.5182!'})
graph.node(name='37', _attributes={'pos': '-110.1723, 38.9935!'})
graph.node(name='38', _attributes={'pos': '-111.6194, 35.1872!'})
graph.node(name='39', _attributes={'pos': '-112.6804, 37.2241!'})
graph.node(name='40', _attributes={'pos': '-112.7500, 36.0565!'})

print(dijkstra(nodes=nodes, source=nodes[0], target=nodes[39], graph=graph))
