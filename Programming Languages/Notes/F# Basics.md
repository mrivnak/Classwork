# F# Basics
### Average Function

In Python:

```python
def averageOf(numbers):
    sum = 0
    count = 0
    for n in numbers:
        sum = sum + n
        count = count + 1
    return sum / count
```

In F#:

```Fsharp
let averageOf numbers =
    let rec avg count sum numbers =
        match numbers with
        |n::rest -> avg (count+1) (n+sum) rest
        |[] -> sum / float count
    avg 0 0.0 numbers
```

### isOdd Example

```Fsharp
let isOdd x = x % 2 <> 0

let addOneIfOdd input =
    let result =
        if isOdd input then
            input+1
        else
            input
    result
printfn "%d" (addOneIfOdd 5)
;;
```

With pattern matching:

```Fsharp
let addOneIfOdd input =
    match input with 
    | input when isOdd input -> input+1
    |_ [incomplete code]
```

### Pattern matching using quards (`when` clauses)

