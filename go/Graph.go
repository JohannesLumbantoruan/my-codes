package main

import (
	"slices"
	"fmt"
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

		result += "\n"
	}

	return result
}

func main() {
	graph := Graph{ []*Vertex{}, false, false }

	v1 := graph.addVertex("A")
	v2 := graph.addVertex("B")
	v3 := graph.addVertex("C")

	graph.addEdge(v1, v2, nil)
	graph.addEdge(v1, v3, nil)
	graph.addEdge(v2, v3, nil)

	fmt.Println("Unweighted and Undirected Graph")

	fmt.Println(graph)

	graph = Graph{ []*Vertex{}, true, false }

	v1 = graph.addVertex("A")
	v2 = graph.addVertex("B")
	v3 = graph.addVertex("C")

	w12 := 10
	w23 := 5
	w13 := 15

	fmt.Println("Weighted Graphs")

	graph.addEdge(v1, v2, &w12)
	graph.addEdge(v2, v3, &w23)
	graph.addEdge(v1, v3, &w13)

	fmt.Println(graph)

	fmt.Println("Weighted and Directed Graph")

	graph = Graph{ []*Vertex{}, true, true }

	v1 = graph.addVertex("A")
	v2 = graph.addVertex("B")
	v3 = graph.addVertex("C")

	w31 := 20

	graph.addEdge(v1, v2, &w12)
	graph.addEdge(v1, v3, &w13)
	graph.addEdge(v2, v3, &w23)
	graph.addEdge(v3, v1, &w31)

	fmt.Println(graph)
}