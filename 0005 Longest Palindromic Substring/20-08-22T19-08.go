import (
    "fmt"
)

type Idxes struct {
    start   int
    end     int
}

type PalindormicString struct {
    longest     Idxes
    tails       []Idxes
    s           []byte
}

func longestPalindrome(s string) string {
    chars := []byte(s)
    var t []Idxes
    t = append(t, Idxes{0, -1})
    p := reduce(&chars, fe, &PalindormicString{Idxes{0, -1}, t, chars})
    return string(p.s[p.longest.start:p.longest.end+1])
}

func reduce(pchars *[]byte, f func(*PalindormicString, byte) *PalindormicString, initializer *PalindormicString) *PalindormicString {
    chars := * pchars
    v := initializer
    for i := 0; i<len(chars); i++ {
        v = f(v, chars[i])
    }
    return v
}

func mapp(pl *[]Idxes, f func(*Idxes) *Idxes) *[]Idxes {
    l := *pl
    for i:=0; i<len(l); i++ {
        l[i] = *f(&l[i])
    }
    return pl
}

func filter(pl *[]Idxes, f func(*Idxes) bool) *[]Idxes {
    var s []Idxes
    l := *pl
    for i := 0; i < len(*pl); i++ {
        if f(&l[i]) {
            s = append(s, l[i])
        }
    }
    return &s
}


func fe(s *PalindormicString, d byte) *PalindormicString {
    b1 := appendTails(d, &s.tails, s.s)
    a1 := longger(&(*b1)[0], &s.longest)
    s.tails = *b1
    s.longest = *a1
    return s
}

func appendTails(c byte, pl0 *[]Idxes, s []byte) *[]Idxes {
    end := (*pl0)[0].end + 1
    f1 := getIsPalindromicFunc(c, s)
    //fmt.Printf("Before: %v\n", *pl0)
    pl1 := filter(pl0, f1)
    //fmt.Printf("After: %v\n", *pl1)
    f2 := func(a *Idxes) *Idxes {
        a.start -= 1
        a.end += 1
        return a
    }
    pl2 := mapp(pl1, f2)
    pl3 := appendNewPalindromic(pl2, f1, end)
    return pl3
}

func appendNewPalindromic(pl *[]Idxes, f func(*Idxes) bool, end int) *[]Idxes {
    l := *pl
    a := Idxes{end, end}
    if f(&a) {
        l = append(l, Idxes{end-1, end})
    }
    l = append(l, a)
    return &l
}

func getIsPalindromicFunc(c byte, s []byte) func(*Idxes) bool {
    return func (idx *Idxes) bool {
        return idx.start >= 1 && s[idx.start-1] == c
    }
}

func longger(a *Idxes, b *Idxes) *Idxes {
    if (b.end - b.start) > (a.end - a.start) {
        return b
    } else {
        return a
    }
}