package main

import "fmt"
import "math/rand"

func quicksort(array []int, first int, last int) {
  if first > last {
    return
  }
  var i int = first
//  print(i, " ")

  var j int = last
  //print(j, " ")

  var mid int = ( first + (last-first)/2)
  //print(mid, " ")
  var pivot = array[mid]

  for i < j {
    for array[i] < pivot {
      i++
    }
    for array[j] > pivot {
      j--
    }
    if i <= j {
      temp := array[i]
      array[i] = array[j]
      array[j] = temp
      i++
      j--
    }
   }
   if i < last {
     quicksort(array, i, last)
   }
   if first < j {
     quicksort(array,first,j)
   }
  return
}
func main() {
	var n int = 100
  var array = make([]int,n )

	r := rand.New(rand.NewSource(99))
	for i := 0; i < n; i++ {
		array[i] = r.Intn(100)
	}

  quicksort(array, 0, n-1)

  for i := 0; i < n; i++ {
    fmt.Print(array[i],  " ")
  }
}
