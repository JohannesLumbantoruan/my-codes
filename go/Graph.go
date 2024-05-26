package main

import (
	"fmt"
	"slices"
	"strings"
)

type Edge struct {
	start *Vertex
	end *Vertex
	weight *int
}

type Vertex struct {
	data string
	edges []Edge
}

func (v Vertex) equals(other Vertex) bool {
	return v.data == other.data
}

func (v *Vertex) addEdge(end *Vertex, weight *int) {
	v.edges = append(v.edges, Edge{ v, end, weight })
}

func (v *Vertex) removeEdge(end *Vertex) {
	v.edges = slices.DeleteFunc(v.edges, func (edge Edge) bool {
		return edge.end.equals(*end)
	})
}

type Graph struct {
	vertices []*Vertex
	isWeighted bool
	isDirected bool
}

func (g *Graph) addVertex(data string) *Vertex {
	vertex := &Vertex{ data, []Edge{} }
	g.vertices = append(g.vertices, vertex)

	return vertex
}

func (g *Graph) removeVertex(vertex *Vertex) {
	g.vertices = slices.DeleteFunc(g.vertices, func (v *Vertex) bool {
		return v.data == vertex.data
	})
}

func (g Graph) addEdge(vertex1, vertex2 *Vertex, weight *int) {
	if !g.isWeighted {
		weight = nil
	}

	vertex1.addEdge(vertex2, weight)

	if !g.isDirected {
		vertex2.addEdge(vertex1, weight)
	}
}

func (g *Graph) removeEdge(vertex1, vertex2 *Vertex) {
	vertex1.removeEdge(vertex2)

	if !g.isDirected {
		vertex2.removeEdge(vertex1)
	}
}

func (g Graph) String() string {
	result := ""

	for _, vertex := range g.vertices {
		result += fmt.Sprintf("%v\n", vertex.data)

		if g.isWeighted {
			for _, edge := range vertex.edges {
				result += fmt.Sprintf("%v -> %v: %v\n", vertex.data, edge.end.data, *edge.weight)
			}
		} else {
			for _, edge := range vertex.edges {
				result += fmt.Sprintf("%v -> %v\n", vertex.data, edge.end.data)
			}
		}
	}

	return result
}

func (g *Graph) dfs(start *Vertex, visited *[]*Vertex, arr *[]string) {
	*arr = append(*arr, start.data)
	*visited = append(*visited, start)

	for _, edge := range start.edges {
		neighbor := edge.end

		if !slices.Contains(*visited, neighbor) {
			g.dfs(neighbor, visited, arr)
		}
	}
}

func (g *Graph) bfs(start *Vertex, arr *[]string) {
	visited := []*Vertex{ start }
	queue := []*Vertex{ start }

	for len(queue) > 0 {
		vertex := queue[0]
		queue = queue[1:]

		*arr = append(*arr, vertex.data)

		for _, edge := range vertex.edges {
			neighbor := edge.end

			if !slices.Contains(visited, neighbor) {
				visited = append(visited, neighbor)
				queue = append(queue, neighbor)
			}
		}
	}
}

func main() {
	graph := Graph{ []*Vertex{}, false, false }

	v0 := graph.addVertex("0")
	v1 := graph.addVertex("1")
	v2 := graph.addVertex("2")
	v3 := graph.addVertex("3")
	v4 := graph.addVertex("4")

	graph.addEdge(v0, v1, nil)
	graph.addEdge(v0, v2, nil)
	graph.addEdge(v1, v2, nil)
	graph.addEdge(v1, v3, nil)
	graph.addEdge(v2, v4, nil)
	graph.addEdge(v3, v4, nil)

	fmt.Println("Unweighted and Undirected Graph")

	fmt.Print(graph)

	visited := []*Vertex{}
	arr := []string{}

	graph.dfs(v0, &visited, &arr)

	fmt.Printf("dfs traversal: %v\n", strings.Join(arr, "->"))

	arr = []string{}

	graph.bfs(v0, &arr)

	fmt.Printf("bfs traversal: %v\n", strings.Join(arr, "->"))

	graph = Graph{ []*Vertex{}, true, false }

	w12 := 10
	w13 := 10
	w23 := 5
	w24 := 15
	w35 := 15
	w45 := 5

	fmt.Println("\nWeighted Graphs")

	v0 = graph.addVertex("0")
	v1 = graph.addVertex("1")
	v2 = graph.addVertex("2")
	v3 = graph.addVertex("3")
	v4 = graph.addVertex("4")

	graph.addEdge(v0, v1, &w12)
	graph.addEdge(v0, v2, &w13)
	graph.addEdge(v1, v2, &w23)
	graph.addEdge(v1, v3, &w24)
	graph.addEdge(v2, v4, &w35)
	graph.addEdge(v3, v4, &w45)

	fmt.Print(graph)

	visited = []*Vertex{}
	arr = []string{}

	graph.dfs(v0, &visited, &arr)

	fmt.Printf("dfs traversal: %v\n", strings.Join(arr, "->"))

	arr = []string{}

	graph.bfs(v0, &arr)

	fmt.Printf("bfs traversal: %v\n", strings.Join(arr, "->"))


	fmt.Println("\nWeighted and Directed Graph")

	graph = Graph{ []*Vertex{}, true, true }

	v0 = graph.addVertex("0")
	v1 = graph.addVertex("1")
	v2 = graph.addVertex("2")
	v3 = graph.addVertex("3")
	v4 = graph.addVertex("4")

	graph.addEdge(v0, v1, &w12)
	graph.addEdge(v0, v2, &w13)
	graph.addEdge(v1, v2, &w23)
	graph.addEdge(v1, v3, &w24)
	graph.addEdge(v2, v4, &w35)
	graph.addEdge(v3, v4, &w45)

	fmt.Print(graph)

	visited = []*Vertex{}
	arr = []string{}

	graph.dfs(v0, &visited, &arr)

	fmt.Printf("dfs traversal: %v\n", strings.Join(arr, "->"))

	arr = []string{}

	graph.bfs(v0, &arr)

	fmt.Printf("bfs traversal: %v\n", strings.Join(arr, "->"))
}