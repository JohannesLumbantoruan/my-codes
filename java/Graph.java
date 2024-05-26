import java.util.ArrayList;

class Graph {
  public ArrayList<Vertex> vertices;
  public boolean isWeighted;
  public boolean isDirected;

  Graph(boolean isWeighted, boolean isDirected) {
    this.vertices = new ArrayList<>();
    this.isWeighted = isWeighted;
    this.isDirected = isDirected;
  }

  void print() {
    for (Vertex vertex: this.vertices) {
      System.out.println(vertex.data);

      for (Edge edge: vertex.edges) {
        if (this.isWeighted) {
          System.out.printf("%s -> %s: %d\n", vertex.data, edge.end.data, edge.weight);
        } else {
          System.out.printf("%s -> %s\n", vertex.data, edge.end.data);
        }
      }
    }
  }

  void printTraversal(ArrayList<String> arr, String text) {
    System.out.printf("%s: ", text);

    for (int i = 0; i < arr.size(); i++) {
      if (i == 0) {
        System.out.printf("[%s, ", arr.get(i));
      } else if (i == arr.size() - 1) {
        System.out.printf("%s]\n", arr.get(i));
      } else {
        System.out.printf("%s, ", arr.get(i));
      }
    }
  }

  public static void main(String[] args) {
    Graph graph = new Graph(false, false);

    Vertex v0 = graph.addVertex("0");
    Vertex v1 = graph.addVertex("1");
    Vertex v2 = graph.addVertex("2");
    Vertex v3 = graph.addVertex("3");
    Vertex v4 = graph.addVertex("4");

    graph.addEdge(v0, v1, null);
    graph.addEdge(v0, v2, null);
    graph.addEdge(v1, v2, null);
    graph.addEdge(v1, v3, null);
    graph.addEdge(v2, v4, null);
    graph.addEdge(v3, v4, null);

    System.out.println("Unweighted and Undirected Graph");
    graph.print();

    ArrayList<Vertex> visited = new ArrayList<>();
    ArrayList<String> arr = new ArrayList<>();

    graph.dfs(v0, visited, arr);

    graph.printTraversal(arr, "dfs traversal");

    arr = new ArrayList<>();

    graph.bfs(v0, arr);

    graph.printTraversal(arr, "bfs traversal");

    graph = new Graph(true, false);

    v0 = graph.addVertex("0");
    v1 = graph.addVertex("1");
    v2 = graph.addVertex("2");
    v3 = graph.addVertex("3");
    v4 = graph.addVertex("4");

    Integer w01 = 10;
    Integer w02 = 10;
    Integer w12 = 5;
    Integer w13 = 15;
    Integer w24 = 15;
    Integer w34 = 5;

    graph.addEdge(v0, v1, w01);
    graph.addEdge(v0, v2, w02);
    graph.addEdge(v1, v2, w12);
    graph.addEdge(v1, v3, w13);
    graph.addEdge(v2, v4, w24);
    graph.addEdge(v3, v4, w34);

    System.out.println("\n\nWeighted and Undirected Graph");
    graph.print();

    visited = new ArrayList<>();
    arr = new ArrayList<>();

    graph.dfs(v0, visited, arr);

    graph.printTraversal(arr, "dfs traversal");

    arr = new ArrayList<>();

    graph.bfs(v0, arr);

    graph.printTraversal(arr, "bfs traversal");

    graph = new Graph(true, true);

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

    System.out.println("\n\nWeighted and directed Graph");
    graph.print();

    visited = new ArrayList<>();
    arr = new ArrayList<>();

    graph.dfs(v0, visited, arr);

    graph.printTraversal(arr, "dfs traversal");

    arr = new ArrayList<>();

    graph.bfs(v0, arr);

    graph.printTraversal(arr, "bfs traversal");
  }

  Vertex addVertex(String data) {
    Vertex vertex = new Vertex(data);

    this.vertices.add(vertex);

    return vertex;
  }

  void removeVertex(Vertex vertex) {
    this.vertices.removeIf(v -> v.equals(vertex));
  }

  void addEdge(Vertex v1, Vertex v2, Integer weight) {
    if (!this.isWeighted) {
      weight = null;
    }

    v1.addEdge(v2, weight);

    if (!this.isDirected) {
      v2.addEdge(v1, weight);
    }
  }

  void removeEdge(Vertex v1, Vertex v2) {
    v1.removeEdge(v2);

    if (!this.isDirected) {
      v2.removeEdge(v1);
    }
  }

  void dfs(Vertex start, ArrayList<Vertex> visited, ArrayList<String> arr) {
    visited.add(start);
    arr.add(start.data);

    for (Edge edge: start.edges) {
      Vertex neighbor = edge.end;

      if (!visited.contains(neighbor)) {
        this.dfs(neighbor, visited, arr);
      }
    }
  }

  void bfs(Vertex start, ArrayList<String> arr) {
    ArrayList<Vertex> visited = new ArrayList<>();
    ArrayList<Vertex> queue = new ArrayList<>();

    visited.add(start);
    queue.add(start);

    while (queue.size() > 0) {
      Vertex vertex = queue.remove(0);

      arr.add(vertex.data);

      for (Edge edge: vertex.edges) {
        Vertex neighbor = edge.end;

        if (!visited.contains(neighbor)) {
          visited.add(neighbor);
          queue.add(neighbor);
        }
      }
    }
  }
}

class Edge {
  public Vertex start;
  public Vertex end;
  public Integer weight;

  Edge(Vertex start, Vertex end, Integer weight) {
    this.start = start;
    this.end = end;
    this.weight = weight;
  }
}

class Vertex {
  public String data;
  public ArrayList<Edge> edges;

  Vertex(String data) {
    this.data = data;
    this.edges = new ArrayList<>();
  }

  boolean equals(Vertex other) {
    return this.data == other.data;
  }

  void addEdge(Vertex end, Integer weight) {
    Edge edge = new Edge(this, end, weight);

    edges.add(edge);
  }

  void removeEdge(Vertex end) {
    edges.removeIf(edge -> edge.end.equals(end));
  }
}