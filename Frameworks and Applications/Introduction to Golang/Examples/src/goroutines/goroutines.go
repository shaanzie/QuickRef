package goroutines

import (
	"fmt"
	"sync"
)

var wg = sync.WaitGroup{}
var m = sync.RWMutex{}

func main() {

	var msg = "hello"
	wg.Add(1)
	
	go func(msg string) {
		fmt.Println(msg)
		wg.Done()
	}(msg)
	
	msg = "Goodbye"
	
	wg.Wait()
}

func sayHello() {
	fmt.Println("Hello")
}