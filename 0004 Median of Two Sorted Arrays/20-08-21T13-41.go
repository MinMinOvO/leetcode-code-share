import (
    "fmt"
)


func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    if len(nums1) == 0 || len(nums2) == 0 {
        if len(nums1) < len(nums2) {
            nums1, nums2 = nums2, nums1
        }
        if len(nums1) % 2 == 1 {
            return float64(nums1[len(nums1)/2])
        } else {
            return float64(nums1[len(nums1)/2] + nums1[len(nums1)/2 - 1]) / 2.0
        }
    }
    if len(nums1) > len(nums2) {
        nums1, nums2 = nums2, nums1
    }
    //For the convenience of implementation, it's actually k-1
    k := (len(nums1) + len(nums2) - 1) / 2 
    odd := (len(nums1) + len(nums2)) % 2 == 1
    return findKth(&nums1, &nums2, 0, len(nums1)-1, k, odd)
}

func findKth(nums1 *[]int, nums2 *[]int, low int, high int, k int, odd bool) float64 {
    var a, b, c, d int
    if k + 1 < len(*nums2) && (*nums1)[0] > (*nums2)[k+1] {
        if odd {
            return float64((*nums2)[k])
        } else {
            return float64((*nums2)[k]+(*nums2)[k+1]) / 2.0
        }
    }
    for {
        i := (low + high) / 2
        j := k - i
        //fmt.Println("i:", i, "j:", j)
        pi, pj := (*nums1)[i], (*nums2)[j]
        if pi > pj {// only *i maybe the (k+1)th
            c = pi
            if i >= 1 && (*nums1)[i-1] > pj {
                b = (*nums1)[i-1]
                a = max(pj, get(nums1, i-2))
            } else {
                b = pj
                a = max(get(nums1, i-1), get(nums2, j-1))
            }
        } else {
            c = pj
            if j >= 1 && (*nums2)[j-1] > pi {
                b = (*nums2)[j-1]
                a = max(pi, get(nums2, j-2))
            } else {
                b = pi
                a = max(get(nums1, i-1), get(nums2, j-1))
            }
        }
        d = min(get(nums1, i+1), get(nums2, j+1))
        if a <= b && c <= d {
            if odd {
                return float64(b)
            } else {
                return float64(b + c) / 2.0
            }
        } else {
            if pi > pj {
                high = i - 1
            } else {
                low = i + 1
            }
            //fmt.Println("Next iteration: ", high, low)
        }
    }
}


func get(arr *[]int, idx int) int {
    if idx < 0 {
        return -0x80000000
    } else if idx >= len(*arr) {
        return 0x7fffffff
    } else {
        return (*arr)[idx]
    }
}

func max(a int, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

func min(a int, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}