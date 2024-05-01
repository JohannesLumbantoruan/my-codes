package main

import (
	"fmt"
)

func fibonacci(n int) int {
	if (n == 0) {
		return 0
	} else if (n <= 2) {
		return 1
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2)
	}
}
func main() {
	var n int

	fmt.Print("Enter a number: ")
	fmt.Scan(&n)

	result := fibonacci(n)

	fmt.Printf("Fibonacci of %v: %v", n, result)
}