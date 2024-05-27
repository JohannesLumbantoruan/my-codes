class Edge(val start: Vertex, val end: Vertex, val weight: Int?)

class Vertex(val data: String, var edges: MutableList<Edge> = mutableListOf()) {
  fun addEdge(end: Vertex, weight: Int?) {
    val edge = Edge(this, end, weight)

    this.edges.add(edge)
  }

  fun removeEdge(end: Vertex) {
    this.edges = this.edges.filter{ it.end.data == end.data }.toMutableList()
  }
}

class Graph(val isWeighted: Boolean, val isDirected: Boolean, var vertices: MutableList<Vertex> = mutableListOf()) {
  fun addVertex(data: String): Vertex {
    val vertex = Vertex(data)

    this.vertices.add(vertex)

    return vertex
  }

  fun print() {
    for (vertex in this.vertices) {
      println(vertex.data)

      for (edge in vertex.edges) {
        if (this.isWeighted) {
          println("${vertex.data} -> ${edge.end.data}: ${edge.weight}")
        } else {
          println("${vertex.data} -> ${edge.end.data}")
        }
      }
    }
  }

  fun removeVertex(vertex: Vertex) {
    this.vertices = this.vertices.filter{ it.data == vertex.data }.toMutableList()
  }

  fun addEdge(start: Vertex, end: Vertex, weight: Int?) {
    var w = weight

    if (!this.isWeighted) {
      w = null
    }

    start.addEdge(end, w)

    if (!this.isDirected) {
      end.addEdge(start, w)
    }
  }

  fun removeEdge(start: Vertex, end: Vertex) {
    start.removeEdge(end)

    if (!this.isDirected) {
      end.removeEdge(start)
    }
  }

  fun dfs(start: Vertex, visited: MutableList<Vertex>, arr: MutableList<String>) {
    visited.add(start)
    arr.add(start.data)

    for (edge in start.edges) {
      val neighbor = edge.end

      if (!visited.contains(neighbor)) {
        this.dfs(neighbor, visited, arr)
      }
    }
  }

  fun bfs(start: Vertex, arr: MutableList<String>) {
    val visited = mutableListOf<Vertex>(start)
    val queue = mutableListOf<Vertex>(start)

    while (queue.size > 0) {
      val vertex = queue.removeAt(0)

      arr.add(vertex.data)

      for (edge in vertex.edges) {
        val neighbor = edge.end

        if (!visited.contains(neighbor)) {
          visited.add(neighbor)
          queue.add(neighbor)
        }
      }
    }
  }
}

fun main() {
  var graph = Graph(false, false)

  var v0 = graph.addVertex("0")
  var v1 = graph.addVertex("1")
  var v2 = graph.addVertex("2")
  var v3 = graph.addVertex("3")
  var v4 = graph.addVertex("4")

  graph.addEdge(v0, v1, null)
  graph.addEdge(v0, v2, null)
  graph.addEdge(v1, v2, null)
  graph.addEdge(v1, v3, null)
  graph.addEdge(v2, v4, null)
  graph.addEdge(v3, v4, null)

  println("Unweighted and Undirected Graph")
  graph.print()

  graph = Graph(true, false)

  v0 = graph.addVertex("0")
  v1 = graph.addVertex("1")
  v2 = graph.addVertex("2")
  v3 = graph.addVertex("3")
  v4 = graph.addVertex("4")

  val w01 = 10
  val w02 = 10
  val w12 = 5
  val w13 = 15
  val w24 = 15
  val w34 = 5

  graph.addEdge(v0, v1, w01)
  graph.addEdge(v0, v2, w02)
  graph.addEdge(v1, v2, w12)
  graph.addEdge(v1, v3, w13)
  graph.addEdge(v2, v4, w24)
  graph.addEdge(v3, v4, w34)

  println("\nWeighted and Undirected Graph")
  graph.print()

  graph = Graph(true, true)

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

  println("\nWeighted and Directed Graph")
  graph.print()

  var visited = mutableListOf<Vertex>()
  var arr = mutableListOf<String>()

  graph.dfs(v0, visited, arr)

  println("\ndfs traversal: ${arr.joinToString(separator = "->")}")

  arr = mutableListOf<String>()

  graph.bfs(v0, arr)

  print("bfs traversal: ${arr.joinToString(separator = "->")}")
}