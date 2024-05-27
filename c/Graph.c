#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Vertex Vertex;

typedef struct {
  Vertex* start;
  Vertex* end;
  int* weight;
} Edge;

struct Vertex {
  char* data;
  Edge** edges;
  int size;
};

void addEdge(Vertex* start, Vertex* end, int* weight) {
  Edge* edge = (Edge*)malloc(sizeof(Edge));

  edge->start = start;
  edge->end = end;
  edge->weight = weight;

  start->edges = (Edge**)realloc(start->edges, (start->size + 1) * sizeof(Edge*));
  start->edges[start->size] = edge;

  start->size += 1;
}

void removeEdge(Vertex* start, Vertex* end) {
  for (int i = 0; i < start->size; i++) {
    if (start->edges[i]->end->data == end->data) {
      start->size -= 1;

      if (i == 0) {
        memmove(start->edges, start->edges + 1, (start->size) * sizeof(Edge*));
        start->edges = (Edge**)realloc(start->edges, start->size * sizeof(Edge*));
      } else if (i == start->size - 1) {
        start->edges = (Edge**)realloc(start->edges, start->size * sizeof(Edge*));
      } else {
        printf("size: %d, i: %d\n", start->size, i);
        memmove(start->edges + i, start->edges + i + 1, (start->size - i) * sizeof(Edge*));
        start->edges = (Edge**)realloc(start->edges, start->size * sizeof(Edge*));
      }

      return;
    }
  }
}

typedef struct {
  Vertex** vertices;
  bool isWeighted;
  bool isDirected;
  int size;
} Graph;

Vertex* addVertex(Graph* graph, char* data) {
  Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));

  vertex->data = (char*)malloc(50);
  strcpy(vertex->data, data);
  vertex->edges = NULL;
  vertex->size = 0;

  graph->vertices = (Vertex**)realloc(graph->vertices, (graph->size + 1) * sizeof(Vertex*));
  graph->vertices[graph->size] = vertex;
  graph->size += 1;

  return vertex;
}

void addEdgeFromGraph(Graph graph, Vertex* start, Vertex* end, int* weight) {
  addEdge(start, end, weight);

  if (!graph.isDirected) {
    addEdge(end, start, weight);
  }
}

void removeEdgeFromGraph(Graph graph, Vertex* start, Vertex* end) {
  removeEdge(start, end);

  if (!graph.isDirected) {
    removeEdge(end, start);
  }
}

void printGraph(Graph graph) {
  for (int i = 0; i < graph.size; i++) {
    Vertex* vertex = graph.vertices[i];

    printf("%s\n", vertex->data);

    for (int j = 0; j < vertex->size; j++) {
      Edge* edge = vertex->edges[j];

      if (graph.isWeighted) {
        printf("%s -> %s: %d\n", vertex->data, edge->end->data, *(edge->weight));
      } else {
        printf("%s -> %s\n", vertex->data, edge->end->data);
      }
    }
  }
}

bool arrayIncludes(Vertex** arr, Vertex* elem, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i]->data == elem->data) {
      return true;
    }
  }

  return false;
}

void printTraversal(char** arr, char* text, int size) {
  printf("%s: [", text);

  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      printf("%s]\n", arr[i]);
    } else {
      printf("%s, ", arr[i]);
    }
  }
}

void dfs(Vertex* start, Vertex*** visited, char*** arr, int* size) {
  *size += 1;
  *visited = (Vertex**)realloc(*visited, *size * sizeof(Vertex*));
  (*visited)[*size - 1] = start;
  *arr = (char**)realloc(*arr, *size * sizeof(char*));
  *(*arr + (*size - 1)) = (char*)malloc(50);
  strcpy(*(*arr + (*size - 1)), start->data);

  for (int i = 0; i < start->size; i++) {
    Vertex* neighbor = start->edges[i]->end;

    if (!arrayIncludes(*visited, neighbor, *size)) {
      dfs(neighbor, visited, arr, size);
    }
  }
}

void bfs(Vertex* start, char*** arr, int* size) {
  int size1 = 1;
  int size2 = 1;
  Vertex** visited = (Vertex**)malloc(size1 * sizeof(Vertex*));
  Vertex** queue = (Vertex**)malloc(size2 * sizeof(Vertex*));

  visited[0] = start;
  queue[0] = start;

  while (size2 > 0) {
    Vertex* vertex = queue[0];

    memmove(queue, queue + 1, size2 * sizeof(Vertex*));
    size2 -= 1;
    queue = (Vertex**)realloc(queue, size2 * sizeof(Vertex*));

    *size += 1;
    *arr = (char**)realloc(*arr, *size * sizeof(char*));
    *(*arr + (*size - 1)) = (char*)malloc(50);
    strcpy((*arr)[*size - 1], vertex->data);

    for (int i = 0; i < vertex->size; i++) {
      Edge* edge = vertex->edges[i];
      Vertex* neighbor = edge->end;

      if (!arrayIncludes(visited, neighbor, size1)) {
        size1 += 1;
        visited = (Vertex**)realloc(visited, size1 * sizeof(Vertex*));
        visited[size1 - 1] = neighbor;
        size2 += 1;
        queue = (Vertex**)realloc(queue, size2 * sizeof(Vertex*));
        queue[size2 - 1] = neighbor;
      }
    }
  }
}

int main() {
  Graph graph = { NULL, false, false, 0 };

  Vertex* v0 = addVertex(&graph, "0");
  Vertex* v1 = addVertex(&graph, "1");
  Vertex* v2 = addVertex(&graph, "2");
  Vertex* v3 = addVertex(&graph, "3");
  Vertex* v4 = addVertex(&graph, "4");

  addEdgeFromGraph(graph, v0, v1, NULL);
  addEdgeFromGraph(graph, v0, v2, NULL);
  addEdgeFromGraph(graph, v1, v2, NULL);
  addEdgeFromGraph(graph, v1, v3, NULL);
  addEdgeFromGraph(graph, v2, v4, NULL);
  addEdgeFromGraph(graph, v3, v4, NULL);

  puts("Unweighted and Undirected Graph");
  printGraph(graph);

  graph.vertices = NULL;
  graph.isWeighted = true;
  graph.size = 0;

  v0 = addVertex(&graph, "0");
  v1 = addVertex(&graph, "1");
  v2 = addVertex(&graph, "2");
  v3 = addVertex(&graph, "3");
  v4 = addVertex(&graph, "4");

  int w01 = 10;
  int w02 = 10;
  int w12 = 5;
  int w13 = 15;
  int w24 = 15;
  int w34 = 5;

  addEdgeFromGraph(graph, v0, v1, &w01);
  addEdgeFromGraph(graph, v0, v2, &w02);
  addEdgeFromGraph(graph, v1, v2, &w12);
  addEdgeFromGraph(graph, v1, v3, &w13);
  addEdgeFromGraph(graph, v2, v4, &w24);
  addEdgeFromGraph(graph, v3, v4, &w34);

  puts("\nWeighted and Undirected Graph");
  printGraph(graph);

  graph.vertices = NULL;
  graph.isDirected = true;
  graph.size = 0;

  v0 = addVertex(&graph, "0");
  v1 = addVertex(&graph, "1");
  v2 = addVertex(&graph, "2");
  v3 = addVertex(&graph, "3");
  v4 = addVertex(&graph, "4");

  addEdgeFromGraph(graph, v0, v1, &w01);
  addEdgeFromGraph(graph, v0, v2, &w02);
  addEdgeFromGraph(graph, v1, v2, &w12);
  addEdgeFromGraph(graph, v1, v3, &w13);
  addEdgeFromGraph(graph, v2, v4, &w24);
  addEdgeFromGraph(graph, v3, v4, &w34);

  puts("\nWeighted and Directed Graph");
  printGraph(graph);

  Vertex** visited = NULL;
  char** arr = NULL;
  int size = 0;

  dfs(v0, &visited, &arr, &size);

  printTraversal(arr, "\ndfs traversal", size);

  arr = NULL;
  size = 0;

  bfs(v0, &arr, &size);

  printTraversal(arr, "bfs traversal", size);

  return 0;
}