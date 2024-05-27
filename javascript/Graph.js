class Edge {
  constructor(start, end, weight) {
    this.start = start;
    this.end = end;
    this.weight = weight;
  }
}

class Vertex {
  constructor(data) {
    this.data = data;
    this.edges = [];
  }

  addEdge(end, weight) {
    const edge = new Edge(this, end, weight);

    this.edges.push(edge);
  }

  removeEdge(end) {
    this.edges = this.edges.filter((edge) => {
      return !edge.end.data === end.data;
    });
  }
}

class Graph {
  constructor(isWeighted, isDirected) {
    this.vertices = [];
    this.isWeighted = isWeighted;
    this.isDirected = isDirected;
  }

  print() {
    for (const vertex of this.vertices) {
      console.log(`${vertex.data}`);

      for (const edge of vertex.edges) {
        if (this.isWeighted) {
          console.log(`${vertex.data} -> ${edge.end.data}: ${edge.weight}`);
        } else {
          console.log(`${vertex.data} -> ${edge.end.data}`);
        }
      }
    }
  }

  addVertex(data) {
    const vertex = new Vertex(data);

    this.vertices.push(vertex);

    return vertex;
  }

  removeVertex(vertex) {
    this.vertices = this.vertices.filter((v) => {
      return !v.data === vertex.data;
    });
  }

  addEdge(start, end, weight) {
    if (!this.isWeighted) {
      weight = null;
    }

    start.addEdge(end, weight);

    if (!this.isDirected) {
      end.addEdge(start, weight);
    }
  }

  removeEdge(start, end) {
    start.removeEdge(end);

    if (!this.isDirected) {
      end.removeEdge(start);
    }
  }

  dfs(start, visited, arr) {
    visited.push(start);
    arr.push(start.data);

    for (const edge of start.edges) {
      const neighbor = edge.end;

      if (!visited.includes(neighbor)) {
        this.dfs(neighbor, visited, arr);
      }
    }
  }

  bfs(start, arr) {
    const visited = [start];
    const queue = [start];

    while (queue.length > 0) {
      const vertex = queue.shift();

      arr.push(vertex.data);

      for (const edge of vertex.edges) {
        const neighbor = edge.end;

        if (!visited.includes(neighbor)) {
          visited.push(neighbor);
          queue.push(neighbor);
        }
      }
    }
  }
}

let graph = new Graph(false, false);

let v0 = graph.addVertex('0');
let v1 = graph.addVertex('1');
let v2 = graph.addVertex('2');
let v3 = graph.addVertex('3');
let v4 = graph.addVertex('4');

graph.addEdge(v0, v1, null);
graph.addEdge(v0, v2, null);
graph.addEdge(v1, v2, null);
graph.addEdge(v1, v3, null);
graph.addEdge(v2, v4, null);
graph.addEdge(v3, v4, null);

console.log('Unweighted and Undirected Graph');
graph.print();

graph = new Graph(true, false);

v0 = graph.addVertex('0');
v1 = graph.addVertex('1');
v2 = graph.addVertex('2');
v3 = graph.addVertex('3');
v4 = graph.addVertex('4');

const w01 = 10;
const w02 = 10;
const w12 = 5;
const w13 = 15;
const w24 = 15;
const w34 = 5;

graph.addEdge(v0, v1, w01);
graph.addEdge(v0, v2, w02);
graph.addEdge(v1, v2, w12);
graph.addEdge(v1, v3, w13);
graph.addEdge(v2, v4, w24);
graph.addEdge(v3, v4, w34);

console.log('\nWeighted and Undirected Graph');
graph.print();

graph = new Graph(true, true);

v0 = graph.addVertex('0');
v1 = graph.addVertex('1');
v2 = graph.addVertex('2');
v3 = graph.addVertex('3');
v4 = graph.addVertex('4');

graph.addEdge(v0, v1, w01);
graph.addEdge(v0, v2, w02);
graph.addEdge(v1, v2, w12);
graph.addEdge(v1, v3, w13);
graph.addEdge(v2, v4, w24);
graph.addEdge(v3, v4, w34);

console.log('\nWeighted and Directed Graph');
graph.print();

const visited = [];
let arr = [];

graph.dfs(v0, visited, arr);

console.log(`\ndfs traversal: ${arr.join('->')}`);

arr = [];

graph.bfs(v0, arr);

console.log(`bfs traversal: ${arr.join('->')}`);