// Last updated: 07/11/2025, 13:41:06
func reversePrefix(word string, ch byte) string {
    j := strings.IndexByte(word, ch)
	if j < 0 {
		return word
	}
	s := []byte(word)
	for i := 0; i < j; i++ {
		s[i], s[j] = s[j], s[i]
		j--
	}
	return string(s)
    
}