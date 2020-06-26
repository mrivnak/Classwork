// Learn more about F# at http://fsharp.org

open System
open System.Collections.Generic

[<EntryPoint>]
let main argv =
    let removeAllMultiples listn listx =
        let mutable output = new List<int>()
        output.AddRange(listx)
        for i in listn do
            for j in listx do
                if (j % i = 0 && j <> i) then
                    output.Remove(j) |> ignore
        output


    let getPrimesUpTo n =
        let max = int (sqrt (float n))
        removeAllMultiples [ 2 .. max ] [ 1 .. n ]

    printfn "Primes Up To %d:\n %A" 10000 ((getPrimesUpTo 10000).ToArray())
    0 // return an integer exit code
