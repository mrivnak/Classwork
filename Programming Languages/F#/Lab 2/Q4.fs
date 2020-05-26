// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let rec vecadd list1 list2 =
        List.map2 (+) list1 list2

    let matadd vec1 vec2 =
        List.map2 (vecadd) vec1 vec2

    let M1 = [[1; 4]; [2; 5]; [3; 6]]
    let M2 = [[7; 1]; [8; 2]; [9; 3]]

    printfn "%A" (matadd M1 M2)
    0 // return an integer exit code
