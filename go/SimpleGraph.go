package main

import (
	"fmt"
	"slices"
)

type SimpleGraph struct {
	size int
	isWeighted bool
	isDirected bool
	matrix [][]int
	vertices map[string]int
	keys []string
}

func NewSimpleGraph(size int, isWeighted bool, isDirected bool) SimpleGraph {
	matrix := [][]int{}

	for i := 0; i < size; i++ {
		col := make([]int, size)

		matrix = append(matrix, col)
	}

	return SimpleGraph{ size, isWeighted, isDirected, matrix, map[string]int{}, []string{} }
}

func (sg *SimpleGraph) addVertex(data string) {
	if len(sg.vertices) < sg.size {
		sg.vertices[data] = len(sg.keys)
		sg.keys = append(sg.keys, data)
	}
}

func (sg *SimpleGraph) addEdge(start, end string, weight int) {
	if !sg.isWeighted {
		weight = 1
	}

	vStart := sg.vertices[start]
	vEnd := sg.vertices[end]

	sg.matrix[vStart][vEnd] = weight

	if !sg.isDirected {
		sg.matrix[vEnd][vStart] = weight
	}
}

func (sg *SimpleGraph) removeEdge(start, end string) {
	vStart := sg.vertices[start]
	vEnd := sg.vertices[end]

	sg.matrix[vStart][vEnd] = 0

	if !sg.isDirected {
		sg.matrix[vEnd][vStart] = 0
	}
}

func (sg *SimpleGraph) printGraph() {
	for i := 0; i < sg.size; i++ {
		if i == 0 {
			fmt.Printf("   %v ", sg.keys[i])
		} else if i == sg.size - 1 {
			fmt.Printf(" %v\n", sg.keys[i])
		} else {
			fmt.Printf(" %v ", sg.keys[i])
		}
	}

	for i := 0; i < sg.size; i++ {
		for j := 0; j < sg.size; j++ {
			if j == 0 {
				fmt.Printf("%v ", sg.keys[i])
			}

			if sg.matrix[i][j] < 10 {
				fmt.Printf(" %v ", sg.matrix[i][j])
			} else {
				fmt.Printf("%v ", sg.matrix[i][j])
			}
		}
		fmt.Print("\n")
	}
}

func (sg *SimpleGraph) dfs(start string, visited *[]string, arr *[]int) {
	vertex := sg.vertices[start]
	*visited = append(*visited, start)
	*arr = append(*arr, vertex)

	for i := 0; i < sg.size; i++ {
		n := sg.matrix[vertex][i]

		if n > 0 {
			neighbor := sg.keys[i]

			if !slices.Contains(*visited, neighbor) {
				sg.dfs(neighbor, visited, arr)
			}
		}
	}
}

func (sg *SimpleGraph) bfs(start string, arr *[]int) {
	visited := []string{ start }
	queue := []string { start }

	for len(queue) > 0 {
		vertex := queue[0]

		queue = queue[1:]

		*arr = append(*arr, sg.vertices[vertex])

		for i := 0; i < sg.size; i++ {
			n := sg.matrix[sg.vertices[vertex]][i]

			if n > 0 && !slices.Contains(visited, sg.keys[i]) {
				visited = append(visited, sg.keys[i])
				queue = append(queue, sg.keys[i])
			}
		}
	}
}

func main() {
	graph := NewSimpleGraph(5, false, false)

	graph.addVertex("A")
	graph.addVertex("B")
	graph.addVertex("C")
	graph.addVertex("D")
	graph.addVertex("E")

	graph.addEdge("A", "B", 0)
	graph.addEdge("A", "C", 0)
	graph.addEdge("B", "C", 0)
	graph.addEdge("B", "D", 0)
	graph.addEdge("C", "E", 0)
	graph.addEdge("D", "E", 0)

	fmt.Println("Unweighted and Undirected Graph")
	graph.printGraph()

	graph = NewSimpleGraph(5, true, false)

	graph.addVertex("A")
	graph.addVertex("B")
	graph.addVertex("C")
	graph.addVertex("D")
	graph.addVertex("E")

	w01 := 10
	w02 := 10
	w12 := 5
	w13 := 15
	w24 := 15
	w34 := 5

	graph.addEdge("A", "B", w01)
	graph.addEdge("A", "C", w02)
	graph.addEdge("B", "C", w12)
	graph.addEdge("B", "D", w13)
	graph.addEdge("C", "E", w24)
	graph.addEdge("D", "E", w34)

	fmt.Println("\nWeighted and Undirected Graph")
	graph.printGraph()

	graph = NewSimpleGraph(5, true, true)

	graph.addVertex("A")
	graph.addVertex("B")
	graph.addVertex("C")
	graph.addVertex("D")
	graph.addVertex("E")

	graph.addEdge("A", "B", w01)
	graph.addEdge("A", "C", w02)
	graph.addEdge("B", "C", w12)
	graph.addEdge("B", "D", w13)
	graph.addEdge("C", "E", w24)
	graph.addEdge("D", "E", w34)

	fmt.Println("\nWeighted and Directed Graph")
	graph.printGraph()

	visited := []string{}
	arr := []int{}

	graph.dfs("A", &visited, &arr)

	fmt.Println("\ndfs traversal:", arr)

	arr = []int{}

	graph.bfs("A", &arr)

	fmt.Println("bfs traversal:", arr)
}