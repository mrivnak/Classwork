// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let vecadd list1 list2 =
        List.map2 (+) list1 list2
        // List.map2 (fun x y -> x + y) list1 list2
        // Originally the function on the previous line was (fun x y -> x + y)
        // The F# linter in VS Code suggested I not reimplement a function where no arguments are mutable
        // That led to some research and the simple function used above

    printfn "%A" (vecadd [1; 2; 3] [4; 5; 6])
    printfn "%A" (vecadd [1; 2; -3; 4] [4; -5; 6; 7])
    0 // return an integer exit code
