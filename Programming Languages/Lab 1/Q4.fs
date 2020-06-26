// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let rec fact x =
        match x with
        | 0 -> 1
        | _ -> x * fact (x - 1)

    printfn "%d" (fact 5)
    0 // return an integer exit code
