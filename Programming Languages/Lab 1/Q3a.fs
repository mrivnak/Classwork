// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let round input =
        if input >= 100
        then 100
        elif input < 0
            then 0
            else input

    printfn "%d" (round 110)
    printfn "%d" (round 50)
    printfn "%d" (round -10)
    
    0 // return an integer exit code
