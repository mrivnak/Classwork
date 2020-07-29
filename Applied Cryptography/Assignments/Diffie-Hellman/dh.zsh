for ((i = 1; i <= 3; i++)); do
    {
        time (
            openssl dhparam -out alice${i}.pem 2048 > /dev/null
        )
    } 2>> hash_times.txt
    {
        time (
            openssl dhparam -out bob${i}.pem 2048 > /dev/null
        )
    } 2>> hash_times.txt
done

for ((i = 1; i <= 3; i++)); do
    openssl genpkey -paramfile alice${i}.pem -out alice_key${i}.pem
    openssl genpkey -paramfile bob${i}.pem -out bob_key${i}.pem

    openssl genpkey -paramfile alice${i}.pem -text > alice_text${i}.txt
    openssl genpkey -paramfile bob${i}.pem -text > bob_text${i}.txt
    
    openssl pkey -in alice_key${i}.pem -pubout -out alice_pub${i}.pem
    openssl pkey -in bob_key${i}.pem -pubout -out bob_pub${i}.pem
done

for ((i = 1; i <= 3; i++)); do
    {
        time (
            openssl dhparam -out alice_4096_${i}.pem 4096 > /dev/null
        )
    } 2>> hash_times_4096.txt
    {
        time (
            openssl dhparam -out bob_4096_${i}.pem 4096 > /dev/null
        )
    } 2>> hash_times_4096.txt
done