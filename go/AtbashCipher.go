package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
)

func atbashCipher(plainText string) string {
	result := []rune{}
	var c rune = 0

	for _, char := range plainText {
		if char >= 97 && char <= 122 {
			c = (25 - (char - 97)) % 26 + 97

			result = append(result, c)
		} else {
			result = append(result, char)
		}
	}

	return string(result)
}

func main() {
	fmt.Println("Enter string to encode/decode:")
	
	plainText, _ := bufio.NewReader(os.Stdin).ReadString('\n')

	result := atbashCipher(strings.ToLower(plainText))

	fmt.Printf("Result: %v", result)
}