import matplotlib.pyplot as plt
import xml.etree.ElementTree as ETree
from xml.etree.ElementTree import ElementTree

tree: ElementTree = ETree.parse('transit_schedule.xml')
root: ETree.Element = tree.getroot()

routes_and_quantity_of_bus_stops: dict[str, int] = {}
# Iterate transitSchedule -> transitLine
# root[1] = transitLine
for route in root[1]:
    # route = transitRoute
    # route[1] = routeProfile
    routes_and_quantity_of_bus_stops[route.attrib['id']] = len(route[1])

print(routes_and_quantity_of_bus_stops)
print('Rota com o maior número de paradas: ', max(routes_and_quantity_of_bus_stops.items(), key=lambda x: x[1]))
print('Rota com o menor número de paradas: ', min(routes_and_quantity_of_bus_stops.items(), key=lambda x: x[1]))
print('Média do número de paradas: ',
      sum(routes_and_quantity_of_bus_stops.values()) / len(routes_and_quantity_of_bus_stops))

box = plt.boxplot(x=routes_and_quantity_of_bus_stops.values())
print("Medians:", [median.get_ydata() for median in box['medians']])
print("Boxes (Q1 to Q3):", [box_elem.get_ydata() for box_elem in box['boxes']])
print("Fliers (outliers):", [flier.get_ydata() for flier in box['fliers']])

plt.xticks(visible=False)
plt.savefig(fname='quantity_of_bus_stops_boxplot.pdf', transparent=True, bbox_inches='tight')
