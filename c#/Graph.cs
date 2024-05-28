class Edge
{
  public Vertex start;
  public Vertex end;
  public int? weight;

  public Edge(Vertex start, Vertex end, int? weight)
  {
    this.start = start;
    this.end = end;
    this.weight = weight;
  }
}

class Vertex
{
  public string data;
  public List<Edge> edges = new List<Edge>();

  public Vertex(string data)
  {
    this.data = data;
  }

  public void addEdge(Vertex end, int? weight)
  {
    var edge = new Edge(this, end, weight);

    this.edges.Add(edge);
  }

  public void removeEdge(Vertex end)
  {
    this.edges.RemoveAll((edge) => edge.end == end);
  }
}

class Graph
{
  public List<Vertex> vertices = new List<Vertex>();
  public bool isWeighted;
  public bool isDirected;

  public Graph(bool isWeighted, bool isDirected)
  {
    this.isWeighted = isWeighted;
    this.isDirected = isDirected;
  }

  public void print()
  {
    foreach (var vertex in vertices) {
      Console.WriteLine(vertex.data);

      foreach (var edge in vertex.edges) {
        if (this.isWeighted) {
          Console.WriteLine($"{vertex.data} -> {edge.end.data}: {edge.weight}");
        } else {
          Console.WriteLine($"{vertex.data} -> {edge.end.data}");
        }
      }
    }
  }

  public void PrintTraversal(List<string> arr, string text)
  {
    Console.Write($"{text}: [");

    for (int i = 0; i < arr.Count; i++) {
      if (i == arr.Count - 1) {
        Console.Write($"{arr[i]}]\n");
      } else {
        Console.Write($"{arr[i]}, ");
      }
    }
  }

  public Vertex addVertex(string data)
  {
    var vertex = new Vertex(data);

    this.vertices.Add(vertex);

    return vertex;
  }

  public void removeVertex(Vertex vertex)
  {
    this.vertices.Remove(vertex);
  }

  public void addEdge(Vertex start, Vertex end, int? weight)
  {
    if (!this.isWeighted) {
      weight = null;
    }

    start.addEdge(end, weight);

    if (!this.isDirected) {
      end.addEdge(start, weight);
    }
  }

  public void removeEdge(Vertex start, Vertex end)
  {
    start.removeEdge(end);

    if (!this.isDirected) {
      end.removeEdge(start);
    }
  }

  public void dfs(Vertex start, List<Vertex> visited, List<string> arr)
  {
    visited.Add(start);
    arr.Add(start.data);

    foreach (Edge edge in start.edges) {
      Vertex neighbor = edge.end;

      if (!visited.Contains(neighbor)) {
        this.dfs(neighbor, visited, arr);
      }
    }
  }

  public void Bfs(Vertex start, List<string> arr)
  {
    var visited = new List<Vertex>();
    var queue = new List<Vertex>();

    visited.Add(start);
    queue.Add(start);

    while (queue.Count > 0) {
      Vertex vertex = queue[0];

      queue.RemoveAt(0);

      arr.Add(vertex.data);

      foreach (Edge edge in vertex.edges) {
        Vertex neighbor = edge.end;

        if (!visited.Contains(neighbor)) {
          visited.Add(neighbor);
          queue.Add(neighbor);
        }
      }
    }
  }
}

var graph = new Graph(false, false);

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

Console.WriteLine("Unweighted and Undirected Graph");
graph.print();

graph = new Graph(true, false);

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

Console.WriteLine("\nWeighted and Undirected Graph");
graph.print();

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

Console.WriteLine("\nWeighted and Directed Graph");
graph.print();

var visited = new List<Vertex>();
var arr = new List<string>();

graph.dfs(v0, visited, arr);

graph.PrintTraversal(arr, "\ndfs traversal");

arr = new List<string>();

graph.Bfs(v0, arr);

graph.PrintTraversal(arr, "bfs traversal");