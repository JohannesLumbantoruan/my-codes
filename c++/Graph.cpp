#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool vector_includes(vector<string> vec, string elem);
class Graph {
  public:
    vector<vector<int>> matrix;
    map<string, int> vertices;

    Graph(int size, bool isWeighted, bool isDirected);
    string addVertex(string vertex);
    void addEdge(string start, string end, int weight);
    void printMatrix();
    void dfs(string start, vector<string>* visited, vector<int>* arr, map<string, int>::iterator it);
    void bfs(string start, vector<int>* arr, map<string, int>::iterator it);
    void printTraversal(vector<int> arr, string text);

  private:
    int size;
    bool isWeighted;
    bool isDirected;
};

int main() {
  Graph* graph = new Graph(5, false, false);

  string a = graph->addVertex("A");
  string b = graph->addVertex("B");
  string c = graph->addVertex("C");
  string d = graph->addVertex("D");
  string e = graph->addVertex("E");

  graph->addEdge(a, b, 0);
  graph->addEdge(a, c, 0);
  graph->addEdge(b, c, 0);
  graph->addEdge(b, d, 0);
  graph->addEdge(c, e, 0);
  graph->addEdge(d, e, 0);

  cout << "Unweighted and Undirected Graph" << endl;
  graph->printMatrix();

  graph = new Graph(5, true, false);

  a = graph->addVertex("A");
  b = graph->addVertex("B");
  c = graph->addVertex("C");
  d = graph->addVertex("D");
  e = graph->addVertex("E");

  graph->addEdge(a, b, 10);
  graph->addEdge(a, c, 10);
  graph->addEdge(b, c, 5);
  graph->addEdge(b, d, 15);
  graph->addEdge(c, e, 15);
  graph->addEdge(d, e, 5);

  cout << "\nWeighted and Undirected Graph" << endl;
  graph->printMatrix();

  graph = new Graph(5, true, true);

  a = graph->addVertex("A");
  b = graph->addVertex("B");
  c = graph->addVertex("C");
  d = graph->addVertex("D");
  e = graph->addVertex("E");

  graph->addEdge(a, b, 10);
  graph->addEdge(a, c, 10);
  graph->addEdge(b, c, 5);
  graph->addEdge(b, d, 15);
  graph->addEdge(c, e, 15);
  graph->addEdge(d, e, 5);

  cout << "\nWeighted and Directed Graph" << endl;
  graph->printMatrix();

  vector<string> visited;
  vector<int> arr;
  map<string, int>::iterator it = graph->vertices.begin();

  graph->dfs(a, &visited, &arr, it);

  graph->printTraversal(arr, "\ndfs traversal");

  arr.clear();

  graph->bfs(a, &arr, it);

  graph->printTraversal(arr, "bfs traversal");

  return 0;
}

Graph::Graph(int size, bool isWeighted, bool isDirected) {
  this->size = size;
  this->isWeighted = isWeighted;
  this->isDirected = isDirected;

  for (int i = 0; i < this->size; i++) {
    vector<int> col;

    for (int j = 0; j < this->size; j++) {
      col.push_back(0);
    }

    matrix.push_back(col);
  }
}

string Graph::addVertex(string vertex) {
  if (this->vertices.size() < this->size) {
    this->vertices[vertex] = this->vertices.size();
  }

  return vertex;
}

void Graph::addEdge(string start, string end, int weight) {
  int s = this->vertices[start];
  int e = this->vertices[end];

  if (this->isWeighted) {
    this->matrix[s][e] = weight;

    if (!this->isDirected) {
      this->matrix[e][s] = weight;
    }
  } else {
    this->matrix[s][e] = 1;

    if (!this->isDirected) {
      this->matrix[e][s] = 1;
    }
  }
}

void Graph::printMatrix() {
  cout << "  ";

  for (map<string, int>::iterator it = this->vertices.begin(); it != this->vertices.end(); it++) {
    cout << " " << it->first << " ";
  }

  cout << endl;

  map<string, int>::iterator it = this->vertices.begin();

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {      
      if (j == 0) {
        cout << (it++)->first << " ";
      }

      if (this->matrix[i][j] < 10) {
        cout << " " << this->matrix[i][j] << " ";
      } else {
        cout << this->matrix[i][j] << " ";
      }
    }

    cout << endl;
  }
}

void Graph::dfs(string start, vector<string>* visited, vector<int>* arr, map<string, int>::iterator it) {
  int vertex = this->vertices[start]; 
  visited->push_back(start);
  arr->push_back(vertex);

  for (int i = 0; i < this->size; i++) {
    int n = this->matrix[vertex][i];

    if (n > 0) {
      string neighbor = next(it, i)->first;

      if (!vector_includes(*visited, neighbor)) {
        this->dfs(neighbor, visited, arr, it);
      }
    }
  }
}

void Graph::bfs(string start, vector<int>* arr, map<string, int>::iterator it) {
  vector<string> visited;
  vector<string> queue;
  visited.push_back(start);
  queue.push_back(start);

  while (queue.size() > 0) {
    int vertex = this->vertices[queue[0]];

    queue.erase(queue.begin());

    arr->push_back(vertex);

    for (int i = 0; i < this->size; i++) {
      int n = this->matrix[vertex][i];

      if (n > 0) {
        string neighbor = next(it, i)->first;

        if (!vector_includes(visited, neighbor)) {
          visited.push_back(neighbor);
          queue.push_back(neighbor);
        }
      }
    }
  }
}

void Graph::printTraversal(vector<int> arr, string text) {
  cout << text << ": [";

  for (int i = 0; i < arr.size(); i++) {
    if (i == arr.size() - 1) {
      cout << arr[i] << "]\n";
    } else {
      cout << arr[i] << ", ";
    }
  }
}

bool vector_includes(vector<string> vec, string elem) {
  for (string v: vec) {
    if (v == elem) return true;
  }

  return false;
}