// Learn more about F# at http://fsharp.org

// Implement an add function, run the following tests
//      add 25 15
//      add 18 34 13 19

open System

[<EntryPoint>]
let main argv =
    let add in0 in1 =
        in0 + in1

    let rec sum list =
        match list with
        | [] -> 0
        | x :: xs -> add x (sum xs)

    printfn "%d" (add 25 15)
    printfn "%d" (sum [18; 34; 13; 19])
    0 // return an integer exit code
