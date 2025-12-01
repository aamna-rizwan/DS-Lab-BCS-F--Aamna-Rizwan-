//dijsktra algorithm written : 
/*

function Dijkstra(Graph, source, target):
for each vertex v in Graph:
define the visited state FALSE
define the cost from the source node to infinity
define the previous node to None
if v == source:
define the cost from the source node to zero
while target is not visited:
selected_node ← vertex in Graph with min distance from
the source node
selected_node is characterized as visited
for each neighbor v of selected_node not visited:
alt ← selected_node distance from source node +
length(selected_node, v)
if alt &lt; neighbor distance from source node:
neighbor distance from source node ← alt
neighbor previous node ← selected_node
calculate the path
return path, target node distance from start
*/
