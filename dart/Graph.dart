class Edge {
  Vertex start;
  Vertex end;
  int? weight;

  Edge(this.start, this.end, this.weight);
}

class Vertex {
  String data;
  final List<Edge> edges = [];

  Vertex(this.data);

  void addEdge(Vertex end, int? weight) {
    final edge = Edge(this, end, weight);

    this.edges.add(edge);
  }

  void removeEdge(Vertex end) {
    this.edges.removeWhere((edge) => edge.end.data == end.data);
  }
}

class Graph {
  final List<Vertex> vertices = [];
  final bool isWeighted;
  final bool isDirected;

  Graph(this.isWeighted, this.isDirected);

  void printGraph() {
    for (final vertex in this.vertices) {
      print(vertex.data);

      for (final edge in vertex.edges) {
        if (this.isWeighted) {
          print("${vertex.data} -> ${edge.end.data}: ${edge.weight}");
        } else {
          print("${vertex.data} -> ${edge.end.data}");
        }
      }
    }
  }

  Vertex addVertex(String data) {
    final vertex = Vertex(data);

    this.vertices.add(vertex);

    return vertex;
  }

  void removeVertex(Vertex vertex) {
    this.vertices.removeWhere((v) => v.data == vertex.data);
  }

  void addEdge(Vertex start, Vertex end, int? weight) {
    if (!this.isWeighted) {
      weight = null;
    }

    start.addEdge(end, weight);

    if (!this.isDirected) {
      end.addEdge(start, weight);
    }
  }

  void removeEdge(Vertex start, Vertex end) {
    start.removeEdge(end);

    if (!this.isDirected) {
      end.removeEdge(start);
    }
  }

  void dfs(Vertex start, List<Vertex> visited, List<String> arr) {
    visited.add(start);
    arr.add(start.data);

    for (final edge in start.edges) {
      final neighbor = edge.end;

      if (!visited.contains(neighbor)) {
        this.dfs(neighbor, visited, arr);
      }
    }
  }

  void bfs(Vertex start, List<String> arr) {
    List<Vertex> visited = [start];
    List<Vertex> queue = [start];

    while (queue.length > 0) {
      final vertex = queue.removeAt(0);

      arr.add(vertex.data);

      for (final edge in vertex.edges) {
        final neighbor = edge.end;

        if (!visited.contains(neighbor)) {
          visited.add(neighbor);
          queue.add(neighbor);
        }
      }
    }
  }
}

void main() {
  var graph = Graph(false, false);

  var v0 = graph.addVertex("0");
  var v1 = graph.addVertex("1");
  var v2 = graph.addVertex("2");
  var v3 = graph.addVertex("3");
  var v4 = graph.addVertex("4");

  graph.addEdge(v0, v1, null);
  graph.addEdge(v0, v2, null);
  graph.addEdge(v1, v2, null);
  graph.addEdge(v1, v3, null);
  graph.addEdge(v2, v4, null);
  graph.addEdge(v3, v4, null);

  print("Unweighted and Undirected Graph");
  graph.printGraph();

  graph = Graph(true, false);

  v0 = graph.addVertex("0");
  v1 = graph.addVertex("1");
  v2 = graph.addVertex("2");
  v3 = graph.addVertex("3");
  v4 = graph.addVertex("4");

  int w01 = 10;
  int w02 = 10;
  int w12 = 5;
  int w13 = 15;
  int w24 = 15;
  int w34 = 5;

  graph.addEdge(v0, v1, w01);
  graph.addEdge(v0, v2, w02);
  graph.addEdge(v1, v2, w12);
  graph.addEdge(v1, v3, w13);
  graph.addEdge(v2, v4, w24);
  graph.addEdge(v3, v4, w34);

  print("\nWeighted and Undirected Graph");
  graph.printGraph();

  graph = Graph(true, true);

  v0 = graph.addVertex("0");
  v1 = graph.addVertex("1");
  v2 = graph.addVertex("2");
  v3 = graph.addVertex("3");
  v4 = graph.addVertex("4");

  graph.addEdge(v0, v1, w01);
  graph.addEdge(v0, v2, w02);
  graph.addEdge(v1, v2, w12);
  graph.addEdge(v1, v3, w13);
  graph.addEdge(v2, v4, w24);
  graph.addEdge(v3, v4, w34);

  print("\nWeighted and Directed Graph");
  graph.printGraph();

  final List<Vertex> visited = [];
  List<String> arr = [];

  graph.dfs(v0, visited, arr);

  print("\ndfs traversal: ${arr.join("->")}");

  arr = [];

  graph.bfs(v0, arr);

  print("bfs traversal: ${arr.join("->")}");
}