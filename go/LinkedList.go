package main

import (
	"fmt"
	"strconv"
	"strings"
	"errors"
)

type Node struct {
	data int
	next *Node
}

type LinkedList struct {
	head *Node
	length int
}

func (ll LinkedList) String() string {
	node := ll.head
	result := []string{}

	if node == nil {
		return "nil"
	} else {
		for node != nil {
			data := strconv.FormatInt(int64(node.data), 10)

			result = append(result, data)

			node = node.next
		}
	}

	result = append(result, "nil")

	return strings.Join(result, "->")
}

func (ll *LinkedList) unshift(data int) {
	node := Node{ data, nil }

	if ll.head == nil {
		ll.head = &node
	} else {
		node.next = ll.head
		ll.head = &node
	}

	ll.length += 1
}

func (ll *LinkedList) push(data int) {
	node := Node{ data, nil }

	if ll.head == nil {
		ll.head = &node
	} else {
		current := ll.head

		for current != nil {
			if current.next == nil {
				current.next = &node
				break
			} else {
				current = current.next
			}
		}
	}

	ll.length += 1
}

func (ll *LinkedList) shift() error {
	node := ll.head

	if node == nil {
		return errors.New("ZeroLengthError: Linked list length is zero")
	} else {
		ll.head = node.next
	}

	ll.length -= 1

	return nil
}

func (ll *LinkedList) pop() error {
	node := ll.head

	if node == nil {
		return errors.New("ZeroLengthError: Linked list length is zero")
	} else {
		var prev *Node = nil

		for node != nil {
			if node.next == nil {
				prev.next = nil
				break
			} else {
				prev = node
				node = node.next
			}
		}
	}

	ll.length -= 1

	return nil
}

func NewLinkedList() LinkedList {
	return LinkedList{ nil, 0 }
}

func main() {
	ll := NewLinkedList()

	for i := 1; i <= 5; i++ {
		ll.unshift(i * 5)
	}

	fmt.Printf("%v, length: %v\n", ll, ll.length)

	for i := 1; i <= 5; i++ {
		ll.push(i * 10)
	}

	fmt.Printf("%v, length: %v\n", ll, ll.length)

	ll.shift()

	fmt.Printf("%v, length: %v\n", ll, ll.length)

	ll.pop()

	fmt.Printf("%v, length: %v\n", ll, ll.length)
}