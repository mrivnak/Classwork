// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let rec fact x =
        match x with
        | 0 -> bigint 1
        | _ -> bigint x * fact (x - 1)

    let C n k =
        (fact n) / ((fact k) * (fact (n - k)))
    printfn "%A" (C 20 5)
    0 // return an integer exit code
