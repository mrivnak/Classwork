# Evaluating Hash Algorithms

There are many different viable hashing algorithms available today. They provide a variety of hash lengths and varying resistance to collisions and other attacks. They also have different performance based on a variety of factors. This project will have you evaluate the timing, reliability, and general performance of the following hash functions in OpenSSL:

* BLAKE2b512
* MD5
* SHA1
* RIPEMD-160
* SHA224
* SHA256
* SHA384
* SHA512
* SHA3-224
* SHA3-256
* SHA3-384
* SHA3-512
* SHAKE128
* SHAKE256

For each of the specified hash algorithms, use OpenSSL to hash the attached file 1000 times and output each iteration to a file. You can automate this with a script that looks something like:

```shell
for i in {0..999} 
    do
    openssl blake2b512 data.txt >> hashblake2-512
done
```

You should document the timing required to execute each collection of hashes and writing them to file. This will allow you to compare and contrast the timing performance of each algorithm against an identical input. Graph the performance of each hash algorithm.

To check the reliability of each hashing algorithm, you should verify that each of the 1000 hashes in each output are 100% identical. If there is one or more unique instances of a hash in the file, it should be noted and the test should be re-run. Document the unique instance of the hash as well.

Finally, you should compare and contrast the results of the different hashing algorithms and their results, with specific commentary on your expectations of performance and reliability.

Ensure that the file that you download is not flawed or corrupted by matching the following hash value (which hashing function was used? HINT: how long is the hash value?):

318f40f7f9e42a8b4ecda1dd1b1a039a2abd7bc7c91dd00967b5b4ddbb96a633809afb827b849d6d9202d17a1a7fc56e5f0a0413c20247bb1816101d919f2764
