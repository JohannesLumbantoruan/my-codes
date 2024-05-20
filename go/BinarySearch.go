package main

import (
	"slices"
	"errors"
	"fmt"
)

func binarySearch(numbers []int, number int) (int, error) {
	start := 0
	end := len(numbers) - 1
	mid := (end + start) / 2

	for start <= end {
		if numbers[mid] == number {
			return mid, nil
		} else if numbers[mid] > number {
			end = mid - 1
		} else {
			start = mid + 1
		}

		mid = (end + start) / 2
	}

	return -1, errors.New("Number not found!")
}

func main() {
	// numbers := []int{ 4, 12, 100, 50, 32 }
	// number := 50
	var size int
	var num int
	var number int
	numbers := []int{}

	fmt.Println("Enter the size of the array:")
	fmt.Scanln(&size)

	fmt.Println("Enter array values:")

	for i := 0; i < size; i++ {
		fmt.Scanln(&num)
		numbers = append(numbers, num)
	}

	fmt.Println("Enter number to search:")
	fmt.Scanf("%d", &number)

	fmt.Printf("Unsorted: %v\n", numbers)

	slices.Sort(numbers)

	fmt.Printf("Sorted: %v\n", numbers)

	index, err := binarySearch(numbers, number)

	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Printf("Index of %v is: %v", number, index)
	}
}