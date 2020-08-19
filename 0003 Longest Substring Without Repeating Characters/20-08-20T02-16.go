import (
    "strings"
)

func lengthOfLongestSubstring(s string) int {
    var letterAppears [256]int
    for i := 0; i < 256; i++ {
        letterAppears[i] = -1
    }
    return length([]byte(s), 0, -1, letterAppears)
}

func length(chars []byte, startIdx int, endIdx int, letterAppears [256]int) int {
    i := endIdx + 1
    for ; i < len(chars); i++ {
        letterIdx := chars[i]
        appearIdx := letterAppears[letterIdx]
        if appearIdx >= 0 {
            la := i - startIdx
            for j := startIdx; j < appearIdx; j++ {
                letterAppears[chars[j]] = -1
            }
            letterAppears[letterIdx] = i
            lb := length(chars, appearIdx+1, i, letterAppears)
            if la < lb {
                return lb
            } else {
                return la
            }
        } else {
            letterAppears[letterIdx] = i
        }
    }
    return i - startIdx
}