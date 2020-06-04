// Learn more about F# at http://fsharp.org

open System
open System.Diagnostics

[<EntryPoint>]
let main argv =
    // Setup for determining CPU time
    let proc = Process.GetCurrentProcess()
    let beginTime = proc.TotalProcessorTime

    let isPrimeMultipleTest n  x =  x = n || x % n <> 0

    let rec removeAllMultiples listn listx =
        match listn with
        | head :: tail -> removeAllMultiples tail (List.filter (isPrimeMultipleTest head) listx)
        | [] -> listx

    let getPrimesUpTo n =
        let max = int (sqrt (float n))
        removeAllMultiples [ 2 .. max ] [ 1 .. n ]

    printfn "Primes Up To %d:\n %A" 10000 (getPrimesUpTo 10000)

    let cpuTime = (proc.TotalProcessorTime - beginTime).TotalMilliseconds
    printfn "CPU Time = %d ms\n" (int64 cpuTime)
    0 // return an integer exit code
