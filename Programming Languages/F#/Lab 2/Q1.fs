// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let cubes list =
        List.map (fun n -> n * n * n) list
    printfn "%A" (cubes [2; 4; 6])
    0 // return an integer exit code
