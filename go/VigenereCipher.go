package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
)

type VigenereCipher struct {
	key string
}

func (vc *VigenereCipher) normalizeKey(length int) {
	keyLength := len(vc.key)
	repeat := length / keyLength
	left := length % keyLength
	normalizedKey := ""

	for i := 0; i < repeat; i++ {
		normalizedKey += vc.key
	}

	normalizedKey += vc.key[:left]

	vc.key = normalizedKey
}

func (vc *VigenereCipher) encode(plainText string) string {
	if len(vc.key) < len(plainText) {
		vc.normalizeKey(len(plainText))
	}

	var chr rune = 0

	result := []rune{}

	for i, char := range plainText {
		if char >= 97 && char <= 122 {
			chr = ((char - 97) + (rune(vc.key[i]) - 97)) % 26 + 97

			result = append(result, chr)
		} else {
			result = append(result, char)
		}
	}

	return string(result)
}

func (vc *VigenereCipher) decode(cipherText string) string {
	if len(vc.key) < len(cipherText) {
		vc.normalizeKey(len(cipherText))
	}

	var chr rune = 0

	result := []rune{}

	for i, char := range cipherText {
		if char >= 97 && char <= 122 {
			chr = ((char - 97) - (rune(vc.key[i]) - 97)) % 26

			if chr < 0 {
				chr += 26
			}

			chr += 97

			result = append(result, chr)
		} else {
			result = append(result, char)
		}
	}

	return string(result)
}

func main() {
	fmt.Println(`VIGENERE CIPHER
1. Encode
2. Decode
	`)

	fmt.Println("Choose an option:")

	option := 0

	fmt.Scanln(&option)

	fmt.Println("Enter text:")

	text, _ := bufio.NewReader(os.Stdin).ReadString('\n')

	text = strings.ToLower(text)

	fmt.Println("Enter key:")

	key, _ := bufio.NewReader(os.Stdin).ReadString('\n')

	key = strings.TrimSpace(key)

	vc := VigenereCipher{ key }

	if option == 1 {
		result := vc.encode(text)

		fmt.Printf("Cipher text: %v", result)
	}

	if option == 2 {
		result := vc.decode(text)

		fmt.Printf("Plain text: %v", result)
	}
}