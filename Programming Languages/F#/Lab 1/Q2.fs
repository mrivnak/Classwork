// Learn more about F# at http://fsharp.org

// Write a program that uses loop.
// Compute the average of a list of integers.
// Use List comprehension to generate the List.

open System

[<EntryPoint>]
let main argv =
    let add in0 in1 =
        in0 + in1

    let rec sum arr =
        match arr with
        | [] -> 0
        | x :: xs -> add x (sum xs)

    let rec length arr =
        match arr with
        | [] -> 0
        | x :: xs -> 1 + length xs

    let avg arr =
        match arr with
        | [] -> 0.0
        | x -> float (sum arr) / float (length arr)
    printfn "%f" (avg [1..4])
    0 // return an integer exit code
