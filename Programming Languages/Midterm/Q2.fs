// Learn more about F# at http://fsharp.org

open System

[<EntryPoint>]
let main argv =
    let countChar (tuple: int*int*int*int*int) (x: char): (int*int*int*int*int) =
        match tuple with
        | (a, b, c, d, e) ->
            match x with
            | 'a' | 'A' -> (a+1, b, c, d, e)
            | 'e' | 'E' -> (a, b+1, c, d, e)
            | 'i' | 'I' -> (a, b, c+1, d, e)
            | 'o' | 'O' -> (a, b, c, d+1, e)
            | 'u' | 'U' -> (a, b, c, d, e+1)
            | _ -> (a, b, c, d, e)
    
    let countVowels (str: string): (int*int*int*int*int) =
        List.fold (countChar) (0, 0, 0, 0, 0) (List.ofSeq str)

    let output = countVowels "A bird in hand is worth two in the bush"

    printfn "%A" output
    0 // return an integer exit code
