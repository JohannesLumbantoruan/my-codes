package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
)

type CaesarCipher struct {}

func (cc CaesarCipher) encode(plainText string, shift rune) string {
	result := []rune{}
	var code rune = 0

	for _, char := range plainText {
		if char >= 97 && char <= 122 {
			code = ((char - 97) + shift) % 26 + 97

			result = append(result, code)
		} else {
			result = append(result, char)
		}
	}

	return string(result)
}

func (cc CaesarCipher) decode(cipherText string, shift rune) string {
	result := []rune{}
	var code rune = 0

	for _, char := range cipherText {
		if char >= 97 && char <= 122 {
			code = ((char - 97) - shift) % 26

			if code < 0 {
				code += 26
			}

			code += 97

			result = append(result, code)
		} else {
			result = append(result, char)
		}
	}

	return string(result)
}

func main() {
	option := 0

	fmt.Println(`CAESAR CIPHER
1. Encode
2. Decode`)
	fmt.Println("\nChoose option: ")

	fmt.Scanln(&option)

	fmt.Println("Enter text:")

	var shift rune = 0

	text, _ := bufio.NewReader(os.Stdin).ReadString('\n')

	text = strings.ToLower(text)

	fmt.Println("Enter shift:")

	fmt.Scanln(&shift)

	result := ""

	if option == 1 {
		result = CaesarCipher{}.encode(text, shift)

		fmt.Printf("Cipher text: %v", result)
	}

	if option == 2 {
		result = CaesarCipher{}.decode(text, shift)

		fmt.Printf("Plain text: %v", result)
	}
}