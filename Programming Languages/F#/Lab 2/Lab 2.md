# Lab 2

1. Write a function cubes that will display the cubes of a list of positive integers using the Lambda expression

    ```fsharp
    (fun n -> n * n * n)
    ```

    Test the function for the list [2; 4; 6]

    ```fsharp
    let main argv =
        let cubes list =
            List.map (fun n -> n * n * n) list
        printfn "%A" (cubes [2; 4; 6])
        0 // return an integer exit code
    ```

    ```plaintext
    [8; 64; 216]
    ```

2. In mathematics, the binomial coefficient C(n, k) is the number of ways of picking ‘k’ unordered outcomes from ‘n’ possibilities. It is given by the formula:

    ```plaintext
    C (n,k) = n! / (k!(n-k)!)
    ```

    Implement the function C in F# and run the following test. Note that the factorials for the given values could overflow the stack so you must use the integer type BigInt of unlimited precision. This means you will have to cast integers to bigint in the computation. You can perform computations with integers too big for the 64-bit integer type by using the bigint type. bigint is not considered a basic type; it is an abbreviation for System.Numerics.BigInteger. You may want to check this: <https://blogs.endjin.com/>

    ```plaintext
    C 20 5
    Result 15504
    ```

    ```fsharp
    let main argv =
        let rec fact x =
            match x with
            | 0 -> bigint 1
            | _ -> bigint x * fact (x - 1)

        let C n k =
            (fact n) / ((fact k) * (fact (n - k)))
        printfn "%A" (C 20 5)
        0 // return an integer exit code
    ```

    ```plaintext
    15504
    ```

3. Vector add

    vecadd adds two integer lists, element by element. Assume the two int lists contain the same number of elements

    ```plaintext
    vecadd [1;2;3] [4;5;6]
    Result list = [5;7;9]

    vecadd [1; 2; -3; 4] [4; -5; 6; 7]
    Result list = [5; -3; 3; 11]
    ```

    ```fsharp
    ```

    ```plaintext
    ```
