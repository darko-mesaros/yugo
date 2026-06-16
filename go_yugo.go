package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	data := []int64{120259084288, 63763084476416, 140735340871680, 70368209387520, 140737463181312, 109951162773504, 76965813942272, 10995116277504, 1099511627664, 824633720816, 549755813872, 137438953456, 21474836472, 5368709116, 4831838192, 66846712, 7372784, 1056752, 8188, 16382, 8184, 3840}
	hash := func(r rune) rune {
		if r == '0' {
			return ' '
		}
		return '#'
	}
	for _, n := range data {
		myString := string(strconv.FormatInt(n, 2)[:])
		fmt.Printf("%s\n", strings.Map(hash, fmt.Sprintf("%048s", myString)))
	}
}
