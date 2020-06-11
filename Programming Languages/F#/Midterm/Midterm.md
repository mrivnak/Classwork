# Midterm Part 2

1. You are fiven a simple sorting program in C. Convert this program to use F#. The data is in an array which is a mutable structure. You must use F# constructs.

    C Program:

    ```c
    int data[] = {6, 92, 3, 7, 6, 77, 13, 9, 11, 46, 19, 24, 30, 55, 4};

    void swap(int i, int j, int *arr) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    int main() {
        int len = sizeof(data) / sizeof(int);

        // Print unsorted data
        for (int i = 0; i < len; i++)
            printf("%d ", data[i]);

        printf("\n");
        for (int i = len - 1; i >=0; i--)
            for (int j = 1; j <= i; j++)
                if (data[j-1] > data[j])
                    swap((j-1, j, data))

        // Print sorted data
        for (int i = 0; i < len; i++)
            printf("%d ", data[i]);

        return 0;
    }
    ```

    F# Program:

    ```fsharp
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
    ```

    Output:

    ```plaintext
    Unsorted array: [|6; 92; 3; 7; 6; 77; 13; 9; 11; 46; 19; 24; 30; 55; 4|]
    Sorted array: [|3; 4; 6; 6; 7; 9; 11; 13; 19; 24; 30; 46; 55; 77; 92|]
    ```
    