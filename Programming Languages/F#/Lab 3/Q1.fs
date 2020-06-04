// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let isPrimeMultipleTest n  x =  x = n || x % n <> 0

    let rec removeAllMultiples listn listx =
        match listn with
        | head :: tail -> removeAllMultiples tail (List.filter (isPrimeMultipleTest head) listx)
        | [] -> listx

    let getPrimesUpTo n =
        let max = int (sqrt (float n))
        removeAllMultiples [ 2 .. max ] [ 1 .. n ]

    printfn "Primes Up To %d:\n %A" 10000 (getPrimesUpTo 10000)
    0 // return an integer exit code
