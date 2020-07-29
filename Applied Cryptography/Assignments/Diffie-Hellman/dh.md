# Diffie-Hellman-Merkle

This project will give you insight into the key generation and agreement  processes of the Diffie-Hellman-Merkle algorithms and OpenSSL.

Use OpenSSL version 1.1.1 to generate at least 3 sets of DHKE parameters for Alice and another 3 sets for Bob, using 2048-bit length values. From the parameters, generate the necessary "keys" that would be used for the public and private values.

1. Report each of these parameter sets in the long "-text" output

    ```plaintext
    -----BEGIN DH PARAMETERS-----
    MIIBCAKCAQEAx8Jk0SW/umGR+kvo4G29l+cYs/vJzMaznVk6eR2O1JX93baUc7X+
    BBtxnaoT/J8MZXS3MSYArDGyYEhPv5DmxI1zNNDvq+RJyZWAVBSWdmCUY7JaLIn/
    bMt24u9T7iztSTKfyBEu8+paEi78Xr+RCxGfQoQzGqQfDuOnQw1zljT2kJNIgLfT
    0YDxEsBwpGEJjZAdXXIf2CUO2SO/HC5QrL8KC+6RW0gPQnGptWGAeujqBj3oZ0VY
    d01CKWw0aSOWIIAkUnMm1quShxyMCxKLQOYVBH4UQ0GhdXlALU+OCUdN25ut7hog
    arxrKz6bB3Ag+sF1emr8ZStnI1ARu0FgMwIBAg==
    -----END DH PARAMETERS-----
    ```

2. Take note of the amount of time required to generate each set of parameters and report the range of time needed.

    ```plaintext
    min: 7.376, max: 33.744, mean: 17.264
    ```

3. Compare and contrast the individual parameters for Alice, Bob, and combined.

    ```shell
    diff alice1.pem alice2.pem
    ```

    ```plaintext
    2,7c2,7
    < MIIBCAKCAQEAx8Jk0SW/umGR+kvo4G29l+cYs/vJzMaznVk6eR2O1JX93baUc7X+
    < BBtxnaoT/J8MZXS3MSYArDGyYEhPv5DmxI1zNNDvq+RJyZWAVBSWdmCUY7JaLIn/
    < bMt24u9T7iztSTKfyBEu8+paEi78Xr+RCxGfQoQzGqQfDuOnQw1zljT2kJNIgLfT
    < 0YDxEsBwpGEJjZAdXXIf2CUO2SO/HC5QrL8KC+6RW0gPQnGptWGAeujqBj3oZ0VY
    < d01CKWw0aSOWIIAkUnMm1quShxyMCxKLQOYVBH4UQ0GhdXlALU+OCUdN25ut7hog
    < arxrKz6bB3Ag+sF1emr8ZStnI1ARu0FgMwIBAg==
    ---
    > MIIBCAKCAQEAtDCHnXzVWCgl3H4GYPk+2q+T8+KAK5MpifNB/4+5zuw4vHkVl2R2
    > 2rywmhm8w8xaiZhvBYTJ4CSQYNRHLcWo9rNjR3jqZE2sWOs88jA+5l1EZaRemmjK
    > os78vU0gQeo7I5XF060kSZTASAn7Fk/TW1hV15/mgBTAI79WzWaFtSxdd6s+y24e
    > DWM14L9mhU7kIIgPGws9FcSlbXMGvzRaWekKqbApxOm+fMvB5y9w8liCi2soIHdc
    > As58oZDUACH6ask8tAxSRohUUNL3MVo+Kt2NQqcl+L298ZpqofHmUwGZOukcpRxN
    > UL5JxqoysSgBlRTlaC2i/L2Amu1tkahHWwIBAg==
    ```

    ```shell
    diff alice1.pem bob1.pem
    ```

    ```plaintext
    2,7c2,7
    < MIIBCAKCAQEAx8Jk0SW/umGR+kvo4G29l+cYs/vJzMaznVk6eR2O1JX93baUc7X+
    < BBtxnaoT/J8MZXS3MSYArDGyYEhPv5DmxI1zNNDvq+RJyZWAVBSWdmCUY7JaLIn/
    < bMt24u9T7iztSTKfyBEu8+paEi78Xr+RCxGfQoQzGqQfDuOnQw1zljT2kJNIgLfT
    < 0YDxEsBwpGEJjZAdXXIf2CUO2SO/HC5QrL8KC+6RW0gPQnGptWGAeujqBj3oZ0VY
    < d01CKWw0aSOWIIAkUnMm1quShxyMCxKLQOYVBH4UQ0GhdXlALU+OCUdN25ut7hog
    < arxrKz6bB3Ag+sF1emr8ZStnI1ARu0FgMwIBAg==
    ---
    > MIIBCAKCAQEAjVEB4kVfZi+qYz+cj1ib9e9Uz0AJD03YDah+MKnsFCPQCQ6YfYpg
    > JifLNewHU3tyE1ll7HOR6NBmhZ9MdYZyb0aARiSMbZ4IALUm+R8umuq/ZwoOlVVs
    > WBqxGD3kYWGgNBGMhGEfjEb98nceYrJKjgf4f3skAGU6vNfzrUZXxmSV9HKdIJJ4
    > Ez+7mVDTBXZt/vHujO555zMl47Ibw9W0TOEd7HAQGvrbNineRQY0/MUfY0AtMEwg
    > mhV2MtRZWUVsQBVr/SiqB52RaDNK4BZP7EiBJTumqFIyMZ2AHfnNbFKrWH5Tl8e8
    > KyZ/483CYxKeXEiL+qzHVA7eXGYLTj4z6wIBAg==
    ```

    Interestingly, the first 12 characters of the parameters are the same between the different parameters

4. If Perfect Forward Secrecy is to be maintained, how many sessions can be established between Alice and Bob with these sets of parameters?

    For perfect forward secrecy, Alice and Bob must use a unique parameter value for each session and they may not be reused. This ensures that if a secret is compromised, all other sessions are still secure.

5. Generate a DHKE parameter set for Alice and Bob using 4096-bit values. Compare this to the time required for 2048-bit values. Why doesn't this difference in time seem to be just double the amount of time for the 2048-bit values?

    ```plaintext
    min: 166.065, max: 670.993, mean: 465.413
    ```
