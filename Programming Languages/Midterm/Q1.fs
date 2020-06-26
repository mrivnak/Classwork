// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let data = [|6; 92; 3; 7; 6; 77; 13; 9; 11; 46; 19; 24; 30; 55; 4|]

    printfn "Unsorted array: %A" data

    let swap (i: int) (j: int) (arr: 'a[]) = 
        let temp = arr.[i]
        arr.[i] <- arr.[j]
        arr.[j] <- temp
    

    let sort (arr: 'a[]) =
        for i = arr.Length - 1 downto 0 do
            for j = 1 to i do
                if arr.[j-1] > arr.[j] then
                    swap (j-1) j arr
    
    sort data

    printfn "Sorted array: %A" data
    0 // return an integer exit code
