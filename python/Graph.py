class Edge:
  def __init__(self, start: 'Vertex', end: 'Vertex', weight: int):
    self.start = start
    self.end = end
    self.weight = weight

class Vertex:
  def __init__(self, data: str):
    self.data = data
    self.edges = []

  def addEdge(self, end: 'Vertex', weight: int):
    edge = Edge(self, end, weight)

    self.edges.append(edge)

  def removeEdge(self, end: 'Vertex'):
    self.edges = filter(lambda edge: edge.end.data == end.data, self.edges)

class Graph:
  def __init__(self, isWeighted: bool, isDirected: bool):
    self.vertices = []
    self.isWeighted = isWeighted
    self.isDirected = isDirected

  def print(self):
    for vertex in self.vertices:
      print(f"{vertex.data}")

      for edge in vertex.edges:
        if self.isWeighted:
          print(f"{vertex.data} -> {edge.end.data}: {edge.weight}")
        else:
          print(f"{vertex.data} -> {edge.end.data}")

      print("")

  def addVertex(self, data: str) -> Vertex:
    vertex = Vertex(data)

    self.vertices.append(vertex)

    return vertex
  
  def removeVertex(self, vertex: Vertex):
    self.vertices = filter(lambda v: not v.data == vertex.data, self.vertices)

  def addEdge(self, start: Vertex, end: Vertex, weight: int):
    if not self.isWeighted:
      weight = None

    start.addEdge(end, weight)

    if not self.isDirected:
      end.addEdge(start, weight)

  def removeEdge(self, start: Vertex, end: Vertex):
    start.removeEdge(end)

    if not self.isDirected:
      end.removeEdge(start)

  def dfs(self, start: Vertex, visited: list, arr: list):
    visited.append(start)
    arr.append(start.data)

    for edge in start.edges:
      neighbor = edge.end

      if not neighbor in visited:
        self.dfs(neighbor, visited, arr)

  def bfs(self, start: Vertex, arr: list):
    visited = [start]
    queue = [start]

    while len(queue) > 0:
      vertex = queue.pop(0)

      arr.append(vertex.data)

      for edge in vertex.edges:
        neighbor = edge.end

        if not neighbor in visited:
          visited.append(neighbor)
          queue.append(neighbor)

graph = Graph(False, False)

v0 = graph.addVertex("0")
v1 = graph.addVertex("1")
v2 = graph.addVertex("2")
v3 = graph.addVertex("3")
v4 = graph.addVertex("4")

graph.addEdge(v0, v1, None)
graph.addEdge(v0, v2, None)
graph.addEdge(v1, v2, None)
graph.addEdge(v1, v3, None)
graph.addEdge(v2, v4, None)
graph.addEdge(v3, v4, None)

print("Unwewighted and Undirected Graph")
graph.print()

graph = Graph(True, False)

v0 = graph.addVertex("0")
v1 = graph.addVertex("1")
v2 = graph.addVertex("2")
v3 = graph.addVertex("3")
v4 = graph.addVertex("4")

w01 = 10
w02 = 10
w12 = 5
w13 = 15
w24 = 15
w34 = 5

graph.addEdge(v0, v1, w01)
graph.addEdge(v0, v2, w02)
graph.addEdge(v1, v2, w12)
graph.addEdge(v1, v3, w13)
graph.addEdge(v2, v4, w24)
graph.addEdge(v3, v4, w34)

print("Weighted and Undirected Graph")
graph.print()

graph = Graph(True, True)

v0 = graph.addVertex("0")
v1 = graph.addVertex("1")
v2 = graph.addVertex("2")
v3 = graph.addVertex("3")
v4 = graph.addVertex("4")

graph.addEdge(v0, v1, w01)
graph.addEdge(v0, v2, w02)
graph.addEdge(v1, v2, w12)
graph.addEdge(v1, v3, w13)
graph.addEdge(v2, v4, w24)
graph.addEdge(v3, v4, w34)

print("Weighted and Directed Graph")
graph.print()

visited = []
arr = []

graph.dfs(v0, visited, arr)

print(f"dfs traversal: {'->'.join(arr)}")

arr = []

graph.bfs(v0, arr)

print(f"bfs traversal: {'->'.join(arr)}")