// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let round input =
        match input with
        | x when x >= 100 -> 100
        | x when x < 0 -> 0
        | _ -> input

    printfn "%d" (round 110)
    printfn "%d" (round 50)
    printfn "%d" (round -10)
    
    0 // return an integer exit code
