package main

import "fmt"

func uniqueMorseRepresentations(words []string) int {
	morse := []string{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}
	morseMap := make(map[rune]string)
	var k rune = 'a'
	for i := 0; i < len(morse); i++ {
		morseMap[k] = morse[i]
		k++
	}

	m := make(map[string]int)
	for _, word := range words {
		var key string
		// fmt.Println(word)
		for _, w := range word {
			key += morseMap[w]
		}
		m[key]++
	}

	return len(m)
}

func main() {
	fmt.Println(uniqueMorseRepresentations([]string{"gin", "zen", "gig", "msg"}))
}
