#!/usr/bin/zsh

openssl enc -aes-256-cbc -e -nosalt -K 8000000000000000000000000000000000000000000000000000000000000001 -iv 0 -in message.txt -out message.txt.aes-256-cbc

openssl dgst -sha256 -mac hmac -macopt key:0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b message.txt > message.txt.sha256-hmac

openssl dgst -sha3-512 -mac hmac -macopt key:b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0 message.txt > message.txt.sha3-512-hmac