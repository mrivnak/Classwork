#!/usr/bin/zsh

echo "Creating output directory..."

mkdir hashes_output >> /dev/null

echo "Cleaning previous data..."

rm hash_times.txt hashes_output/* >> /dev/null

echo "\nCalculating hashes..."

hash_names=('BLAKE2b512' 'MD5' 'SHA1' 'RIPEMD-160' 'SHA224' 'SHA256' 'SHA384' 'SHA512' 'SHA3-224' 'SHA3-256' 'SHA3-384' 'SHA3-512' 'SHAKE128' 'SHAKE256')
hash_filenames=('blake2b512' 'md5' 'sha1' 'ripemd160' 'sha224' 'sha256' 'sha384' 'sha512' 'sha3-224' 'sha3-256' 'sha3-384' 'sha3-512' 'shake128' 'shake256')

TIMEFMT=$'\nreal\t%*E\nuser\t%*U\nsys\t\t%*S\n'

for ((i = 1; i <= ${#hash_names[@]}; i++)); do
    echo "[$i/${#hash_names[@]}] ${hash_names[$i]}..."
    echo "${hash_names[$i]}:" >> hash_times.txt
    {
        time (
            for ((j = 0; j < 1000; j++)); do
                openssl ${hash_filenames[$i]} data.txt >> ./hashes_output/${hash_filenames[$i]}
            done
        )
    } 2>> hash_times.txt
done

echo "\nValidating hashes..."

for ((i = 1; i <= ${#hash_names[@]}; i++)); do
    echo "[$i/${#hash_names[@]}] ${hash_names[$i]}..."
    awk '!unique[$0]++ { count++ } END { print count == 1 ? "Passed!" : "Failed! :("  }' ./hashes_output/${hash_filenames[$i]}
done